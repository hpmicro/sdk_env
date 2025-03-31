.. _pdma:

PDMA
========

概述
------

该工程演示了PDMA图像缩放、旋转和Porter-Duff Alpha Blending的功能。

硬件设置
------------

连接LCD到板上LCD接口。

编译类型
------------

- flash_sdram_xip

- flash_sdram_xip_release

运行现象
------------

当工程正确运行后，可以在LCD上看到图像变化。串口终端会输出如下信息：

.. code-block:: console

   pdma example
   2 rectangles will be drawn on the screen with alpha blending enabled

