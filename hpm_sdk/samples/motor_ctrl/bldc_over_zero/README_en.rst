.. _bldc_sensorless_over_zero_control:

BLDC sensorless over-zero control
==================================================================

Overview
--------

This project shows a sensorless control method for brushless motors
- Control by trapezoidal wave algorithm

- Reverse electric potential over zero method to detect commutation moment

- Speed control

Configurations
--------------

- This program uses the **BLM57050-1000**  brushless motor of "Leisai Intelligence", please refer to the `Leisai Intelligence <https://leisai.com/>`_ website for the specific parameters of the motor.

- Board settings refer to the development board documentation  :ref:`Motor Pin <board_resource>`  related content

- Requires board to support phase current acquisition

-
 .. note::
  The motor driver board J6 J7 J12 to be connected to UU UV UW.


Running the demo
----------------

The motor accelerates at speeds from 5 to 40 revolutions per second when the project is running correctly, then decelerates from 40 to 5 revolutions per second and keeps cycling.


.. warning::

   - After the motor is powered on, it will first perform the "alignment" action. If the motor is disturbed at this time, it will produce a jitter.

   - Pay attention to the current size, when abnormalities occur, please cut off the power at any time

