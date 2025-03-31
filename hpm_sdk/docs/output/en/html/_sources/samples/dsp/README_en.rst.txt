.. _dsp:

DSP
======

Overview
--------

The dsp_demo sample project shows the DSP CFFT and CIFFT calculations and prints the results through the serial port.

Board Setting
-------------

No special settings

Running the example
-------------------

When the project runs correctly, and the serial port terminal will output the following information:


.. code-block:: console

   --------------------
   after CFFT_RD2, maxdiff= 0x0080 [0.00390816]
   --------------------
   MAE is 0.00079375, RMSD is 0.00176055, NRMSD is 0.00005502, MAXDIFF is 0.00390816, SNR is 67.12823486
   CFFT_RD2 out scaleup by 64
   after CIFFT_RD2, maxdiff= 0x0009 [0.00029564]
   --------------------
   MAE is 0.00012192, RMSD is 0.00014900, NRMSD is 0.00007450, MAXDIFF is 0.00029564, SNR is 73.52618408
   CIFFT_RD2 out scaleup by 2
   CIFFT_RD2 PASS

