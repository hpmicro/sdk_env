# uart_lin_slave_baudrate_adaptive
## 概述

该工程展示通过PLB检测LIN时钟，UART依据检测的LIN时钟实现LIN从机波特率自适应的收发数据帧功能。

## 注意
- 数据帧之间的间隔应大于等于4个UART字节的传输时间。
- 不支持从机自动休眠，无需主机唤醒。

## 硬件设置

- 在没有板载LIN收发器的开发板上：
  需要一个LIN收发器和一个USB_LIN调试器
  将开发板上的UART TX和RX引脚与LIN收发器的MCU信号相连，将USB_LIN调试器与LIN收发器的LIN信号相连。
- 在有板载LIN收发器的开发板上：
  需要一个USB_LIN调试器
  将调试器的LIN信号和GND与开发板上的对应引脚相连。
- 需要将UART_RX引脚与PLB LIN时钟检测引脚相连，实现PLB监测LIN时钟。

请参考具体开发板{ref}`引脚描述 <lab_board_resource>`部分的描述。

## 运行现象

运行此程序，需要配置usb_lin调试器
- 配置usb_lin调试器，选择正确的串口和波特率， 然后点击`设置到调试器`：
  ![lin_debugger_configuration](../../../lin/doc/lin_debugger_configuration.png)
- 配置发送窗口， 包括主机发送，主机接收：
  ![lin_debugger_master_sent](../../../lin/slave/doc/lin_debugger_master_sent_config.png)
- 当程序正确运行之后， 调试器窗口可以看到结果：
  ![lin_debugger_master_result](../../../lin/slave/doc/lin_debugger_master_result.png)

当工程正确运行后，使用USB_LIN调试器发送数据帧，串口终端会输出如下信息，调整调试器中的LIN波特率，程序也能正确接收：
```console
Test uart lin slave baudrate adaptive example
uart lin receive ID: 0x31
uart receive 8 data:
0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7
uart lin receive ID: 0x30
uart send 8 data:
0x7 0x6 0x5 0x4 0x3 0x2 0x1 0x0
```




