/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2025/05/07
 * Description        : Main program body for V3F.
 *********************************************************************************
 * Copyright (c) 2025 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
/*
 *@Note
  Example routine to emulate a custom USB device (CH372 device).
  This routine demonstrates the use of a USBSS Device to emulate a custom device, the CH372,
  with endpoints 1/2 downlinking data and uploading via endpoints 2/1 respectively
  Endpoints 3 and 4 upload and download data separately respectively.
  The device can be operated using Bushund or other upper computer software.
  Note: This routine needs to be demonstrated in conjunction with the host software.

  If the USB is set to high-speed, an external crystal oscillator is recommended for the clock source.
*/

#include "debug.h"
#include "hardware.h"
#include "ch32h417_usbss_device.h"
#include "ch32h417_usbhs_device.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    SystemAndCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(921600);

	printf("SystemClk:%d\r\n", SystemClock);
	printf("V3F SystemCoreClk:%d\r\n", SystemCoreClock);
    printf("CH372Device Running On USBSS Controller\n");

#if (Run_Core == Run_Core_V3FandV5F)
    NVIC_WakeUp_V5F(Core_V5F_StartAddr);//wake up V5
    HSEM_ITConfig(HSEM_ID0, ENABLE);
    NVIC->SCTLR |= 1<<4;
    PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFE);
    HSEM_ClearFlag(HSEM_ID0);
    printf("V3F wake up\r\n");

    Hardware();

#elif (Run_Core == Run_Core_V3F)
    Hardware();

#elif (Run_Core == Run_Core_V5F)
    NVIC_WakeUp_V5F(Core_V5F_StartAddr);//wake up V5
    PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFE);
    printf("V3F wake up\r\n");
#endif

    while(1)
    {

    }

}
