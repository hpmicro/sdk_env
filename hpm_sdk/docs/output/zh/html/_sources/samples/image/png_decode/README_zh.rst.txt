﻿.. _png_decode:

PNG 解码
============

概述
------

PNG 解码示例工程展示了如何使用LODEPNG软件库解码PNG图片数据

硬件设置
------------

- **USB盘** 连接到开发板 ``USB0`` （注意：U盘格式化的 `分配单元大小` 不能超过32KB，建议格式化参数为FAT32/32KB），或 **SD内存卡** 插入到开发板 ``sd card`` 。

  .. image:: ../../../../../samples/image/common/doc/UDisk_Format.png
     :alt: UDisk_Format

- **LCD屏** 连接到开发板

工程配置
------------

- 文件 `CMakeLists.txt` :

  - ``set (PNG_USE_SDCARD 1)``  从SD卡中读取png文件(.png); ``set (PNG_USE_UDISK 1)``  从u盘中读取png文件(.png)。这两个为排他选项

支持的图片格式
---------------------

- 支持标准的PNG图片

本例程支持的图片大小
------------------------------

- png文件不大于1MB

运行现象
------------

- 按需要更改CMakeLists.txt中关于目标存储/解码方式的配置，目标存储默认为SD卡。

- 将png文件复制到目标存储中

- 连接LCD屏和存储介质到开发板

- 将开发板上电

- 下载编译后的elf文件到开发板

- 如果一切正常，存储介质中的png文件将被一张张显示在LCD屏上
