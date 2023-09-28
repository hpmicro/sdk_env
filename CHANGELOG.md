# Change Log 

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

