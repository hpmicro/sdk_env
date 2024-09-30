# BLDC BLOCK

## Overview

**Bldc_block** project demonstrates speed control of the BLDC.
- Control by trapezoidal wave algorithm

## Configurations

- This program uses the **BLM57050-1000** brushless motor of "Leisai Intelligence", refer to the [Leisai Intelligence](https://leisai.com/) website for the specific parameters of the motor.

- Board settings refer to the development board documentation [Motor Pin](lab_board_motor_ctrl_pin) related content
    - SOCs without the HALL peripheral need to connect the HALL signal from the motor board to the QEI pin on the motor interface of the development board.

## Running the Demo

The motor runs at a speed of 20r/s.
The following data can be configured by serial console ：

``speed`` float, range +40~+5 -40~-5 0, unit r/s.

The serial console message is as follows:

```console

Speed mode, motor run, speed is: 20.000000.
Input speed:

Speed mode, motor run, speed is: 10.500000.
Input speed:

```

```{warning}
Pay attention to the current size, when abnormalities occur, please cut off the power at any time
```
