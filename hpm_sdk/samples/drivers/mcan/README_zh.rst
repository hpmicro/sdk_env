.. _mcan:

MCAN
========

概述
------

mcan_demo 例程提供如下功能：
- SoC支持的所有CAN外设的回环测试，主要集中在CAN和CAN-FD测试

- 开发板所支持的CAN外设的回环测试，基于中断模式

- 双板之间的回声（Echo）测试

- 用于检测CAN总线连接性的多包发送

- RXBUF测试

- 过滤器测试

- 时间戳测试

硬件设置
------------

无特殊设置

运行现象
------------

当该例程成功运行后，会在串口终端打印如下菜单:


.. code-block:: console

   *******************************************************************************
   *                                                                             *
   *                         CAN Example Menu                                    *
   *                                                                             *
   * 0 - Run loopback test for all supported CAN controllers (CAN and CANFD)     *
   * 1 - Run loopback test for board supported CAN controller (interrupt mode)   *
   * 2 - Echo test between two board:initiator                                   *
   * 3 - Echo test between two board:responder                                   *
   * 4 - Send multiple classic CAN messages for transmission check               *
   * 5 - Send multiple CANFD messages for transmission check                     *
   * 6 - CAN error test (Need to remove current node from CAN BUS for this test) *
   * 7 - CAN filter test                                                         *
   * 8 - CAN RXBUF test                                                          *
   * 9 - CAN TX EVENT FIFO test                                                  *
   * a - CAN Timestamp Test                                                      *
   * b - CAN timeout counter Test                                                *
   * c - CAN TXBUF cancellation Test                                             *
   *                                                                             *
   *******************************************************************************


注意事项:
~~~~~~~~~~~~~

- 对于菜单选项 0 或 1, 用户可以直接在串口终端输入0 或 1 来启

- 对于菜单选项 2 和 3， 用户必须连接两块开发板，并在两个开发板上同时运行该例程。然后先启动响应者（responder），再启动发起者（initiator）

- 对于菜单选项 4, 用户需确认开发板挂载到有效的CAN总线上。 如果开发板连接在CAN分析仪上，用户可以通过CAN分析仪观测到开发板在运行该选项后发送了多包数据
