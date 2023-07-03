@echo off
rem Copyright 2022 hpmicro
rem SPDX-License-Identifier: BSD-3-Clause
if not "%~1"=="true" (
    setlocal enabledelayedexpansion
)
set SDK_ENV=%~1
set HPM_SDK_BASE=%~1\hpm_sdk
echo SDK_ENV %SDK_ENV%
echo HPM_SDK_BASE %HPM_SDK_BASE%
pushd %SDK_ENV%
 
rem check if long path support has been enabled or not
set value=0
FOR /F "usebackq skip=2 tokens=1-2*" %%A IN (`REG QUERY HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled 2^>nul`) DO (
    set value=%%C
)
if '%value%' NEQ '0x1' (
    rem "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"
    >nul 2>&1 rd /q /s "%WinDir%\System32\hpmicro_test_permissions"
    >nul 2>&1 md "%WinDir%\System32\hpmicro_test_permissions"
    if '!errorlevel!' NEQ '0' (
        call :UACPrompt
        echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        echo ^|     HPMicro SDK Env Tool    ^|
        echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        echo.
        echo - WARNING: long path support has not been enabled yet
        echo.
    ) else (
        >nul 2>&1 rd /q /s "%WinDir%\System32\hpmicro_test_permissions"
        if exist "%temp%\getadmin.vbs" (
            echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            echo ^|     HPMicro SDK Env Tool: Enabling long path support    ^|
            echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            echo.
            goto gotAdmin
        ) else (
            echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            echo ^|     HPMicro SDK Env Tool    ^|
            echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            echo.
            echo - WARNING: long path support has not been enabled yet
            echo.
            >nul 2>&1 REG ADD HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled /t REG_DWORD /d 1 /f
            echo - INFO: Long path support has been enabled
            set LONG_PATH_ENABLED=true
            rem pushd %~dp0
        )
    )
) else (
    echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    echo ^|     HPMicro SDK Env Tool    ^|
    echo +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    echo.
    echo - INFO: Long path support has been enabled
    set LONG_PATH_ENABLED=true
    @REM pushd %~dp0
)

if not exist "%APPDATA%\OpenOCD" (
    md "%APPDATA%\OpenOCD"
)

if exist %HPM_SDK_BASE%\boards\openocd (
    xcopy /S /Q /Y %HPM_SDK_BASE%\boards\openocd "%APPDATA%\OpenOCD\" > nul 2>&1
    if ERRORLEVEL 1 (
        echo - WARNING: openocd config file failed to be copied to %APPDATA% from %HPM_SDK_BASE%\boards\openocd
    ) else (
        echo - INFO: openocd config file has been copied to %APPDATA% from %HPM_SDK_BASE%\boards\openocd
    )
)
if exist tools\openocd\tcl (
    xcopy /S /Q /Y tools\openocd\tcl "%APPDATA%\OpenOCD\" > nul 2>&1
    if ERRORLEVEL 1 (
        echo - WARNING: openocd config file failed to be copied to %APPDATA% from tools\openocd\tcl
    ) else (
        echo - INFO: openocd config file copied to %APPDATA% from tools\openocd\tcl
    )
)
if exist tools\openocd\scripts (
    xcopy /S /Q /Y tools\openocd\scripts "%APPDATA%\OpenOCD\" > nul 2>&1
    if ERRORLEVEL 1 (
        echo - WARNING: openocd config file failed to be copied to %APPDATA% from tools\openocd\scripts
    ) else (
        echo - INFO: openocd config file has been copied to %APPDATA% from tools\openocd\scripts
    )
)
set value=0
FOR /F "usebackq skip=2 tokens=1-2*" %%A IN (`REG QUERY HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled 2^>nul`) DO (
    set value=%%C
)
if '%value%' EQU '0x1' (
    if "%LONG_PATH_ENABLED%"=="false" (
        echo - INFO: Long path support has been enabled
    )
)

goto DONE

:gotAdmin
    if exist "%temp%\getadmin.vbs" ( del "%temp%\getadmin.vbs" )
    >nul 2>&1 REG ADD HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled /t REG_DWORD /d 1 /f
    echo - INFO: Long path support has been enabled, press any key to close this window
    pause
    exit

:UACPrompt
echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
echo UAC.ShellExecute "cmd.exe", "/c %~s0 %~1", "", "runas", 1 >> "%temp%\getadmin.vbs"

"%temp%\getadmin.vbs"
rem del "%temp%\getadmin.vbs"
exit /b 0

:CYGWIN_PATH_WARNING
echo.
echo WARNING: Currently, Andes toolchain is specified, please make sure cygwin path is appended to current PATH environment variable of current console

:DONE
echo.
popd
