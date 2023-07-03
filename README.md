# HPM SDK Development Environment for Windows

## Quick Start Guide
1. Install FT2232 driver.
![Install driver](doc/img/ftdi_install.png)
1. Open `start_cmd.cmd` to start a windows command prompt for HPM SDK development, it will configure all needed environment variables (only effective in this windows command prompt, not changing any in current system globally). So all the following operations need to be executed in this window command prompt opened by `start_cmd.cmd`. This windows command prompt will be refered as **sdk prompt**
1. The script will generate all examples' segger project of all vailable boards under folder  samples_ses_project by clicking `generate_all_ses_projects.cmd`.
1. 
## Folder structure:
- hpm_sdk: sdk root directory in which sdk zip package should be unzip to, please make sure the folder of "cmake" can be found via path hpm_sdk\cmake
- toolchains: toolchain should be put in this folder. For example, copy toolchain files to toolchains folder, then riscv32-elf-\*-gcc.exe must be found at toolchains\TOOLCHAIN_NAME\bin
  - Note:
    - TOOLCHAIN_NAME needs to be configured correctly in start_cmd.cmd
- tools:
  - ninja
  - cmake
  - python3
  - openocd
  - scripts
  - FTDI_InstallDriver.exe: FT2232 windows driver installer
- doc: documentation

## FAQ
### Can't find FTDI debug probe
  - Make sure install driver (FTDI_InstallDriver.exe) correctly. Please be aware it might need to be installed again if the debug usb cable is pluged to another USB port on PC.
### Segger Embedded Studio fails to debug
  Please try to following options
  - Reopen Segger Embedded Studio, and try to debug again
  - Close Segger Embedded Sutdio, then kill the process of "openocd" in Window task manager, reopen Segger Embedded Studio and try to debug again.
  - Set boot mode to "ISP" or "Serial Download Mode" on evaluation board, then press reset button the board, try to debug again.
### Issue caused by Windows 10 path limit
  To enable long path support, please import registry file located at tools/scripts/win10_enable_long_path.reg. For more details about this limitation, please refer to https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=cmd
  
