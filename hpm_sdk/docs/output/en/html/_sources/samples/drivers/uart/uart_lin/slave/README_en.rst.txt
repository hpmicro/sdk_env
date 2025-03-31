﻿.. _uart_lin_slave:

uart_lin_slave
============================

Overview
--------

This project demonstrates the functionality of UART simulation LIN salve.

Note
----

- The interval between data frames should be greater than or equal to the transmission time of 4 UART bytes.

- The baudrate adaptation function is not supported, need to configured UART baudrate to the desired value.

- The slave automatic sleep function is not supported, the master no need to wake up slave.

Board Setting
-------------

- On development boards without onboard LIN transceivers:

  Need a LIN transceiver and a USB_LIN debugger
  Connect the UART TX/RX pins on the development board to the TX/RX signal of the LIN transceiver, and connect the USB_LIN debugger to the LIN signal of the LIN transceiver.
- On development boards with onboard LIN transceivers:

  Need a USB_LIN debugger
  Connect the LIN signal and GND of the debugger to the corresponding pins on the development board.

Please refer to  :ref:`Pin Description <board_resource>`  for specific board.

Running the example
-------------------

configure usb_lin debugger:
- configure com and baudrate, then click `Set to Debugger` option

  .. image:: ../../../../../../../samples/drivers/lin/doc/lin_debugger_configuration.png
     :alt: lin_debugger_configuration

- Configure sent data, including master sent, master receive：

  .. image:: ../../../../../../../samples/drivers/lin/slave/doc/lin_debugger_master_sent_config.png
     :alt: lin_debugger_master_sent

- Running the example, check the result in debugger window

  .. image:: ../../../../../../../samples/drivers/lin/slave/doc/lin_debugger_master_result.png
     :alt: lin_debugger_master_result

When the example runs successfully, the log would be seen on the terminal like:

.. code-block:: console

   Test uart lin salve example
   uart lin receive ID: 0x31
   uart receive 8 data:
   0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7
   uart lin receive ID: 0x30
   uart send 8 data:
   0x7 0x6 0x5 0x4 0x3 0x2 0x1 0x0

