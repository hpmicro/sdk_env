# OpENer Blinky

## 1.Overview

The OpENer Blinky example is used to demonstrate the function of realizing remote IO through the Ethernet/IP (EIP) protocol using OpENer.
## 2.Preparation
### 2.1 Hardware

  - A development board with Ethernet. Refer to the {ref}pin description <lab_board_resource> of the specific development board to view the Ethernet hardware.
    - ==According to your development board, select RMII/RGMII and ethernet phy in the CMakeLists.txt==
  - A PC with a network port.
    - The TwinCAT3 software has adaptation issues with PC network cards. Some supported Intel network cards.

### 2.2 Software
  - TwinCAT3.1(Build 4024.56)

## 3. TwinCAT project settings

### 3.1 Create a project
  1. Open the TwinCAT software and select File -> New -> Project.
    ![](doc/Twincat_new_project_1.png)
  2. Select TwinCAT Project, name it and click OK.
    ![](doc/Twincat_new_project_2.png)

### 3.2 Software configuration
  1. Update the network card driver (required when using for the first time).
    ![](doc/Twincat_ethernet_driver.png)
    ![](doc/Twincat_ethernet_driver_2.png)
  2. Clock setting
    When the software is running, the following error may be encountered: It is necessary to run C:\TwinCAT\3.1\System\win8settick.bat with administrator privileges.
      - - -
      *Init4\RTime：Start Interrupt：Ticker started >> AdsWarning4115 （0x1013,RTIME：system clock setup failed）*
      - - -
      ![](doc/Twincat_set_tick.png)

### 3.3 Add EIP Scanner
  1. Click on Device, right-click to add a new item.
    ![](doc/add_new_interface.png)
  2. Select EIP Scanner.
    ![](doc/seclet_new_interface.png)
  3. Select the network card after the driver is updated.
    ![](doc/seclet_local_interface.png)
  4. Configure the IP address.
    ![](doc/set_ip_address.png)
  5. Re-enter the configuration mode to make the IP configuration in the previous step take effect.
    ![](doc/reenter_config_mode.png)

### 3.4. Add EDS file
  Right-click on EIP Scanner and select import EDS file. Select opener/opener_blinky_app.eds.
    ![](doc/import_eds_file.png)

### 3.5. Scan devices
  1. Right-click on EIP Scanner and then scan.
    ![](doc/scan.png)
  2. Add a device.
    ![](doc/found_new_device.png)

### 3.6 Add IO connection
  ![](doc/add_io_connection.png)
  If there is no `Exclusive Owner` is the combox, specify the eds file manually.
  ![](doc/load_from_eds.jpg)

### 3.7 IO operation
  1. For input IO, press the button KEYA on the evaluation board, and the value of Input/Key State changes.
    ![](doc/keystate.png)
  2. For output IO, right-click on Led State, select Online, and click Write to write a value. When writing 1, the LED on the development board lights up. When writing 0, the LED on the development board turns off.
    ![](doc/ledstate.png)

## 4. Operation phenomenon

After the project runs correctly, the serial terminal will output the following information. The input and output IO states correspond to the TwinCAT project configuration:
```console
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
```