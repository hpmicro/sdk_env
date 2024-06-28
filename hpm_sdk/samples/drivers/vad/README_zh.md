# VAD

## 概述

该工程演示了使用VAD记录声音并通过DAO播放的功能。

## 硬件设置

连接扬声器到板上DAO接口。

## 已知问题

使用DAO播放某些音频时会产生噪声。

## 运行现象

当工程正确运行后，按照log提示发出声音，声音会被记录并播放出来。串口终端会输出如下信息：
```console
vad example
vad calibration done
Recording...
Please make some sound to mic0
Got something...
Recorded 204800 bytes data
Now, playing...
```