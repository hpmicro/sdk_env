.. _i2s_slave:

I2S Slave
==================

Overview
--------

I2S slave example shows i2s controller as slave with DMA communicate with master between board and board.

I2S slave sends a piece of audio data in a loop to master.

Board Setting
-------------

- Connect  :ref:`I2S Pins <board_resource>`  bewteen the two boards.

  Connect Master FCLK with Slave FCLK

  Connect Master BCLK with Slave BCLK

  Connect Master RXD with Slave TXD

  Connect GND together between board and board

Running the example
-------------------

- None
