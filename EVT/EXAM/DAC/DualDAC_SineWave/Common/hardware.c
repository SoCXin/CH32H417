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

/* Global define */
#define Num 64

/* Global Variable */ 
uint32_t DAC_Value[Num]={2048,2248,2447,2642,2831,3013,3185,3347,3496,3631,3750,3854,3940,4007,4056,4086,
                         4095,4086,4056,4007,3940,3854,3750,3631,3496,3347,3185,3013,2831,2642,2447,2248,
                         2048,1847,1648,1453,1264,1082,910 ,748 ,599 ,464 ,345 ,241 ,155 ,88  ,39  ,9   ,
                         0   ,9   ,39  ,88  ,155 ,241 ,345 ,464 ,599 ,748 ,910 ,1082,1264,1453,1648,1847};

uint32_t Dual_DAC_Value[Num];

/*********************************************************************
 * @fn      Dac_Init
 *
 * @brief   Initializes DAC collection.
 *
 * @return  none
 */
void Dac_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    DAC_InitTypeDef  DAC_InitType = {0};

    RCC_HB2PeriphClockCmd(RCC_HB2Periph_GPIOA, ENABLE);
    RCC_HB1PeriphClockCmd(RCC_HB1Periph_DAC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

	DAC_InitType.DAC_Trigger=DAC_Trigger_T4_TRGO;
	DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_None;
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;
	DAC_InitType.DAC_OutputBuffer=DAC_OutputBuffer_Disable ;
    DAC_Init(DAC_Channel_1,&DAC_InitType);
    DAC_Init(DAC_Channel_2,&DAC_InitType);

    DAC_Cmd(DAC_Channel_1, ENABLE);
    DAC_Cmd(DAC_Channel_2, ENABLE);

    DAC_DMACmd(DAC_Channel_1,ENABLE);
    DAC_DMACmd(DAC_Channel_2,ENABLE);

    DAC_SetDualChannelData(DAC_Align_12b_R, 0x123,0x321);
}
/*********************************************************************
 * @fn      DAC1_DMA_INIT
 *
 * @brief   Initializes DMA of DAC1 collection.
 *
 * @return  none
 */
void Dac_Dma_Init(void)
{
    DMA_InitTypeDef DMA_InitStructure={0};
    RCC_HBPeriphClockCmd(RCC_HBPeriph_DMA2, ENABLE);

    DMA_StructInit( &DMA_InitStructure);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(DAC->RD12BDHR);
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&Dual_DAC_Value[0];
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = Num;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

    DMA_Init(DMA2_Channel3, &DMA_InitStructure);
    DMA_Cmd(DMA2_Channel3, ENABLE);

}

/*********************************************************************
 * @fn      Timer4_Init
 *
 * @brief   Initializes TIM4
 *
 * @return  none
 */
void Timer4_Init(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure={0};
    RCC_HB1PeriphClockCmd(RCC_HB1Periph_TIM4, ENABLE);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = 3600-1;
    TIM_TimeBaseStructure.TIM_Prescaler =0;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    TIM_SelectOutputTrigger(TIM4, TIM_TRGOSource_Update);
    TIM_Cmd(TIM4, ENABLE);
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
    u8 i = 0;
    printf("Noise Wava Generation Test\r\n");
    Dac_Init();
    Dac_Dma_Init();
    DMA_MuxChannelConfig(DMA_MuxChannel10, 0x67); 
    Timer4_Init();
	for(i=0;i<Num;i++)
	{
	    Dual_DAC_Value[i]=(DAC_Value[i]<<16) + DAC_Value[i];
	    printf("0x%08x\r\n",Dual_DAC_Value[i]);
	}
    while(1)
    {
       printf("CNT=%d\r\n",TIM4->CNT);
        printf("RD12BDHR=0x%04x\r\n",DAC->RD12BDHR);
        printf("DOR1=0x%04x\r\n",DAC->DOR1);
        printf("DOR2=0x%04x\r\n",DAC->DOR2);
        Delay_Ms(500);
    }
}
