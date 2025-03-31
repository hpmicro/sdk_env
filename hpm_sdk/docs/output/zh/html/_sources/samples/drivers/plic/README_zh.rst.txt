.. _plic:

PLIC
========

概述
------

PLIC示例工程使用`ptpc(or gptmr)/gpio/plicsw`三个中断演示中断嵌套功能。

ptpc(or gptmr)中断服务程序会在5次GPIO按键中断发生之后完成, 同时在GPIO按键中断中将触发软件中断。

硬件设置
------------

无特殊设置

运行现象
------------

运行工程，按照log提示按下GPIO按键(请确认具体开发板 {ref}`按键 <board_resource>` 部分描述)，会产生中断嵌套，串口终端会输出如下信息：

.. code-block:: console

   Machine mode (Vector Preemptive) interrupt test
   Press button will trigger GPIO interrupt, in which software interrupt will be triggered as well.
   ptpc(or gptmr) interrupt start
   + now next 5 gpio interrupts will occur in nested irq context
   gpio interrupt start
   plicsw start
   plicsw end
   gpio interrupt end

