@echo off
rem Copyright 2021-2022 hpmicro
rem SPDX-License-Identifier: BSD-3-Clause

setlocal enabledelayedexpansion

set PROG_NAME=%~n0
set SPECIFIC_BOARD=
set ELF_FILE=
set BIN_FILE=
set FLASH_ADDRESS=
set FORCE_TO_RUN=0

if "%HPM_SDK_BASE%"=="" (
    echo HPM_SDK_BASE needs to be defined first, pointing to the root directory of HPM_SDK
    goto EXIT
)


:LOOP
if NOT "%1"=="" (
    if "%1"=="-b" (
        set SPECIFIC_BOARD=%2
    )
    if "%1"=="-elf" (
        if "%2"=="" (
            echo error: missing elf file
            echo.
            goto USAGE
        )
        set ELF_FILE=%2
    )
    if "%1"=="-bin" (
        if "%2"=="" (
            echo error: missing bin file
            echo.
            goto USAGE
        )
        set BIN_FILE=%2
        if "%3"=="" (
            echo error: no flash address is given
            echo.
            goto USAGE
        )
        set FLASH_ADDRESS=%3
    )
    if "%1"=="-f" (
        set FORCE_TO_RUN=1
    )

    if "%1"=="-h" (
        goto USAGE
    )
    shift
    goto LOOP
)

if "%ELF_FILE%"=="" (
    if "%BIN_FILE%"=="" (
        echo error: elf or bin file should be specified.
        goto USAGE
    )
)

if not "%ELF_FILE%"=="" (
    if not "%BIN_FILE%"=="" (
        echo error: elf and bin file are both given, please make sure only one file is given
        goto USAGE
    )
)

if not exist "%HPM_SDK_BASE%\boards\%SPECIFIC_BOARD%\%SPECIFIC_BOARD%.yaml" (
    CALL :LIST_ALL_BOARDS
    goto EXIT
) else (
    for /F "tokens=2 delims= " %%a in ('findstr /I "openocd-probe:" %HPM_SDK_BASE%\boards\%SPECIFIC_BOARD%\%SPECIFIC_BOARD%.yaml') do set OCD_PROBE=%%a.cfg
    for /F "tokens=2 delims= " %%a in ('findstr /I "openocd-soc:" %HPM_SDK_BASE%\boards\%SPECIFIC_BOARD%\%SPECIFIC_BOARD%.yaml') do set OCD_SOC=%%a.cfg
    rem use single core config file for programming
    set OCD_SOC=!OCD_SOC:dual=single!
)

if not exist "%APPDATA%\OpenOCD\probes\%OCD_PROBE%" (
    echo "%APPDATA%\OpenOCD\probes\%OCD_PROBE%" does not exist
    goto EXIT
)

if not exist "%APPDATA%\OpenOCD\soc\%OCD_SOC%" (
    echo "%APPDATA%\OpenOCD\soc\%OCD_SOC%" does not exist
    goto EXIT
)

set OCD_CFG=-f probes\%OCD_PROBE% -f soc\%OCD_SOC% -f boards\%SPECIFIC_BOARD%.cfg

set OCD_CMD=
if not "%ELF_FILE%"=="" (
    if exist "%ELF_FILE%" (
        set "NORMALIZED_FILE_NAME=%ELF_FILE:\=/%"
        set OCD_CMD=program \"!NORMALIZED_FILE_NAME!\" verify reset exit
    ) else (
        echo error: %ELF_FILE% can not be found
    )
)

if not "%BIN_FILE%"=="" (
    if exist "%BIN_FILE%" (
        set "NORMALIZED_FILE_NAME=%BIN_FILE:\=/%"
        set OCD_CMD=program \"!NORMALIZED_FILE_NAME!\" verify reset exit %FLASH_ADDRESS%
    ) else (
        echo error: %BIN_FILE% can not be found
    )
)

if not "%OCD_CMD%"=="" (
    echo openocd %OCD_CFG% -c "%OCD_CMD%"
    openocd %OCD_CFG% -c "%OCD_CMD%"
) else (
    if "%FORCE_TO_RUN%"=="1" (
        echo start openocd gdbserver only
        openocd %OCD_CFG%
    )
)

goto EXIT

:LIST_ALL_BOARDS
for /D %%B in ("%HPM_SDK_BASE%\boards\*") DO (
    set brd=%%~nB
    if exist "%%B\CMakeLists.txt" (
        echo !brd!
    )
)

exit /b 0

:USAGE
echo %PROG_NAME% [-b board] [-elf elf_file] [-bin bin_file address] [-h] [-f]
echo   -b board: specify board for project generation
echo   -elf elf_file: program elf file to flash
echo   -bin bin_file address: program bin file to flash at given flash address
echo   -f: force to run even if elf or bin file does not exist, instead it will start openocd
echo   -h: show this text
echo   Note: -elf and -bin can't be specified at the same time
goto EXIT

:EXIT
exit /b 0
endlocal
