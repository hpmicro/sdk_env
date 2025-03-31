.. _msc_sd_card:

MSC SD CARD
======================

概述
------

本示例工程展示USB MSC设备，使用SD卡模拟出一个U盘。

- PC 通过设备管理器查看得到一个U盘

- 注意：SD卡数据格式为FAT或exFAT

硬件设置
------------

- 使用USB Type-C线缆连接PC USB端口和PWR DEBUG端口

- 使用USB Type-C线缆连接PC USB端口和开发板USB0端口

运行现象
------------

- 将程序下载至开发板运行，电脑可自动识别并枚举出一个U盘

- 可以将文件copy至U盘，然后从U盘copy出来，可当做U盘使用
