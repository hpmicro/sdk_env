.. _bldc_smc:

BLDC SMC
================

Overview
--------

The **bldc_smc**  project contains the sensorless speed control of DC brushless motors.
- Use the **FOC**  control algorithm

- Sensorless control algorithm for **SMC**

Configurations
--------------

- This program uses the **BLM57050-1000**  brushless motor of "Leisai Intelligence", please refer to the `Leisai Intelligence <https://leisai.com/>`_ website for the specific parameters of the motor.

- Board settings refer to the development board documentation  :ref:`Motor Pin <board_resource>`  related content

Running the demo
----------------

The motor accelerates at speeds from 15 to 40 revolutions per second when the project is running correctly, then decelerates from 40 to 15 revolutions per second and keeps cycling.

The serial console message is as follows:


.. code-block:: console

   bldc smc demo.



.. warning::

   - After the motor is powered on, it will first perform the "alignment" action. If the motor is disturbed at this time, it will produce a jitter.

   - Pay attention to the current size, when abnormalities occur, please cut off the power at any time

