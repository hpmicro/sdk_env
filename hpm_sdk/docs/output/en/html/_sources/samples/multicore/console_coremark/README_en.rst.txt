.. _console_coremark_demo:

Console Coremark Demo
==========================================

Overview
--------

Multi-core Console coremark example project runs the "coremark" example on core0 and core1.

In this project:
 - The multi-core coremark will run automatically when the demo starts to run, and the dual-core coremark result will be

   printed out to the console
 - The application accept next request to run this demo again if detecting any inputs from the console UART.

Board Setting
-------------

  BOOT_PIN should be configured to 0-OFF, 1-OFF

Generate, Build and Debug Multi-core projects
---------------------------------------------

Please reference :ref:`Multicore General Description <multicore_general_description>`

Running the example
-------------------

- Taking HPM6750EVKMINI as an example, when the project runs successfully, it will print out the following result:


.. code-block:: console

   ----------------------------------------------------------------------
   $$\   $$\ $$$$$$$\  $$\      $$\ $$\
   $$ |  $$ |$$  __$$\ $$$\    $$$ |\__|
   $$ |  $$ |$$ |  $$ |$$$$\  $$$$ |$$\  $$$$$$$\  $$$$$$\   $$$$$$\
   $$$$$$$$ |$$$$$$$  |$$\$$\$$ $$ |$$ |$$  _____|$$  __$$\ $$  __$$\
   $$  __$$ |$$  ____/ $$ \$$$  $$ |$$ |$$ /      $$ |  \__|$$ /  $$ |
   $$ |  $$ |$$ |      $$ |\$  /$$ |$$ |$$ |      $$ |      $$ |  $$ |
   $$ |  $$ |$$ |      $$ | \_/ $$ |$$ |\$$$$$$$\ $$ |      \$$$$$$  |
   \__|  \__|\__|      \__|     \__|\__| \_______|\__|       \______/
   ----------------------------------------------------------------------
   Dual-core Coremark example

   Copying secondary core image to destination memory: 0x1180000
   Run Coremark on Core1...

   Run Coremark on Core0...

   ------------------------------------------------------
   |                                                    |
   |          Core0 CoreMark Info:                      |
   |                                                    |
   ------------------------------------------------------
   2K performance run parameters for coremark.
   CoreMark Size    : 666
   Total ticks      : 371867026
   Total time (secs): 15.494459
   Iterations/Sec   : 3872.351941
   Iterations       : 60000
   Compiler version : GCC11.1.0
   Compiler flags   : -Wall -Wno-format -fomit-frame-pointer -fno-builtin -ffunction-sections -fdata-sections -mabi=ilp32 -march=rv32imac -g -O3 -funroll-all-loops -finline-limit=600 -ftree-dominator-optsg
   Memory location  : STACK
   seedcrc          : 0xe9f5
   [0]crclist       : 0xe714
   [0]crcmatrix     : 0x1fd7
   [0]crcstate      : 0x8e3a
   [0]crcfinal      : 0xbd59
   Correct operation validated. See README.md for run and reporting rules.
   CoreMark 1.0 : 3872.351941 / GCC11.1.0 -Wall -Wno-format -fomit-frame-pointer -fno-builtin -ffunction-sections -fdata-sections -mabi=ilp32 -march=rv32imac -g -O3 -funroll-all-loops -finline-limit=600 -K



   ------------------------------------------------------
   |                                                    |
   |               Core1 CoreMark Info:                 |
   |                                                    |
   ------------------------------------------------------
   2K performance run parameters for coremark.
   CoreMark Size    : 666
   Total ticks      : 15608229
   Total time (secs): 15.608229
   Iterations/Sec   : 3844.126070
   Iterations       : 60000
   Compiler version : GCC11.1.0
   Compiler flags   : -Wall -Wno-format -fomit-frame-pointer -fno-builtin -ffunction-sections -fdata-sections -mabi=ilp32 -march=rv32imac -g -O3 -funroll-all-loops -finline-limit=600 -ftree-dominator-optsg
   Memory location  : STACK
   seedcrc          : 0xe9f5
   [0]crclist       : 0xe714
   [0]crcmatrix     : 0x1fd7
   [0]crcstate      : 0x8e3a
   [0]crcfinal      : 0xbd59
   Correct operation validated. See README.md for run and reporting rules.
   CoreMark 1.0 : 3844.126070 / GCC11.1.0 -Wall -Wno-format -fomit-frame-pointer -fno-builtin -ffunction-sections -fdata-sections -mabi=ilp32 -march=rv32imac -g -O3 -funroll-all-loops -finline-limit=600 -K



   Press any key to start a new round of coremark test


- Users can re-run the dual-core coremark test by press any keys
