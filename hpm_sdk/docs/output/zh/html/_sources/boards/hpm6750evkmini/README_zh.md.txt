# HPM6750EVKMINI开发板

## 概述

HPM6750是一款主频达816Mhz的双核微控制器。该芯片拥有最大2M字节的连续片上RAM，并集成了丰富的存储接口，如SDRAM，Quad SPI NOR flash， SD/eMMC卡。同时它也提供多种音视频接口包括LCD显示，像素DMA，摄像头以及I2S音频接口。

 ![hpm6750evkmini](doc/hpm6750evkmini.png "hpm6750evkmini")

## 板上硬件资源

- HPM6750IVM 微控制器 (主频816Mhz, 2MB片上内存)
- 板载存储
  - 128Mb SDRAM
  - 64Mb Quad SPI NOR Flash
- 显示/摄像头
  - LCD接口
  - 摄像头(DVP)接口
- WiFi
  - RW007
- USB
  - USB type C (USB 2.0 OTG) connector x2
- 音频
  - Mic
  - DAO
- 其他
  - TF卡槽
  - FT2232
  - 蜂鸣器
  - RGB LED
- 扩展口
  - ART-PI

## 拨码开关 S1

- Bit 1，2控制启动模式

| Bit[2:1] | 功能描述                |
| -------- | ----------------------- |
| OFF, OFF | Quad SPI NOR flash 启动 |
| OFF, ON  | 串行启动                |
| ON, OFF  | 在系统编程              |

(lab_hpm6750_evkmini_board)=

## 按键

(lab_hpm6750_evkmini_board_buttons)=

| 名称       | 功能                                  |
| ---------- | ------------------------------------- |
| PBUTN (S2) | 电源按键, TinyUF2 Boot按键, GPIO 按键 |
| WBUTN (S3) | WAKE UP 按键                          |
| RESET (S4) | Reset 按键                            |

## 引脚描述

- SPI引脚：

| 功能      | 位置   |
| --------- | ------ |
| SPI2.CSN  | P1[24] |
| SPI2.SCLK | P1[23] |
| SPI2.MISO | P1[21] |
| SPI2.MOSI | P1[19] |

- I2C引脚：

| 功能     | 位置   |
| -------- | ------ |
| I2C0.SCL | P1[13] |
| I2C0.SDA | P1[15] |

- ACMP引脚

| 功能       | 位置   |
| ---------- | ------ |
| CMP.INN6   | P2[11] |
| CMP.COMP_1 | P1[7]  |

- GPTMR引脚

| 功能          | 位置   |  备注 |
| ------------- | ------ | ------ |
| GPTMR5.CAPT_1 | P1[12] |
| GPTMR5.COMP_0 | P1[31] | SPI模拟I2S的MCLK |
| GPTMR5.COMP_1 | P1[35] | SPI模拟I2S的LRCK |
| GPTMR5.COMP_2 | P2[38] | SPI模拟I2S的BLCK |

- ADC12引脚

| 功能              | 位置   |
| ----------------- | ------ |
| ADC12参考电压设置 | 无     |
| ADC0.VINP14       | P1[33] |

- ADC16引脚

| 功能              | 位置   |
| ----------------- | ------ |
| ADC16参考电压设置 | 无     |
| ADC3.INA2         | P1[16] |

- PWM引脚

| 功能    | 位置   |
| ------- | ------ |
| PWM0.P4 | P1[29] |
| PWM0.P5 | P1[32] |

- DAO接口

| 功能     | 位置 |
| -------- | ---- |
| 喇叭接口 | J2   |

- I2S引脚

| 功能      | 位置   |
| --------- | ------ |
| I2S0.FCLK | P1[35] |
| I2S0.BCLK | P1[12] |
| I2S0.RXD1 | P1[38] |
| I2S0.TXD1 | P1[40] |
| GND       | P1[39] |

- 以太网PPS信号引脚

| 功能        | 引脚 | 位置   |
| ----------- | ---- | ------ |
| ENET0.EVTO0 | PF05 | P1[38] |
| ENET0.EVTO1 | PF06 | P1[12] |
| ENET0.EVTO2 | PF09 | P1[35] |
| ENET0.EVTI0 | PF00 | P1[26] |
| ENET0.EVTI1 | PF01 | P1[27] |
| ENET0.EVTI2 | PF02 | P1[28] |

- UART13引脚

 UART13用于CORE1调试串口或一些使用UART的功能测试，例如uart_software_rx_idle，uart_rx_timeout，uart_software_lin，MICROROS_UART，USB_CDC_ACM_UART, MODBUS_RTU等。

| 功能       | 位置   | 备注     |
| ---------- | ------ |  ------ |
| UART13.TXD | P1[8] |
| UART13.RXD | P1[10] |
| UART13.RXD | P1[24] | 产生uart break信号|

- TRGMUX引脚用于uart_software_rx_idle工程

| 功能        | 位置    |
| ---------- | -------- |
| TRGM2_P9(PD19)  | P2[35]   |

- 电机引脚

  参考 [HPM6750EVKMINI-TO-MOTOR扩展板章节](lab_board_hpm6750evkmini-to-motor-220530RevA) 进行连接

- Tamper 接口

| 功能     | 引脚   | 位置   |  模式   |
|----------|--------|--------|--------|
| TAMP.08  | PZ08   | P1[10] | 主动模式 |
| TAMP.09  | PZ09   | P1[8]  | 主动模式 |
| TAMP.10  | PZ10   | P1[22] | 被动模式 |

- SPI模拟I2S CS引脚

| 功能 | 位置   |  备注 |
| ---- | ----- | ------ |
| PD25  | P2[40] | 控制SPI从机CS的引脚 |


## 已知问题：
- 一些例程在运行过程中有可能会进入trap handler，同时mcause为2（指令错误），这是由于ILM的缺陷导致的，详见《勘误手册E00001》。
  - 处理办法：将链接脚本中的ILM接口地址改为ILM_SLV地址。
