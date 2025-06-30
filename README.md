# HPM SDK Development Environment for Windows

## Quick Start Guide
1. Install FT2232 driver.
![Install driver](doc/img/ftdi_install.png)
1. Open `start_cmd.cmd` to start a windows command prompt for HPM SDK development, it will configure all needed environment variables (only effective in this windows command prompt, not changing any in current system globally). So all the following operations need to be executed in this window command prompt opened by `start_cmd.cmd`. This windows command prompt will be refered as **sdk prompt**
1. The script will generate all examples' segger project of all vailable boards under folder  samples_ses_project by clicking `generate_all_ses_projects.cmd`.

## start_gui quick start
`start_gui.exe` is a visual tool which is used to generate project by `hpm_sdk`. User can not only generate sample in `hpm_sdk`, but also generate private application by custom board and app directory. The whole GUI of `start_gui.exe` is shown as below:

![start_gui](doc/img/start_gui.png)

The menu bar supports setting both English and Chinese languages and provides access to the current user guide. For the convenience of users to view and use `hpm_sdk`, the tool is equipped with three built-in quick access points to the `hpm_sdk` documentation, represented by three light purple circular buttons as shown in the above image. The help button next to `SDK ENV` opens the homepage of the current `hpm_sdk` help documentation. The help button to the right of the `SDK Boards` dropdown directly opens the documentation for the development board that is currently selected. Similarly, the help button beside the `SDK Samples` dropdown instantly opens the documentation for the chosen sample. You may select and open the corresponding document as per your needs.

- The tool is split to different sections according by different background color:

1. SDK ENV configuration: You can set SDK ENV path manually. After clicking `Advanced` button, you can set the details of `hpm_sdk` path and `CMake、Ninja` path and so on.

2. Board configuration: the tool will list all the boards in `hpm_sdk/boards` by default. You can click the help button located on the right side of the dropdown box to open the local documentation for the currently selected board. And it also supports loading custom board configuration. You need to select `Enable User Board Path` at first and then `User Board` search fuction will be enabled. Then, you need to select a board folder which is used to be searched. And the tool will search `current folder` and `the first level subfolders`. When `CMakeLists.txt and the yaml file whose name is the folders'` are found in the folder, the folder will be recongized as the board configuration and added to list. What's more, if the current folder is recongnized as the board configuration, the tool will not search its subfolders.

    **Note: If custom board is used, the cfg file whose name is as same as the board will be searched as openocd board config file automatically in CMake generating process. If the file is not found, openocd will not add any board config file.**

3. Sample configuration: After selecting a board, the tool will filter samples by the yaml configuration and display the sample list by default. You can click the help button located on the right side of the dropdown box to open the local documentation for the current sample. For dual-core programs, the sample list hides the core1 project by default. If users want to display the core1 project, they only need to click the checkbox on the right to configure it. The tool also supports loading custom sample configuration. You need to select `Enable User Application Path` at first and then `User Applications` will be enabled. Then you need to select a sample which you want to search. The tool wiil search `current folder and all of the subfolders`. When `CMakeLists.txt` is found, the tool will search whether `hpm-sdk` is invoked and add the sample to the list. After selecting a sample, the tool will find all the hpm build types and cmake build types supported by the sample and add them to the list. When `Enable User GCC Linker File` is not selected and switching the hpm build type, the linker script for the hpm build type will be added to the input box automatically. If the option is selected, you need to add the required linker script manually.

4. Output configuration: You can custom the generation path in output section. The tool will use `${sample}/${board}_${build_type}` as the generation path by default. What's more, the tool supports parent directory which you can generate different projects in. You need to select `Use Same Parent Directory` at first and then select a parent directory. After that, all the projects will be generated to the parent directory. `Build Folder` is the project folder whose name will be generated as `${sample}_${board}_${build_type}` automatically. You can also change the folder name manually. On the right side of the `Build Path` input box, there are buttons to open the "Build Path" console and resource explorer. The opened console by default loads the environment variables of `SDK_ENV`,  which allow user to compile project under the "Build Path" directory and run commands directly.

5. Generate options: After configuration, you can use `Generate` to generate project. When the project is generated success, `Open with IDE` will be highlighted and can be clicked to open the IDE which it can be switched by right arrow button. `Compile` button is supported to compile the project directly. Taking into account various user needs for `hpm_sdk`, the tool also supports extracting the `hpm_sdk` files used by the current project to a separate directory, which is the functionality provided by the `Localize SDK for App` button. `hpm_sdk` will be localized to the same directory as the current application's CMakeLists.txt, named `hpm_sdk_localized_sdk_for_${BOARDNAME}`. The dropdown menu under `SDK Samples` in `Region 3` will prompt for localized projects. Meanwhile, localized project supports the "UnLocalize SDK for App" operation to revert back to the previously unlocalized project. On the far left of `Region 5`, the tool provides a shortcut entry to launch GDB Server. The currently supported GDB Server is OpenOCD. Clicking it allows users to perform simple configurations and quickly start the GDB Server. The GDB Server will remember the user's configuration by default, so it can be directly launched next time. However, when users switch the board, they need to reconfigure OpenOCD before launching it again. Meanwhile, this tool also provides a quick FLASH image programming feature (RAM image programming is not supported). This feature executes the programming operation by calling OpenOCD process, and shares the same OpenOCD launched configuration as the GDB Server to simplify the operation.

6. Log window: The log window shows all the log informations and supports clearing and exporting.

- For user customizing Borad and APP files, please refer to [README.md](user_template/README_en.md) in the user_template directory.

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
  - project_generator
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
### Windows 7 can't use Python 3.9 or above
  - Hpm_sdk relies on Python 3.9 or above, but it can't run directly on Windows 7, requiring installation of pythonw_win7_patch. Download link: https://pan.baidu.com/s/1RaYHOD7xk7fnotmgLpoAlA?pwd=xk2n, path is `先楫技术资料/SDK`.
### When building the project with CMake, a warning is displayed “The object file directory xxx has xxx characters. The maximum full path to an object file is 250 characters..The build may not work correctly.”
  The warning occurs because the path to the current build project's output directory is too long. This may result in some generated obj files having paths that exceed the maximum length supported by the compiler, potentially causing compilation failures. You can address this issue by making the following adjustments:
  - To minimize the absolute path length for hpm_sdk, place the SDK_ENV directory as close to the root of the drive as possible, such as "D:\sdk_env". This reduces the number of directory levels in the absolute path for sdk_env, thereby shortening the entire path length for hpm_sdk.
  - Alternatively, you can shorten the final output directory path length. For example, in start_gui, reduce the "Build Path" to minimize the number of directory levels in the absolute path. Ensuring a shorter path length can help guarantee that the project builds successfully.
  
