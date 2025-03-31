﻿.. _uart_lin_master:

uart_lin_master
==============================

概述
------

该工程演示了UART模拟LIN的功能。

注意
------

数据帧之间的间隔应大于等于4个UART字节的传输时间。

硬件设置
------------

- 在没有板载LIN收发器的开发板上：

  需要一个LIN收发器和一个USB_LIN调试器
  将开发板上的UART TX和RX引脚与LIN收发器的MCU信号相连，将USB_LIN调试器与LIN收发器的LIN信号相连。
- 在有板载LIN收发器的开发板上：

  需要一个USB_LIN调试器
  将调试器的LIN信号和GND与开发板上的对应引脚相连。

请参考具体开发板  :ref:`引脚描述 <board_resource>`  部分的描述。

运行现象
------------

运行此程序，需要配置usb_lin调试器
- 配置usb_lin调试器，选择正确的串口和波特率， 然后点击`设置到调试器`：

  .. image:: ../../../../../../../samples/drivers/lin/doc/lin_debugger_configuration.png
     :alt: lin_debugger_configuration

- 配置作为从机发送配置选项， 设置ID和数据以及校验方式，勾选使能选项， 点击`配置到调试器`：

  .. image:: ../../../../../../../samples/drivers/lin/master/doc/lin_debugger_slave_sent_config.png
     :alt: lin_debugger_slave_sent

- 当程序正确运行之后， 调试器窗口可以看到结果：

  .. image:: ../../../../../../../samples/drivers/lin/master/doc/lin_debugger_slave_result.png
     :alt: lin_debugger_slave_result

当工程正确运行后，串口终端会输出如下信息：

.. code-block:: console

   Test uart lin master polling transfer
   uart lin master send ID: 0x31
   uart send 8 data:
   0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7
   uart lin master send ID: 0x30
   uart receive 8 data:
   0x7 0x6 0x5 0x4 0x3 0x2 0x1 0x0

   Test uart lin master interrupt transfer
   uart lin master send ID: 0x31
   uart send 8 data:
   0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7
   uart lin master send ID: 0x30
   uart receive 8 data:
   0x7 0x6 0x5 0x4 0x3 0x2 0x1 0x0

