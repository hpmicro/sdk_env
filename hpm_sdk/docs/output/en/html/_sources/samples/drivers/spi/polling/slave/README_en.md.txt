# SPI_POLLING_SLAVE

## Overview

The spi_polling_slave example shows how to use spi driver as slave to do board to board transfer with polling.
In this example, one spi instance as master and another spi instance on other board as slave. Master sends a piece of data to slave, and receives a piece of data from slave. This example checks if the data received from slave is correct.

## Board Setting

Connect [SPI Pins](lab_board_app_spi_pin) of the two boards.

the two boards must be connected to the GND of both sides for a common ground to ensure signal transmission.


## Running the example

- Run slave first, and then run master.

- When the example runs successfully, the log would be seen on the terminal like:
```console
SPI-Slave Polling Transfer Example
SPI-Slave transfer format is configured.
SPI-Slave transfer mode:write-read-together
SPI-Slave transfer waits.
SPI-Slave read  data: 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9
SPI-Slave write data: 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 0xb8 0xb9
SPI-Slave transfer ends.
```

## Notice
- To ensure normal transmission, it is recommended to add a 4.7K pull-up resistor to the SPI CS pin.
