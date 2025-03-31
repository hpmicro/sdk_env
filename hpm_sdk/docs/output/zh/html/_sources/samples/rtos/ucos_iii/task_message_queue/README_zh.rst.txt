.. _uc_os_iii_task_message_queue:

uC/OS-III 任务内嵌消息队列
====================================

概述
------

该工程演示了uC/OS-III的任务内嵌消息队列功能。

硬件设置
------------

无特殊设置

运行现象
------------

当工程正确运行后，LED会开始闪烁，串口终端会输出如下信息：

.. code-block:: console

   que remain 0.
   led0 task send que.
   float task get  que .
   que:  led_send_que 0.
   que remain 0.
   led0 task send que.
   float task get  que .
   que:  led_send_que 1.
   que remain 0.
   led0 task send que.
   float task get  que .
   que:  led_send_que 2.
   que remain 0.
   led0 task send que.
   float task get  que .
   que:  led_send_que 3.

