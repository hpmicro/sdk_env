.. _opener_motor:

OpENer Motor
========================

Overview
----------

The OpENer Motor example is used to demonstrate the function of realizing remote motor speed control through the Ethernet/IP (EIP) protocol using OpENer.

Preparation
-------------

Hardware
~~~~~~~~~~~~

  - A development board with Ethernet. Refer to the {ref}pin description <board_resource> of the specific development board to view the Ethernet hardware.

    - ==According to your development board, select RMII/RGMII and ethernet phy in the CMakeLists.txt==

  - A PC with a network port.

    - The TwinCAT3 software has adaptation issues with PC network cards. Some supported Intel network cards.

  - This program uses the **BLM57050-1000**  brushless motor of "Leisai Intelligence", please refer to the `Leisai Intelligence <https://leisai.com/>`_ website for the specific parameters of the motor.

  - Board settings refer to the development board documentation  :ref:`Motor Pin <board_resource>`  related content

Software
~~~~~~~~~~~~

  - TwinCAT3.1(Build 4024.56)

TwinCAT project settings
---------------------------

Create a project
~~~~~~~~~~~~~~~~~~~~

  1. Open the TwinCAT software and select File -> New -> Project.

    .. image:: doc/Twincat_new_project_1.png
       :alt:

  2. Select TwinCAT Project, name it and click OK.

    .. image:: doc/Twincat_new_project_2.png
       :alt:

Software configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~

  1. Update the network card driver (required when using for the first time).

    .. image:: doc/Twincat_ethernet_driver.png
       :alt:

    .. image:: doc/Twincat_ethernet_driver_2.png
       :alt:

  2. Clock setting

    When the software is running, the following error may be encountered: It is necessary to run C:\TwinCAT\3.1\System\win8settick.bat with administrator privileges.
      - - -

      *Init4\RTime：Start Interrupt：Ticker started >> AdsWarning4115 （0x1013,RTIME：system clock setup failed）*
      - - -

      .. image:: doc/Twincat_set_tick.png
         :alt:

Add EIP Scanner
~~~~~~~~~~~~~~~~~~~

  1. Click on Device, right-click to add a new item.

    .. image:: doc/add_new_interface.png
       :alt:

  2. Select EIP Scanner.

    .. image:: doc/seclet_new_interface.png
       :alt:

  3. Select the network card after the driver is updated.

    .. image:: doc/seclet_local_interface.png
       :alt:

  4. Configure the IP address.

    .. image:: doc/set_ip_address.png
       :alt:

  5. Re-enter the configuration mode to make the IP configuration in the previous step take effect.

    .. image:: doc/reenter_config_mode.png
       :alt:

Add EDS file
~~~~~~~~~~~~~~~~~

  Right-click on EIP Scanner and select import EDS file. Select opener/opener_blinky_app.eds.

    .. image:: doc/import_eds_file.png
       :alt:

Scan devices
~~~~~~~~~~~~~~~~~

  1. Right-click on EIP Scanner and then scan.

    .. image:: doc/scan.png
       :alt:

  2. Add a device.

    .. image:: doc/found_new_device.png
       :alt:

Add IO connection
~~~~~~~~~~~~~~~~~~~~~

  .. image:: doc/add_io_connection.png
     :alt:

  If there is no `Exclusive Owner` is the combox, specify the eds file manually.

  .. image:: doc/load_from_eds.png
     :alt:

IO operation
~~~~~~~~~~~~~~~~

  1. For input IO, press the button KEYA on the evaluation board, and the value of Input/Key State changes.

    .. image:: doc/keystate.png
       :alt:

  2. For output IO, right-click on Led State, select Online, and click Write to write a value. When writing 1, the LED on the development board lights up. When writing 0, the LED on the development board turns off.

    .. image:: doc/ledstate.png
       :alt:

  3. For output IO. Right-click "Motor Target Speed", select "Online", and click "Write" to enter a value. The motor rotates according to the input value. Note that the upper limit of the motor speed is 35.

    .. image:: doc/set_motor_speed.png
       :alt:

  4. For input IO. Observe "Inputs/Motor Current Speed", which shows the real-time motor speed.

    .. image:: doc/current_motor_speed.png
       :alt:

  5. For input IO, right-click Break, select Online, and write values by motor Write. When inputting 1, the motor stops rotating. When inputting 0, the motor resumes the rotating state before stopping.

    .. image:: doc/break.png
       :alt:

Operation phenomenon
-----------------------

After the project runs correctly, the serial terminal will output the following information:

.. code-block:: console

   This is an Ethernet/IP demo.
   LwIP Version: 2.1.2

   Speed mode, motor run, speed is: 0.000000.
   Enet phy init passed !
   Link Status: Down
   Link Status: Down
   Link Status: Up
   Link Speed:  100Mbps
   Link Duplex: Full duplex
   IPv4 Address: 192.168.100.10
   IPv4 Netmask: 255.255.255.0
   IPv4 Gateway: 192.168.100.1
   Mesaage receieved from host!

