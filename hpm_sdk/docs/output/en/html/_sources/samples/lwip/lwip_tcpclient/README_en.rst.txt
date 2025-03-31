﻿.. _lwip_tcpclient:

lwip_tcpclient
============================

Overview
--------

This example shows the usage of TCP client.

- MCU as TCP client sends data frame periodically to a TCP server.

Board Settings
--------------

- Connect a USB port on PC to the PWR DEBUG port on the development board with a USB Type-C cable

- Connect an Ethernet port on PC to a RGMII port or a RMII port on the development board with an Ethernet cable

Project Configurations
----------------------

- Ethernet Port Settings: Refer to :ref:`Ethernet common project settings <ethernet_port_configurations_en>`

- Ethernet DHCP Configurations

  - the configurations in the `CMakeLists.txt` as follows:

    - sdk_compile_definitions(-DLWIP_DHCP=0): Disable DHCP feature

    - sdk_compile_definitions(-DLWIP_DHCP=1): Enable DHCP feature

Run Example
-----------

- Compiling and Downloading

- Running log is shown in the serial terminal as follows:


  .. code-block:: console

     This is an ethernet demo: TCP Client (Polling Usage)
     LwIP Version: 2.1.2
     Enet phy init passed !
     Link Status: Up
     Link Speed:  1000Mbps
     Link Duplex: Full duplex
     IPv4 Address: 192.168.100.10
     IPv4 Netmask: 255.255.255.0
     IPv4 Gateway: 192.168.100.1
     Connect to server successfully!


- Run an Ethernet debugging tool

  - Create and set a TCP Server:  TCP Server IP: 192.168.100.5/Port: 5001

  - Open

  - Watch the data frame in the receive window

    .. image:: ../../../../../samples/lwip/doc/lwip_tcpclient.png
