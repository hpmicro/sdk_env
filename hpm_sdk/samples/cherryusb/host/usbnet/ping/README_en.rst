.. _rndis_host_ping:

RNDIS Host - PING
==================================

Overview
--------

- the sample shows the USB RNDIS Host is connected to luat 4G module (air780e module) or ec20 module to network and ping communication

Board Setting
-------------

- development board interconnected to air780e or ec20 module through port USB0.

- development board(RNDIS Host) DEBUG port or console port connect to PC.

Example of output log
---------------------

- download the programs to the development board, and connect air780e, the board will show logs as follows

- if not, check whether the upper module is powered on


.. code-block:: console

   Start rndis host ping task...
   [I/USB] EHCI HCIVERSION:0100
   [I/USB] EHCI HCSPARAMS:010011
   [I/USB] EHCI HCCPARAMS:0006
   [I/USB] New high-speed device on Hub 1, Port 1 connected
   [I/USB] New device found,idVendor:19d1,idProduct:0001,bcdDevice:0200
   [I/USB] The device has 8 interfaces
   [I/USB] Enumeration success, start loading class driver
   [I/USB] Loading rndis class driver
   [I/USB] Ep=01 Attr=02 Mps=512 Interval=00 Mult=00
   [I/USB] Ep=82 Attr=02 Mps=512 Interval=00 Mult=00
   [I/USB] rndis init success
   [I/USB] rndis query OID_GEN_SUPPORTED_LIST success,oid num :22
   [W/USB] Ignore rndis query iod:00010101
   [W/USB] Ignore rndis query iod:00010102
   [W/USB] Ignore rndis query iod:00010103
   [W/USB] Ignore rndis query iod:00010104
   [I/USB] rndis query iod:00010106 success
   [I/USB] rndis query iod:00010107 success
   [W/USB] Ignore rndis query iod:0001010a
   [W/USB] Ignore rndis query iod:0001010b
   [W/USB] Ignore rndis query iod:0001010c
   [W/USB] Ignore rndis query iod:0001010d
   [W/USB] Ignore rndis query iod:00010116
   [W/USB] Ignore rndis query iod:0001010e
   [W/USB] Ignore rndis query iod:00010111
   [W/USB] Ignore rndis query iod:00010112
   [W/USB] Ignore rndis query iod:00010113
   [I/USB] rndis query iod:00010114 success
   [W/USB] Ignore rndis query iod:00010115
   [I/USB] rndis query iod:01010101 success
   [I/USB] rndis query iod:01010102 success
   [W/USB] Ignore rndis query iod:01010103
   [I/USB] rndis query iod:01010104 success
   [W/USB] Ignore rndis query iod:01010105
   [I/USB] rndis set OID_GEN_CURRENT_PACKET_FILTER success
   [I/USB] rndis set OID_802_3_MULTICAST_LIST success
   [I/USB] Register RNDIS Class:/dev/rndis
   [E/USB] do not support Class:0x0a,Subclass:0x00,Protocl:0x00
   [E/USB] do not support Class:0x02,Subclass:0x02,Protocl:0x01
   [E/USB] do not support Class:0x0a,Subclass:0x00,Protocl:0x00
   [E/USB] do not support Class:0x02,Subclass:0x02,Protocl:0x01
   [E/USB] do not support Class:0x0a,Subclass:0x00,Protocl:0x00
   [E/USB] do not support Class:0x02,Subclass:0x02,Protocl:0x01
   [E/USB] do not support Class:0x0a,Subclass:0x00,Protocl:0x00

   *********************************************************************************

   input ping the IP or URL address and press the enter key to end

   if want to terminate midway, please press the esc key

   *********************************************************************************

    IPv4 Address     : 192.168.10.2
    IPv4 Subnet mask : 255.255.255.0
    IPv4 Gateway     : 192.168.10.1


- when the EC20 module is connected, the following information is printed, indicating that the EC20 initialization is successful and the IP is assigned.


.. code-block:: console

   [I/USB] EHCI HCIVERSION:0100
   [I/USB] EHCI HCSPARAMS:010011
   [I/USB] EHCI HCCPARAMS:0006
   [I/USB] New high-speed device on Hub 1, Port 1 connected
   [I/USB] New device found,idVendor:2c7c,idProduct:0125,bcdDevice:0318
   [I/USB] The device has 6 interfaces
   [I/USB] Enumeration success, start loading class driver
   [E/USB] do not support Class:0xff,Subclass:0xff,Protocl:0xff
   [E/USB] do not support Class:0xff,Subclass:0x00,Protocl:0x00
   [E/USB] do not support Class:0xff,Subclass:0x00,Protocl:0x00
   [E/USB] do not support Class:0xff,Subclass:0x00,Protocl:0x00
   [I/USB] Loading cdc_ecm class driver
   [I/USB] CDC ECM mac address 9e: 28: 59: e0: 00: 00
   [I/USB] CDC ECM Max Segment Size:1280
   [I/USB] Ep=89 Attr=03 Mps=16 Interval=09 Mult=00
   [I/USB] Ep=88 Attr=02 Mps=512 Interval=00 Mult=00
   [I/USB] Ep=05 Attr=02 Mps=512 Interval=00 Mult=00
   [I/USB] Select cdc ecm altsetting: 1
   [I/USB] Set CDC ECM packet filter:000c
   [I/USB] Register CDC ECM Class:/dev/cdc_ether
   [E/USB] do not support Class:0x0a,Subclass:0x00,Protocl:0x00

   *********************************************************************************

   input ping the IP or URL address and press the enter key to end

   if want to terminate midway, please press the esc key

   *********************************************************************************

    IPv4 Address     : 192.168.225.27
    IPv4 Subnet mask : 255.255.255.0
    IPv4 Gateway     : 192.168.225.1


- after that, need to enter the IP addrees or domain name to be ping, and press enter key when done

- for example: www.baidu.com


.. code-block:: console

   Pinging www.baidu.com [120.232.145.144] ..................
   from 120.232.145.144 bytes=60 icmp_seq=0 ttl=52 time=53 ms
   from 120.232.145.144 bytes=60 icmp_seq=1 ttl=52 time=77 ms
   from 120.232.145.144 bytes=60 icmp_seq=2 ttl=52 time=91 ms
   from 120.232.145.144 bytes=60 icmp_seq=3 ttl=52 time=104 ms
   from 120.232.145.144 bytes=60 icmp_seq=4 ttl=52 time=82 ms

