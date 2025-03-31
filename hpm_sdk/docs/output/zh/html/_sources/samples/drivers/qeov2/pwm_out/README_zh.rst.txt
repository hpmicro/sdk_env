﻿.. _qeov2_pwm_out:

QEOV2_PWM_OUT
==========================

概述
------

QEO_PWM_OUT示例工程展示QEO根据得到的位置信息，通过PWM外设输出PWM波形的功能。

硬件设置
------------

观察指定PWM引脚的输出波形，(请参考 :ref:`引脚描述 <board_resource>` 部分)。

运行现象
------------

- 当工程正确运行后， 通过示波器或逻辑分析仪观察PWM引脚上的信号，串口终端会输出如下信息：


.. code-block:: console

   QEO PWM example
   QEO generate PWM signal with software inject postion
   QEO generate PWM signal with hardware provide postion

使用逻辑分析仪可以抓到2种PWM波形


.. image:: ../../../../../../samples/drivers/qeov2/pwm_out/doc/qeo_pwm_1.png
   :alt:


.. image:: ../../../../../../samples/drivers/qeov2/pwm_out/doc/qeo_pwm_2.png
   :alt:
