@echo off
rem Copyright 2021-2022 hpmicro
rem SPDX-License-Identifier: BSD-3-Clause

setlocal enabledelayedexpansion

set PROG_NAME=%~n0
set FORCE=0
set LIST_ALL=0
set SPECIFIC_BOARD=
set SPECIFIC_BOARD_PATH=
set GENERATE_ALL=0
set BUILD_TYPE=debug
set SUPPORTED_BUILD_TYPES=release debug flash_xip flash_xip_release flash_sdram_xip flash_sdram_xip_release flash_uf2 flash_uf2_release flash_sdram_uf2 flash_sdram_uf2_release sec_core_img sec_core_img_release

if "%HPM_SDK_BASE%"=="" (
    echo HPM_SDK_BASE needs to be defined first, pointing to the root directory of HPM_SDK
    goto ERROR
)


:LOOP
if NOT "%1"=="" (
    if "%1"=="-f" (
        set FORCE=1
    )
    if "%1"=="-b" (
        set SPECIFIC_BOARD=%2
    )
    if "%1"=="-x" (
        set SPECIFIC_BOARD_PATH=%2
    )
    if "%1"=="-l" (
        set LIST_ALL=1
    )
    if "%1"=="-list" (
        set LIST_ALL=1
    )
    if "%1"=="-a" (
        set GENERATE_ALL=1
    )
    if "%1"=="-t" (
        if "%2"=="" (
            echo error: missing build type after -t
            echo.
            goto USAGE
        )
        set BUILD_TYPE=%2
    )
    if "%1"=="-h" (
        goto USAGE
    )
    shift
    goto LOOP
)

if "%LIST_ALL%"=="1" (
    call :LIST_ALL_BOARDS
    goto EXIT
)

if not "%BUILD_TYPE%"=="" (
    for %%t IN (%SUPPORTED_BUILD_TYPES%) DO (
        if "%%t"=="%BUILD_TYPE%" (
            goto BUILD_TYPE_FOUND
        )
    )
) else (
    goto BUILD_TYPE_FOUND
)

:BUILD_TYPE_NOT_FOUND
    echo  error: unsupported build type %BUILD_TYPE%
    echo  Here're supported build types:
    call :LIST_SUPPORTED_BUILD_TYPES
    goto ERROR

:BUILD_TYPE_FOUND

if "%GENERATE_ALL%"=="1" (
    if not exist CMakeLists.txt (
        goto NOT_IN_SAMPLE_DIR
    )
    for /D %%B in ("%HPM_SDK_BASE%\boards\*") DO (
        set board=%%~nB
        if exist "%%B\CMakeLists.txt" (
            call :GEN_PROJECT_FOR_BOARD !board: =! !BUILD_TYPE!
        )
    )
    goto EXIT
)

if not "%SPECIFIC_BOARD%"=="" (
    set BRD_PATH=
    if not "%SPECIFIC_BOARD_PATH%"=="" (
        if exist "%SPECIFIC_BOARD_PATH%\%SPECIFIC_BOARD%\CMakeLists.txt" (
            set BRD_PATH=%SPECIFIC_BOARD_PATH%\%SPECIFIC_BOARD%
        )
    ) else (
        if exist "%HPM_SDK_BASE%\boards\%SPECIFIC_BOARD%\CMakeLists.txt" (
            set BRD_PATH=%HPM_SDK_BASE%\boards\%SPECIFIC_BOARD%
        )
    )
    if exist "!BRD_PATH!\CMakeLists.txt" (
        call :GEN_PROJECT_FOR_BOARD %SPECIFIC_BOARD% !BUILD_TYPE! %SPECIFIC_BOARD_PATH%
        goto EXIT
    ) else (
        echo %SPECIFIC_BOARD% can not be found, please make sure it is a valid board.
        goto ERROR
    )
)

echo error: no board specified
echo.

goto USAGE

:GEN_PROJECT_FOR_BOARD
set b=%~1
set t=%~2
set x=%~3
set build_dir=%b%_build

if exist CMakeLists.txt (
    if exist %build_dir% (
        if "%FORCE%"=="1" (
            rd /q /s %build_dir%
        ) else (
            echo %build_dir% directory exists, please remove it manually or run this script with -f option
            goto ERROR
        )
    )
    md %build_dir%
    cd %build_dir%
    if "%x%"=="" (
        cmake --fresh -GNinja -DBOARD=%b% -DCMAKE_BUILD_TYPE=%t% ..
    ) else (
        cmake --fresh -GNinja -DBOARD=%b% -DCMAKE_BUILD_TYPE=%t% -DBOARD_SEARCH_PATH=%x% ..
    )
    cd ..
) else (
    goto NOT_IN_SAMPLE_DIR
)
exit /b 0

:LIST_ALL_BOARDS
set BRD_PATH=
if not "%SPECIFIC_BOARD_PATH%"=="" (
    set BRD_PATH=%SPECIFIC_BOARD_PATH%
) else (
    set BRD_PATH=%HPM_SDK_BASE%\boards
)

for /D %%B in ("%BRD_PATH%\*") DO (
    set brd=%%~nB
    if exist "%%B\CMakeLists.txt" (
        echo !brd!
    )
)


exit /b 0

:LIST_SUPPORTED_BUILD_TYPES
for %%t in (%SUPPORTED_BUILD_TYPES%) DO (
    echo    -  %%t
)
exit /b 0

:USAGE
echo %PROG_NAME% [-f] [-b board] [-x board_search_path] [-a] [-list] [-h]
echo   -f: force clean already existed build directory
echo   -b board: specify board for project generation
echo   -x board_search_path: specify board search path for project generation
echo   -a: generate projects for all supported boards
echo   -list: list all supported boards
echo   -t type: specify build type
echo   -h: show this text
echo.
echo  Here're supported build types:
call :LIST_SUPPORTED_BUILD_TYPES
goto EXIT


:NOT_IN_SAMPLE_DIR
echo no CMakeLists.txt is found at %~dp0, please change diretory to certain sample directory under %HPM_SDK_BASE%\samples\

:ERROR
exit /b 1

:EXIT
endlocal
