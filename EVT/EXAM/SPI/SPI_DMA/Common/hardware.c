/********************************** (C) COPYRIGHT  *******************************
* File Name          : hardware.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2025/03/01
* Description        : This file provides all the CRC firmware functions.
*********************************************************************************
* Copyright (c) 2025 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#include "hardware.h"
#include "string.h"



/* SPI Mode Definition */
#define HOST_MODE  0
#define SLAVE_MODE 1

/* SPI Communication Mode Selection */
#define SPI_MODE   HOST_MODE
// #define SPI_MODE   SLAVE_MODE

/* Global define */
#define Size       18

/* Global Variable */
u16 TxData[Size] = {0x0101, 0x0202, 0x0303, 0x0404, 0x0505, 0x0606,
                    0x1111, 0x1212, 0x1313, 0x1414, 0x1515, 0x1616,
                    0x2121, 0x2222, 0x2323, 0x2424, 0x2525, 0x2626};
u16 RxData[Size];

/*********************************************************************
 * @fn      SPI_FullDuplex_Init
 *
 * @brief   Configuring the SPI for full-duplex communication.
 *
 * @return  none
 */
void SPI_FullDuplex_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    SPI_InitTypeDef  SPI_InitStructure  = {0};

    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOB | RCC_HB2Periph_GPIOC, ENABLE);
    RCC_HB1PeriphClockCmd(RCC_HB1Periph_SPI2, ENABLE);

#if (SPI_MODE == HOST_MODE)

    // SCK PB13(AF5)
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // MOSI PC1(AF5)
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource1, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // MISO PC2(AF5)
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
#elif (SPI_MODE == SLAVE_MODE)

    // SCK PB13(AF5)
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // MOSI PC1(AF5)
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource1, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // MISO PC2(AF5)
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF5);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

#endif

    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;

#if (SPI_MODE == HOST_MODE)
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;

#elif (SPI_MODE == SLAVE_MODE)
    SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;

#endif

    SPI_InitStructure.SPI_DataSize          = SPI_DataSize_16b;
    SPI_InitStructure.SPI_CPOL              = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA              = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS               = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_Mode6;
    SPI_InitStructure.SPI_FirstBit          = SPI_FirstBit_LSB;
    SPI_InitStructure.SPI_CRCPolynomial     = 7;
    SPI_Init(SPI2, &SPI_InitStructure);




    SPI_Cmd(SPI2, ENABLE);
}

/*********************************************************************
 * @fn      DMA_Tx_Init
 *
 * @brief   Initializes the DMAy Channelx configuration.
 *
 * @param   DMA_CHx - x can be 1 to 7.
 *          ppadr - Peripheral base address.
 *          memadr - Memory base address.
 *          bufsize - DMA channel buffer size.
 *
 * @return  none
 */
void DMA_Tx_Init(DMA_Channel_TypeDef* DMA_CHx, u32 ppadr, u32 memadr, u16 bufsize)
{
    DMA_InitTypeDef DMA_InitStructure = {0};

    RCC_HBPeriphClockCmd(RCC_HBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA_CHx);

    DMA_InitStructure.DMA_PeripheralBaseAddr = ppadr;
    DMA_InitStructure.DMA_Memory0BaseAddr    = memadr;
    DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize         = bufsize;
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority           = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_M2M                = DMA_M2M_Disable;
    DMA_Init(DMA_CHx, &DMA_InitStructure);
}

/*********************************************************************
 * @fn      DMA_Rx_Init
 *
 * @brief   Initializes the SPI2 DMA Channelx configuration.
 *
 * @param   DMA_CHx - x can be 1 to 7.
 *          ppadr - Peripheral base address.
 *          memadr - Memory base address.
 *          bufsize - DMA channel buffer size.
 *
 * @return  none
 */
void DMA_Rx_Init(DMA_Channel_TypeDef* DMA_CHx, u32 ppadr, u32 memadr, u16 bufsize)
{
    DMA_InitTypeDef DMA_InitStructure = {0};

    RCC_HBPeriphClockCmd(RCC_HBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA_CHx);

    DMA_InitStructure.DMA_PeripheralBaseAddr = ppadr;
    DMA_InitStructure.DMA_Memory0BaseAddr    = memadr;
    DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize         = bufsize;
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority           = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M                = DMA_M2M_Disable;
    DMA_Init(DMA_CHx, &DMA_InitStructure);
}

/*********************************************************************
 * @fn      Hardware
 *
 * @brief   Resets the CRC Data register (DR).
 *
 * @return  none
 */
void Hardware(void)
{
    uint32_t i = 0;
#if (SPI_MODE == SLAVE_MODE)
    printf("Slave Mode\r\n");
    Delay_Ms(1000);

#endif

    SPI_FullDuplex_Init();


#if (SPI_MODE == HOST_MODE)
    printf("Host Mode\r\n");
    Delay_Ms(2000);
#endif

    DMA_Tx_Init(DMA1_Channel3, (u32)&SPI2->DATAR, (u32)TxData, Size);
    DMA_Rx_Init(DMA1_Channel2, (u32)&SPI2->DATAR, (u32)RxData, Size);

    DMA_MuxChannelConfig(DMA_MuxChannel3, 65);
    DMA_MuxChannelConfig(DMA_MuxChannel2, 66);

    SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Tx, ENABLE);
    SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Rx, ENABLE);
    DMA_Cmd(DMA1_Channel3, ENABLE);
    DMA_Cmd(DMA1_Channel2, ENABLE);

    while (1)
    {

        while ((!DMA_GetFlagStatus(DMA1, DMA1_FLAG_TC2)) && (!DMA_GetFlagStatus(DMA1, DMA1_FLAG_TC3)))
            ;

        for (i = 0; i < Size; i++)
        {
            printf(" RxData:%04x\r\n", RxData[i]);
        }

        while (1)
            ;
    }
    while (1)
        ;
}
