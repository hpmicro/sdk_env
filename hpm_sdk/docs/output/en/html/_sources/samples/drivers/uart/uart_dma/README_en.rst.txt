.. _use_dma_to_receive_and_send_uart_data:

Use DMA to receive and send UART data
==========================================================================

Overview
--------

In this example project, UART receives/sends data via DMA.

Port Settings
-------------

- Serial port baud rate is set to ``115200bps`` , with ``one stop bit``  and ``no parity bit``

Note
----

- The input string length should not exceed TEST_BUFF_SIZE defined in the program every time

Running the example
-------------------

When the project runs correctly, manually input the char through the serial port, such as '1234567887654321', and the serial port terminal will receive the following information:

.. code-block:: console

   UART DMA example
   UART will send back received characters, echo every 16 bytes
   1234567887654321

