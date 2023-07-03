# HPM SDK Windows 开发环境配置工具

## 快速开始指南
1. 安装FT2232驱动。
![驱动安装](doc/img/ftdi_install.png)
1. 双击`start_cmd.cmd`，该脚本将开启一个Windows命令行窗口，之后文中将以***sdk prompt***指代该命令行窗口。（***sdk prompt***中将把所有HPM SDK开发依赖的环境变量以及对应工具的路径设置正确，作用范围仅在***sdk prompt***内，不影响当前系统中的变量。）
1. 双击`generate_all_ses_projects.cmd`，该脚本会在同级目录下生成文件夹samples_ses_project，该文件夹包含各种类型板子所有用例的segger工程
1. 
## 目录结构:
- hpm_sdk: hpm_sdk存放目录，当更新SDK时，需要将SDK解压至该文件夹，并确保可以存在hpm_sdk\cmake路径
- toolchains: 工具链存放目录。当更新工具链时，将对应工具链解压至该文件夹(以TOOLCHAIN_NAME为例)，并确保可以在toolchains\TOOLCHAIN_NAME\bin路径下可以找到riscv32-elf-unknown-gcc.exe可执行文件
  - 注意:
    - 使用不同toolchain的时候，对应TOOLCHAIN_NAME需要在start_cmd.cmd中进行正确配置
- tools:
  - ninja
  - cmake
  - python3
  - openocd
  - scripts
  - FTDI_InstallDriver.exe: FT2232 windows 驱动
- doc: 文档目录

## 常见问题：
### 无法找到ftdi调试器
  - 确保正确安装FTDI_InstallDriver.exe驱动。注意：如果更换了PC USB端口, 有可能需要重新安装驱动
### Segger Embedded Studio无法进行调试
  可以做下尝试
  - 重新打开Segger Embedded Studio
  - 在Windows任务管理器中将残留的openocd进程终止
  - 将开发板上启动模式拨成“在系统编程“或者“串行启动”，再按RESET按钮，再尝试调试
### Windows 10路径长度限制
  若要解除路径长度限制可以通过导入tools/scripts/win10_enable_long_path.reg。 有关该限制的详细信息, 请参考https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=cmd
