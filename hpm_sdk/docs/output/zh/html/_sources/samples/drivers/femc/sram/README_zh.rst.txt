.. _sram_example:

SRAM example
========================

概述
------

SRAM示例工程展示了读写内部或外部SRAM存储器的性能。

硬件设置
------------

需外接SRAM模块，本sample测试的SRAM型号为：IS62WV51216EBLL45TLI。

HPM6300系列在地址线和数据线非复用模式下，只有8根地址线，IS62WV51216EBLL45TLI的高位地址线须接地。

运行现象
------------

当工程正确运行后，串口终端会输出如下信息：

.. code-block:: text

   sram example
   comparison test: from 0x48000000 to 0x48001000
   **  u32 comparison succeeded
   **  u16 comparison succeeded
   **  u8 comparison succeeded


温馨提示
------------

当使用SRAM接口访问外部设备（非存储类），例如FPGA，需将SRAM地址空间配置成non-cacheable。
