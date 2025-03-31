.. _use_dma_to_receive_and_send_uart_data:

DMA接收和发送数据UART
============================

概述
------

该示例工程中，展示UART采用DMA的方式接收和发送数据的操作。

端口设置
------------

- 串口波特率设置为 ``115200bps`` ，``1个停止位`` ，``无奇偶校验位``

注意
------

- 通过串口单次输入的字符串长度不应该超过程序中定义的TEST_BUFF_SIZE

运行现象
------------

当工程正确运行后，通过串口手动输入字符串，如 '1234567887654321'，则串口终端会收到如下信息：：

.. code-block:: console

   UART DMA example
   UART will send back received characters, echo every 16 bytes
   1234567887654321

