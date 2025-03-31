﻿.. _lin_slave:

lin_slave
==================

概述
------

lin_slave工程展示了LIN在slave模式接收和发送数据的功能

硬件设置
------------

需要一个LIN收发器和一个USB_LIN调试器
请参考具体开发板 :ref:`引脚描述 <board_resource>` 部分的描述。
将开发板上的LIN TX和RX引脚与LIN收发器的MCU信号相连，将USB_LIN调试器与LIN收发器的LIN信号相连。

运行现象
------------

运行此程序，需要配置usb_lin调试器
- 配置usb_lin调试器，选择正确的串口和波特率， 然后点击`设置到调试器`：

  .. image:: ../../../../../../samples/drivers/lin/doc/lin_debugger_configuration.png
     :alt: lin_debugger_configuration

- 配置发送窗口， 包括主机发送，主机接收和同步间隔，同步间隔可用于将从机从休眠模式唤醒：

  .. image:: ../../../../../../samples/drivers/lin/slave/doc/lin_debugger_master_sent_config.png
     :alt: lin_debugger_master_sent

- 当程序正确运行之后， 调试器窗口可以看到结果：

  .. image:: ../../../../../../samples/drivers/lin/slave/doc/lin_debugger_master_result.png
     :alt: lin_debugger_master_result

当工程正确运行后，串口终端会输出如下信息：

.. code-block:: console

   LIN slave example
   LIN bus timeout, will enter sleep mode
   LIN wakeup
   ID: 31, receive 8 bytes
   0 1 2 3 4 5 6 7
   ID: 30, sent 8 bytes
   7 6 5 4 3 2 1 0

