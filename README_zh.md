# HPM SDK Windows 开发环境配置工具

## 快速开始指南
1. 安装FT2232驱动。
![驱动安装](doc/img/ftdi_install.png)
1. 双击`start_cmd.cmd`，该脚本将开启一个Windows命令行窗口，之后文中将以***sdk prompt***指代该命令行窗口。（***sdk prompt***中将把所有HPM SDK开发依赖的环境变量以及对应工具的路径设置正确，作用范围仅在***sdk prompt***内，不影响当前系统中的变量。）
1. 双击`generate_all_ses_projects.cmd`，该脚本会在同级目录下生成文件夹samples_ses_project，该文件夹包含各种类型板子所有用例的segger工程

## start_gui 快速上手
`start_gui.exe` 是一款适配 `hpm_sdk` 的项目构建可视化工具。通过该工具，您可以方便地对 `hpm_sdk` 中的 samples 进行构建，也可以自定义 sample 目录来构建自己的应用程序。软件整体界面如下图所示:
![start_gui](doc/img/start_gui.png)

不同的背景色将该软件分为了以下几个功能区：

1. SDK ENV 设置：此处可手动配置 SDK ENV 路径，点击 `Advanced` 按钮后，可以对 `hpm_sdk` 以及 `CMake、Ninja` 等工具路径进行更详细的配置；

2. Board 设置：默认情况下，工具会列出 `hpm_sdk/boards` 文件夹下所有的开发板。同时，工具也支持加载用户自定义的开发板配置。用户需要首先勾选 `Enable User Board Path` 复选框启用 `User Board` 搜索功能，然后选择想要搜索的开发板文件夹，软件会搜索`当前文件夹`以及`第一级子文件夹`，当查找到文件夹下存在`CMakeLists.txt 以及 与文件夹同名的 yaml 配置文件`时，会识别当前文件夹为开发板配置，加入到列表项中。当`当前文件夹`被识别为开发板配置时，不会再搜索子文件夹；

**注意：如果使用自定义 board，CMake 构建过程会尝试在自定义目录下搜索与 board 目录同名的 .cfg 文件作为板级 openocd 的配置文件，若无此文件，openocd 将不会添加任何板级配置文件**

3. Sample 设置：选择了开发板后，工具会根据开发板的yaml配置文件自动筛选符合条件的 sample。默认情况下，会展示`hpm_sdk/samples` 文件夹下经过筛选的sample。同时，工具也支持加载用户自定义的 sample 文件夹。用户需要首先勾选 `Enable User Application Path` 复选框启用 `User Applications` 搜索功能，然后选择想要搜索的 sample 文件夹，软件会搜索`当前文件夹`以及`所有子文件夹`，当查找到文件夹下存在 `CMakeLists.txt`时，会查找当前`CMakeLists.txt`是否调用了 `hpm-sdk`，符合条件的会识别为 sample 文件夹并加入到列表项中。当选择了 sample 之后，会自动识别当前 sample 支持的 build type 类型并加入到列表项中；

4. Output 设置：用户可以在 Output 区域定义工程的构建生成路径。默认情况下，项目会生成在 `${sample}/${board}_${build_type}` 文件夹。同时，工具支持选择一个父文件夹，将多个项目生成在当前父文件夹下。该功能需要用户勾选 `Use Same Parent Directory` 复选框，然后选择一个父文件夹，即 `Parent Directory`，之后构建生成的项目均会保存在当前文件夹下，`Build Folder` 为项目文件夹名称，工具会采用`${sample}_${board}_${build_type}`规则自动生成文件夹名称，用户也可以手动修改文件夹名称；

5. 构建选项： 当配置完毕后，用户可点击 `Generate Project` 按钮开始构建项目，当项目正确构建后，`Open Project with IDE`按钮会高亮，点击后会用IDE拉起当前项目。同时，工具支持控制台编译，点击 `Open Build Console` 按钮后，会拉起控制台，该控制台默认加载了 `SDK_ENV` 的环境变量，可以直接编译程序；

6. 日志窗口：日志窗口会显示当前的日志信息，日志信息支持清空和导出。


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
  - project_generator
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
