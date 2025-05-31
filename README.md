# [CH32H417](https://github.com/SoCXin/CH32H417)

* [WCH](http://www.wch.cn/)：[RISC-V](https://github.com/SoCXin/RISC-V)
* [L3R3](https://github.com/SoCXin/Level): 400+144 MHz 

## [简介](https://github.com/SoCXin/CH32H417/wiki)

[CH32H417](https://www.wch.cn/products/CH32H417.html) 是基于青稞RISC-V5F和RISC-V3F双内核设计的互联型通用微控制器。CH32H417集成了USB 3.2 Gen1控制器和收发器、百兆以太网MAC及PHY、SerDes高速隔离收发器、Type-C/PD控制器及PHY，提供SD/EMMC控制器、500MBytes通用高速接口UHSIF、DVP数字图像接口、单线协议主接口SWPMI、可编程协议I/O控制器PIOC、灵活存储控制器FMC、DFSDM、LTDC、GPHA、DMA控制器、多组定时器、8组串口、I3C、4组I2C、2组QSPI、4组SPI，2组I2S、3组CAN等外设资源，内置了5M采样率双12位ADC单元、20M采样率10位高速HSADC单元、16路Touchkey、双DAC单元、3组运放OPA、电压比较器CMP等模拟资源，支持10M/100M以太网通讯，支持USB 2.0和USB 3.0，支持USB Host主机和USB Device设备功能、Type-C和PDUSB快充功能，支持SerDes高速隔离及远距离传输，支持双内核分工提升网络协议处理效率和通讯响应速度。

``` mermaid
gantt
    title CH32H417 SDK
    dateFormat  YYYY-MM-DD
    section Mainline Release
    v1.0           :a1, 2025-05-28, 2025-09-30
```

### 关键特性

* 双内核结构：青稞RISC-V5F和RISC-V3F
* V5F最高频率400MHz，V3F最高频率144MHz
* 896KB SRAM，960KB Flash
* 系统供电额定3.3V
* 常规GPIO供电额定3.3V，支持1.8V
* 高速GPIO供电可选1.2/1.8/2.5/3.3V
* 2组共16路通用DMA控制器
* 2组12位模数转换ADC，采样速率高达5Msps，支持双ADC转换模式
* 1组10位高速模数转换HSADC，采样速率高达20Msps
* 16路TouchKey通道检测
* 2组12位数模转换DAC
* 32位宽度125MHz通用高速接口UHSIF
* 144MHz数字图像接口DVP
* 200MHz双沿SD/EMMC控制器（SDMMC）
* SDIO主机/从机接口：支持SD/SDIO/MMC口
* 单线协议主接口SWPMI
* 可编程协议I/O控制器PIOC
* 以太网控制器MAC及10M/100M PHY
* 5Gbps超高速USB 3.0控制器及PHY
* 480Mbps高速USB 2.0控制器及PHY
* 全速USB 2.0控制器及PHY
* 远距离SerDes控制器及PHY，支持千伏级高压信号隔离传输
* USB PD和Type-C控制器及PHY
* 1组模拟电压比较器CMP
* 3组运放OPA/PGA/电压比较器
* 2个16位高级定时器，4个16位和4个32 位通用定时器
* 2个16位基本定时器，2个16位低功耗定时器
* 2个看门狗定时器：独立和窗口型，2个32位系统时基定时器
* 8组USART串口、4组I2C接口、1组I3C接口
* 4组SPI接口、2组QuadSPI接口、3组CAN接口（2.0B主动）
* 数字滤波器，用于ΣΔ调制器DFSDM
* 串行音频接口SAI
* DCT-TFT显示控制器LTDC
* 图形处理硬件加速器GPHA
* 灵活存储控制器FMC
* 95个I/O,映射16个外部中断
* ECDC加密模块
* 支持单线（默认）和双线两种调试模式
* 封装形式：QFN128、QFN88、QFN68、QFN60X6

## [资源收录](https://github.com/SoCXin)

* [参考资源](src/)
* [参考文档](docs/)
* [参考工程](project/)
* [mounriver开发环境](http://www.mounriver.com/download)

## [选型建议](https://github.com/SoCXin)

[CH32H417](https://github.com/SoCXin/CH32H417) 
