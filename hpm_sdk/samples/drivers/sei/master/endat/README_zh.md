# SEI Master: Connect ENDAT Encoder

## 概述

该工程主要演示通过SEI接口获取ENDAT编码器位置数据，自动计算采样/更新延时，并通过串口将信息打印出来。

## 配置

- 需要两块开发板，一块板子作为Master，一块板子作为Slave。
- Slave的sample的路径为：samples/drivers/sei/slave/endat，master即为本示例。
- 将Master的SEI_CLK跨针跨至Master侧，将Slave的SEI_CLK跨针跨至Slave侧。
- 将Master的SEI接口信号DATA_P/DATA_N与Slave的SEI接口信号DATA_P/DATA_N相连接。
- 将Master的SEI接口信号CLKO_P/CLKO_N与Slave的SEI接口信号CLKI_P/CLKI_N相连接。
- 将Master的GND与Slave的GND相连接。

## 运行现象

- 通过串口终端查看到的log如下，ST数值每次加1。

```console

----------------------------------------------------------------------
$$\   $$\ $$$$$$$\  $$\      $$\ $$\
$$ |  $$ |$$  __$$\ $$$\    $$$ |\__|
$$ |  $$ |$$ |  $$ |$$$$\  $$$$ |$$\  $$$$$$$\  $$$$$$\   $$$$$$\
$$$$$$$$ |$$$$$$$  |$$\$$\$$ $$ |$$ |$$  _____|$$  __$$\ $$  __$$\
$$  __$$ |$$  ____/ $$ \$$$  $$ |$$ |$$ /      $$ |  \__|$$ /  $$ |
$$ |  $$ |$$ |      $$ |\$  /$$ |$$ |$$ |      $$ |      $$ |  $$ |
$$ |  $$ |$$ |      $$ | \_/ $$ |$$ |\$$$$$$$\ $$ |      \$$$$$$  |
\__|  \__|\__|      \__|     \__|\__| \_______|\__|       \______/
----------------------------------------------------------------------
SEI master EnDat sample
Started sei engine!
E:0, ST:0xa5a5, CRC:0x5, sample_tm:2465400001, update_tm:2465409502, TimeDelay:475*0.1us
E:0, ST:0xa5a6, CRC:0xf, sample_tm:2505400001, update_tm:2505409502, TimeDelay:475*0.1us
E:0, ST:0xa5a7, CRC:0x1a, sample_tm:2545400001, update_tm:2545409502, TimeDelay:475*0.1us
E:0, ST:0xa5a8, CRC:0x7, sample_tm:2585400001, update_tm:2585409502, TimeDelay:475*0.1us
E:0, ST:0xa5a9, CRC:0x12, sample_tm:2625400001, update_tm:2625409502, TimeDelay:475*0.1us
E:0, ST:0xa5aa, CRC:0x18, sample_tm:2665400001, update_tm:2665409502, TimeDelay:475*0.1us



```