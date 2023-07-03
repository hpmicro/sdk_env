@echo off
rem Copyright 2022 hpmicro
rem SPDX-License-Identifier: BSD-3-Clause
rem This script can produce segger project under samples_ses_project dir
setlocal enabledelayedexpansion

@rem Please modify the following variable
set VBSCRIPT=Msgbox("Do you want to generate segger project?"+vbcrlf+"This process will cost several minutes." +vbcrlf +"If you choose ok"+vbcrlf +"(1) If LongPathsEnabled registry is not enabled, one cmd window will run"+vbcrlf + ^
"    You can close it after LongPathsEnabled is set"+vbcrlf +"(2) More cmd windows will run to generate segger projects"+vbcrlf +"   Please don't close them",1,"Warning")
for /f "Delims=" %%a in ('MsHta VBScript:Execute("CreateObject(""Scripting.Filesystemobject"").GetStandardStream(1).Write(%VBSCRIPT:"=""%)"^)(Close^)') do Set "MSHTA_RETURN_VALUE=%%a"
if not %MSHTA_RETURN_VALUE% == 1 (
    goto EXIT
)
cd %~dp0
if exist "start_cmd.cmd" (
    call start_cmd.cmd true 
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
set LONG_PATH_VALUE=0
:CHECK_LONG_PATH
FOR /F "usebackq skip=2 tokens=1-2*" %%A IN (`REG QUERY HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v LongPathsEnabled 2^>nul`) DO (
    set LONG_PATH_VALUE=%%C
)
if not '%LONG_PATH_VALUE%' EQU '0x1' (
    goto CHECK_LONG_PATH
)
set HPM_PROJECT_BASE=%~dp0
set SES_PROJ=%HPM_PROJECT_BASE%samples_ses_project
if exist "%SES_PROJ%" (
    rd /q /s %SES_PROJ%
)
md %SES_PROJ%
cd %SES_PROJ%
for /D %%B in ("%HPM_SDK_BASE%\boards\*") DO (
    set BOARD=%%~nB
    if exist "%%B\CMakeLists.txt" (
        echo %SES_PROJ%\!BOARD!
        if exist "%SES_PROJ%\!BOARD!" (
            rd /q /s %SES_PROJ%\!BOARD!
        )
        md %SES_PROJ%\!BOARD!
        cd %SES_PROJ%\!BOARD!
        start /i "Compile !BOARD! seggger project" /MIN  /realtime   %HPM_PROJECT_BASE%tools\scripts\generate_board_ses_projects.cmd !BOARD! %SES_PROJ%\!BOARD! %HPM_PROJECT_BASE%
    )
)
goto EXIT
:EXIT
endlocal