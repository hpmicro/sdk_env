# Change Log 

## [1.10.0] - 2025-06-30:
- start_gui: add quick start menu
- start_gui: change the gcc compile button text to compile.
- start_gui: update docs and image for start_gui UI.
- docs: add evkug ses guide.
- docs: add hpm5e00evk ug
- update sdk to v1.10.0

## [1.9.0] - 2025-03-31:
- tools: openocd: support hybrid_xip
- start_gui: replace sdk path with parameters in preset.bat.
- start_gui: add search path in openocd commands.
- start_gui: fix bug that start_gui will crash if the path of hpm_sdk is too long.
- start_gui: fix bug that cmake process will be blocked if the build folder of current sample is removed when generating another sample
- start_gui: show animation when localize sdk process starting.
- update sdk to v1.9.0

## [1.8.0] - 2024-12-31:
- update SDK to v1.8.0
- start_gui: fix cmake build type's error under certain conditions and support saving board and sample info.
- start_gui: fix bug about default board used and log display error.
- start_gui: fix bug that error log had false positive if project had "error" or "fail" keywords.
- README: add known issue for CMAKE_OBJECT_PATH_MAX problem.

## [1.7.0] - 2024-09-30:
- update SDK to v1.7.0
- start_gui:
  - add button to open board/application folder in explorer

## [1.6.0] - 2024-06-30:
- update SDK to v1.6.0

## [1.5.0] - 2024-03-29:
- update SDK to v1.5.0
- update toolchain to gcc 13.2
- start_gui:
  - add button to localize sdk for app
  - add button to launch gdb server
  - add button to compile with gcc
- update HPM6800EVK UG to 1.1

## [1.4.0] - 2023-12-29:
- update SDK to v1.4.0
- start_gui: support custom linker script

## [1.3.0] - 2023-09-28:
- update SDK to v1.3.0
- start_gui: support custom sample directory

## [1.2.0] - 2023-06-30:
- update SDK to v1.2.0
- project_generator: support cmake building with custom board path parameter.

## [1.1.0] - 2023-03-31:
- update SDK to v1.1.0
- tools: ft2232 driver update to libusbk
- doc: add hpm6200evk quick start guide

## [1.0.0] 2022-12-31:

- Update SDK to v1.0.0
- Add HPM6750EVK2 quick guide
- Add runtime for start_gui

## [0.14.0] 2022-10-31:

### Changed
 - Update SDK to v0.14.0
 - update cmake to 3.24

### Added
 - project_generator


## [0.13.1] 2022-08-22:

### Changed
 - Update SDK to v0.13.1

### Fixed
 - start_cmd.cmd: fix open terminal here issue

## [0.13.0] 2022-07-31:

### Changed
 - Update SDK to v0.13.0

### Added
 - Add script to generate all ses projects
 - doc: add hpm_sw_qsg

## [0.12.1] 2022-07-01:

### Changed
 - Update SDK to v0.12.1

## [0.12.0] 2022-06-30:

### Changed
 - Update SDK to v0.12.0
 - Update doc

### Added
 - start_cmd: add long path support

## [0.11.0] 2022-05-31:

### Changed
 - Update SDK to v0.11.0
### Added
 - Add hpm6360evk quick guide

## [0.10.0_hpm6360] 2022-05-16:

### Changed
 - Update SDK supporting HPM6360

## [0.10.0] 2022-04-30:

### Changed
 - Update gcc toolchain supporting multilib and newlib-nano

### Added
 - Add program_flash.cmd support programming flash using openocd
 - generate_project.cmd: add tinyuf2 loadeable build type: flash_uf2, flash_sdram_uf2

## [0.9.0] 2022-03-31:

### Changed
 - Update SDK to 0.9.0

### Added
 - Add registry file to enable long path on Windows

## [0.8.1] 2022-03-09:

### Changed
 - update openocd to fix issue cmsis-dap can't connected.

## [0.4.0] 2022-03-04:

### Changed
 - Update SDK to 0.8.0
 - Update openocd to take parameter from config file to config onboard flash

## [0.3.1] 2022-02-13:

### Changed:
 - Update SDK to 0.7.1

### Added:
 - Add option to generate project for secondary core

## [0.3.0] 2022-01-30:

### Changed:
 - Update SDK to 0.7.0
 - Update usb driver for FTDI to winusb from libusbk
 - Update openocd with improved flash erasing
 - Update included gnu gcc toolchain

