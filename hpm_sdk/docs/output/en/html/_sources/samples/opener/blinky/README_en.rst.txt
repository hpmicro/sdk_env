.. _opener_blinky:

OpENer Blinky
==========================

Overview
----------

The OpENer Blinky example is used to demonstrate the function of realizing remote IO through the Ethernet/IP (EIP) protocol using OpENer.

Preparation
-------------

Hardware
~~~~~~~~~~~~

  - A development board with Ethernet. Refer to the {ref}pin description <board_resource> of the specific development board to view the Ethernet hardware.

    - ==According to your development board, select RMII/RGMII and ethernet phy in the CMakeLists.txt==

  - A PC with a network port.

    - The TwinCAT3 software has adaptation issues with PC network cards. Some supported Intel network cards.

Software
~~~~~~~~~~~~

  - TwinCAT3.1(Build 4024.56)

TwinCAT project settings
---------------------------

Create a project
~~~~~~~~~~~~~~~~~~~~

  1. Open the TwinCAT software and select File -> New -> Project.

    .. image:: ../../../../../samples/opener/blinky/doc/Twincat_new_project_1.png
       :alt:

  2. Select TwinCAT Project, name it and click OK.

    .. image:: ../../../../../samples/opener/blinky/doc/Twincat_new_project_2.png
       :alt:

Software configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~

  1. Update the network card driver (required when using for the first time).

    .. image:: ../../../../../samples/opener/blinky/doc/Twincat_ethernet_driver.png
       :alt:

    .. image:: ../../../../../samples/opener/blinky/doc/Twincat_ethernet_driver_2.png
       :alt:

  2. Clock setting

    When the software is running, the following error may be encountered: It is necessary to run C:\TwinCAT\3.1\System\win8settick.bat with administrator privileges.
      - - -

      *Init4\RTime：Start Interrupt：Ticker started >> AdsWarning4115 （0x1013,RTIME：system clock setup failed）*
      - - -

      .. image:: ../../../../../samples/opener/blinky/doc/Twincat_set_tick.png
         :alt:

Add EIP Scanner
~~~~~~~~~~~~~~~~~~~

  1. Click on Device, right-click to add a new item.

    .. image:: ../../../../../samples/opener/blinky/doc/add_new_interface.png
       :alt:

  2. Select EIP Scanner.

    .. image:: ../../../../../samples/opener/blinky/doc/seclet_new_interface.png
       :alt:

  3. Select the network card after the driver is updated.

    .. image:: ../../../../../samples/opener/blinky/doc/seclet_local_interface.png
       :alt:

  4. Configure the IP address.

    .. image:: ../../../../../samples/opener/blinky/doc/set_ip_address.png
       :alt:

  5. Re-enter the configuration mode to make the IP configuration in the previous step take effect.

    .. image:: ../../../../../samples/opener/blinky/doc/reenter_config_mode.png
       :alt:

Add EDS file
~~~~~~~~~~~~~~~~~

  Right-click on EIP Scanner and select import EDS file. Select opener/opener_blinky_app.eds.

    .. image:: ../../../../../samples/opener/blinky/doc/import_eds_file.png
       :alt:

Scan devices
~~~~~~~~~~~~~~~~~

  1. Right-click on EIP Scanner and then scan.

    .. image:: ../../../../../samples/opener/blinky/doc/scan.png
       :alt:

  2. Add a device.

    .. image:: ../../../../../samples/opener/blinky/doc/found_new_device.png
       :alt:

Add IO connection
~~~~~~~~~~~~~~~~~~~~~

  .. image:: ../../../../../samples/opener/blinky/doc/add_io_connection.png
     :alt:

  If there is no `Exclusive Owner` is the combox, specify the eds file manually.

  .. image:: ../../../../../samples/opener/blinky/doc/load_from_eds.jpg
     :alt:

IO operation
~~~~~~~~~~~~~~~~

  1. For input IO, press the button KEYA on the evaluation board, and the value of Input/Key State changes.

    .. image:: ../../../../../samples/opener/blinky/doc/keystate.png
       :alt:

  2. For output IO, right-click on Led State, select Online, and click Write to write a value. When writing 1, the LED on the development board lights up. When writing 0, the LED on the development board turns off.

    .. image:: ../../../../../samples/opener/blinky/doc/ledstate.png
       :alt:

Operation phenomenon
-----------------------

After the project runs correctly, the serial terminal will output the following information. The input and output IO states correspond to the TwinCAT project configuration:

.. code-block:: console

   This is Ethernet/IP blinky demo.
   LwIP Version: 2.1.2
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

