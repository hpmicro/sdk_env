# Filter Output
## Overview

Demonstrated configuring PLB as a filter, supporting rapid change mode, delay mode, stable low mode, and stable high mode.

## Board Setting

- Please refer to the [PLB Filter Pins](lab_board_app_plb_filter_pins) for input and output signals
- Input high or low levels of the input signal (high level when connected to 3.3V, low level when disconnected), and use an oscilloscope or logic analyzer to observe the input signal and the filtered signal.

## Outline Design

- Please refer to the[PLB Filter component readme](../../../../components/plb/filter/doc/README_en.md)

## Running the example

- Compile and download the program, the console will output the following information:
``` console
PLB Filiter Demo.

Please Select Filter Mode:
  0 - Filter rapid change mode
  1 - Filter delay mode
  2 - Filter stable low mode
  3 - Filter stable high mode
```

- Please enter 0 - 3 to select the filtering mode

- Input high or low levels of the input signal (high level when connected to 3.3V, low level when disconnected), and use an oscilloscope or logic analyzer to observe the input signal and the filtered signal.
