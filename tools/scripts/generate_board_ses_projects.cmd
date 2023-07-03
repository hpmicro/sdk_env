@echo off
rem Copyright 2022 hpmicro
rem SPDX-License-Identifier: BSD-3-Clause
rem This script will be called by generate_ses.cmd to produce segger project
setlocal enabledelayedexpansion
if "%~3"=="" (
    echo Please input start_cmd.cmd path
    pause
    goto EXIT
)
SET START_CMD_PATH=%~3
if exist "%START_CMD_PATH%start_cmd.cmd" (
    call %START_CMD_PATH%start_cmd.cmd true
) else (
    echo "start_cmd.cmd can not be found"
    pause
    goto EXIT
)

if "%HPM_SDK_BASE%"=="" (
    echo HPM_SDK_BASE needs to be defined first, pointing to the root directory of HPM_SDK
    pause
    goto EXIT
)
set BUILD_TYPE=flash_sdram_xip
set ALL_BUILD_TYPE=debug;release;flash_xip;flash_xip_release;flash_sdram_xip;flash_sdram_xip_release;sec_core_img;sec_core_img_release;flash_uf2

echo.
echo.
echo compile %1 segger project, this process maybe need several minutes, please wait...
echo.
echo.

if "%~1"=="" (
    echo Please input board Name
    pause
    goto EXIT
)
if "%~2"=="" (
    echo Please input compile dir
    pause
    goto EXIT
)

if not exist "%HPM_SDK_BASE%\boards\%~1\CMakeLists.txt" (
    echo Invalid board Name
    pause
    goto EXIT
)

if not exist "%~2" (
    echo Compile path does not exist
    pause
    goto EXIT
)
call :BUILD_ALL_EXAMPLES %~1 %~2
goto EXIT

rem calculate str's length
:STR_LEN STR STR_LEN
setlocal
set STR_TMP=%1
set STR_LEN=0
:NEXT_1
if not "%STR_TMP%"=="" (
    set /a STR_LEN+=1
    set STR_TMP=%STR_TMP:~1%
    goto NEXT_1
)
endlocal&set %2=%STR_LEN%
exit /b 0

:: find str1 in str2's first position
:STR_STR STR1 STR2 POSITION
setlocal
set STR2=%2
set POSITION=0
call :STR_LEN %1 STR_LEN
:STR_STR_NEXT
if not "%STR2%"=="" (
    set /a POSITION+=1
    if "!STR2:~%postion%,%STR_LEN%!"=="%1" (
        goto STR_STR_EXIT
    )
    set STR2=%STR2:~1%
    goto STR_STR_NEXT
)
set POSITION=0
:STR_STR_EXIT
endlocal&set %3=%POSITION%
goto :eof

:FIND_AVAILABLE_TYPE_AND_COMPILE ERROR_INFO BOARD_NAME BUILD_TYPE SAMPLE_DIR ERROR_IN_FLAG
setlocal
set ERROR_INFO=%1
type build.log | findstr /c:%ERROR_INFO% >nul 2>&1
if !ERRORLEVEL!==0 (
    set ERROR_IN_FLAG=1
    cd ..
    if exist "!cd!\%3" (
        rd /q /s !cd!\%3
    )
    for %%t in (%ALL_BUILD_TYPE%) do (
        if not "%3"=="%%t" (
            if exist "%%t" (
                rd /q /s %%t
            )
            md %%t
            cd %%t
            cmake -GNinja -DBOARD=%2 -DCMAKE_BUILD_TYPE=%%t %4 >build.log 2>&1
            if !ERRORLEVEL!==0 (
                goto FIND_AVAILABLE_TYPE_AND_COMPILE_EXIT
            ) else (
                cd ..
                if exist "%%t" (
                    rd /q /s %%t
                )
            )
        )
    )
)
set ERROR_IN_FLAG=0
:FIND_AVAILABLE_TYPE_AND_COMPILE_EXIT
endlocal&set %5=%ERROR_IN_FLAG%
exit /b 0


:EXAMPLE_COMPILE BOARD_NAME BUILD_TYPE SAMPLE_DIR
cmake -GNinja -DBOARD=%1  -DCMAKE_BUILD_TYPE=%2 %3 >build.log 2>&1
if not %ERRORLEVEL%==0 (
    type build.log | findstr /c:"can not support this sample" >nul 2>&1
    if !ERRORLEVEL!==0 (
        rem board does not support
        cd ..
        if exist "!cd!\%2" (
            rd /q /s !cd!\%2
        )
        goto EXAMPLE_COMPILE_EXIT
    )
    call :FIND_AVAILABLE_TYPE_AND_COMPILE "has been excluded for this example" %1 %2 %3 INFO_IN_FLAG
    if "!INFO_IN_FLAG!"=="0" (
        call :FIND_AVAILABLE_TYPE_AND_COMPILE "is not supported" %1 %2 %3 INFO_IN_FLAG
    )
    
)
:EXAMPLE_COMPILE_EXIT
exit /b 0

:EXAMPLE_COMPILE_FOR_MULTICORE BOARD_NAME SAMPLE_DIR
call :STR_STR core0 %2 POSITION_CORE0
if not "!POSITION_CORE0!"=="0" (
    cmake -GNinja -DBOARD=%1  %2 >build.log 2>&1
) else (
    cmake -GNinja -DBOARD=%1 -DCMAKE_BUILD_TYPE="sec_core_img" %2 >build.log 2>&1
)
exit /b 0

:BUILD_ALL_EXAMPLES
call :STR_LEN samples STR_LEN
set /a POSITION=0
for /R %HPM_SDK_BASE%\samples\ %%B in (*CMakeLists.txt) DO (
    set EXAMPLE_DIR=%%~pB
    if !POSITION!==0 (
        call :STR_STR samples !EXAMPLE_DIR! POSITION
        set /a POSITION=!POSITION!+!STR_LEN! 
    )
    for %%x in (!POSITION!) do set DIR_TMP=!EXAMPLE_DIR:~%%x,-1!
    call :STR_STR multicore !DIR_TMP! POSITION_MULTICORE
    if not "!POSITION_MULTICORE!"=="0" (
        echo.
    ) else (
        set EXAMPLE_PATH=%HPM_SDK_BASE%\samples\!DIR_TMP!\
        for %%t in (%BUILD_TYPE%) do (
            set BUILD_DIR=%2\!DIR_TMP!\%%t 
            if exist "!BUILD_DIR!" (
                rd /q /s !BUILD_DIR!
            )
            md !BUILD_DIR!
            cd !BUILD_DIR!
            call :EXAMPLE_COMPILE %1 %%t !EXAMPLE_PATH!
        ) 
    )
)
echo generate ses project for multicore
for /R %HPM_SDK_BASE%\samples\multicore %%B in (*CMakeLists.txt) DO (
    set EXAMPLE_DIR=%%~pB
    for %%x in (!POSITION!) do set DIR_TMP=!EXAMPLE_DIR:~%%x,-1!
    set EXAMPLE_PATH=%HPM_SDK_BASE%\samples\!DIR_TMP!\
    set BUILD_DIR=%2\!DIR_TMP!\
    if exist "!BUILD_DIR!" (
        rd /q /s !BUILD_DIR!
    )
    md !BUILD_DIR!
    cd !BUILD_DIR!
    call :EXAMPLE_COMPILE_FOR_MULTICORE %1 !EXAMPLE_PATH!
)
exit /b 0

:EXIT
endlocal
exit
