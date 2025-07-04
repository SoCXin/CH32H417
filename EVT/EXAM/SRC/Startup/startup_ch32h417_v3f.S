/********************************** (C) COPYRIGHT *******************************
* File Name          : startup_ch32h417_v3f.s
* Author             : WCH
* Version            : V1.0.0
* Date               : 2025/03/01
* Description        : CH32h417 vector table t0 V3F for eclipse toolchain.
*********************************************************************************
* Copyright (c) 2025 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

	.section	.init,"ax",@progbits
	.global	_start
	.align	2
_start:
	j	handle_reset
    .section    .vector,"ax",@progbits
    .align  1
_vector_base:
    .option norvc;
    .word   _start
    .word   0
    .word   NMI_Handler              
    .word   HardFault_Handler         
    .word   0x00FFFFFF   //UART-enable USBHS-enable USBSS-enable /**/
    /*.word   0x06FFFFF9   //UART-enable USBHS-Disable USBSS-disable */
    /*.word   0x05FFFFFA   //UART-Disable USBHS-enable USBSS-disable */
    /*.word   0x03FFFFFC   //UART-Disable USBHS-disable USBSS-enable */
    /*.word   0x04FFFFFB   //UART-enable USBHS-enable USBSS-disable */
    /*.word   0x01FFFFFE   //UART-disable USBHS-enable USBSS-enable */
    /*.word   0x02FFFFFD   //UART-enable USBHS-Disable USBSS-enable */
    .word   Ecall_M_Mode_Handler      
    .word   0
    .word   0
    .word   Ecall_U_Mode_Handler      
    .word   Break_Point_Handler      
    .word   0
    .word   0
    .word   SysTick0_Handler          
    .word   SysTick1_Handler           
    .word   SW_Handler
    .word   0
    .word   IPC_CH0_Handler          
    .word   IPC_CH1_Handler          
    .word   IPC_CH2_Handler          
    .word   IPC_CH3_Handler          
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   HSEM_Handler
    .word   0
    .word   0
    .word   0
    /* External Interrupts */
    .word   WWDG_IRQHandler            
    .word   EXTI15_8_IRQHandler         
    .word   FLASH_IRQHandler         
    .word   RCC_IRQHandler   
    .word   EXTI7_0_IRQHandler          
    .word   SPI1_IRQHandler           
    .word   DMA1_Channel2_IRQHandler   
    .word   DMA1_Channel3_IRQHandler   
    .word   DMA1_Channel4_IRQHandler   
    .word   DMA1_Channel5_IRQHandler  
    .word   DMA1_Channel6_IRQHandler   
    .word   DMA1_Channel7_IRQHandler   
    .word   DMA1_Channel8_IRQHandler  
    .word   USART2_IRQHandler          
    .word   I2C1_EV_IRQHandler        
    .word   I2C1_ER_IRQHandler         
    .word   USART1_IRQHandler          
    .word   SPI2_IRQHandler           
    .word   SPI3_IRQHandler            
    .word   SPI4_IRQHandler           
    .word   I2C2_EV_IRQHandler      
    .word   I2C2_ER_IRQHandler         
    .word   USBPD_IRQHandler        
    .word   USBPDWakeUp_IRQHandler         
    .word   USBHS_IRQHandler           
    .word   DMA1_Channel1_IRQHandler   
    .word   CAN1_SCE_IRQHandler       
    .word   CAN1_TX_IRQHandler      
    .word   CAN1_RX0_IRQHandler       
    .word   0       
    .word   USBSS_IRQHandler          
    .word   USBSS_LINK_IRQHandler           
    .word   USBHSWakeup_IRQHandler     
    .word   USBSSWakeup_IRQHandler    
    .word   RTCAlarm_IRQHandler        
    .word   USBFS_IRQHandler          
    .word   USBFSWakeup_IRQHandler     
    .word   ADC1_2_IRQHandler                                
    .word   TIM1_BRK_IRQHandler              
    .word   TIM1_UP_IRQHandler               
    .word   TIM1_TRG_COM_IRQHandler         
    .word   TIM1_CC_IRQHandler             
    .word   TIM2_IRQHandler                  
    .word   TIM3_IRQHandler                  
    .word   TIM4_IRQHandler                 
    .word   TIM5_IRQHandler                 
    .word   I2C3_EV_IRQHandler               
    .word   I2C3_ER_IRQHandler               
    .word   I2C4_EV_IRQHandler               
    .word   I2C4_ER_IRQHandler              
    .word   QSPI1_IRQHandler              
    .word   SERDES_IRQHandler               
    .word   USART3_IRQHandler              
    .word   USART4_IRQHandler             
    .word   TIM8_BRK_IRQHandler              
    .word   TIM8_UP_IRQHandler               
    .word   TIM8_TRG_COM_IRQHandler          
    .word   TIM8_CC_IRQHandler              
    .word   TIM9_IRQHandler                
    .word   TIM10_IRQHandler               
    .word   TIM11_IRQHandler                
    .word   TIM12_IRQHandler               
    .word   FMC_IRQHandler                  
    .word   SDMMC_IRQHandler                
    .word   LPTIM1_IRQHandler              
    .word   LPTIM2_IRQHandler               
    .word   USART5_IRQHandler               
    .word   USART6_IRQHandler              
    .word   TIM6_IRQHandler                 
    .word   TIM7_IRQHandler                 
    .word   DMA2_Channel1_IRQHandler         
    .word   DMA2_Channel2_IRQHandler         
    .word   DMA2_Channel3_IRQHandler         
    .word   DMA2_Channel4_IRQHandler         
    .word   DMA2_Channel5_IRQHandler        
    .word   DMA2_Channel6_IRQHandler       
    .word   DMA2_Channel7_IRQHandler        
    .word   DMA2_Channel8_IRQHandler         
    .word   ETH_IRQHandler                  
    .word   ETH_WKUP_IRQHandler 
    .word   CAN2_SCE_IRQHandler       
    .word   CAN2_TX_IRQHandler      
    .word   CAN2_RX0_IRQHandler       
    .word   0                  
    .word   USART7_IRQHandler               
    .word   USART8_IRQHandler             
    .word   I3C_EV_IRQHandler                
    .word   I3C_ER_IRQHandler                
    .word   DVP_IRQHandler                   
    .word   ECDC_IRQHandler                  
    .word   PIOC_IRQHandler               
    .word   SAI_IRQHandler
    .word   LTDC_IRQHandler               
    .word   GPHA_IRQHandler 
    .word   0              
    .word   DFSDM0_IRQHandler              
    .word   DFSDM1_IRQHandler  
    .word   0  
    .word   0             
    .word   SWPMI_IRQHandler   
    .word   0  
    .word   0                   
    .word   QSPI2_IRQHandler              
    .word   SWPMI_WKUP_IRQHandler          
    .word   CAN3_SCE_IRQHandler       
    .word   CAN3_TX_IRQHandler      
    .word   CAN3_RX0_IRQHandler       
    .word   0              
    .word   LPTIM2_WKUP_IRQHandler         
    .word   LPTIM1_WKUP_IRQHandler          
    .word   I3C_WKUP_IRQHandler              
    .word   RTC_IRQHandler                    
    .word   HSADC_IRQHandler                  
    .word   UHSIF_IRQHandler                 
    .word   RNG_IRQHandler                    
    .word   SDIO_IRQHandler           

    .option rvc;
    .section    .text.vector_handler, "ax", @progbits
    .weak   NMI_Handler              
    .weak   HardFault_Handler         
    .weak   Ecall_M_Mode_Handler      
    .weak   Ecall_U_Mode_Handler      
    .weak   Break_Point_Handler      
    .weak   SysTick0_Handler          
    .weak   SysTick1_Handler  
    .weak   SW_Handler         
    .weak   IPC_CH0_Handler          
    .weak   IPC_CH1_Handler          
    .weak   IPC_CH2_Handler          
    .weak   IPC_CH3_Handler  
    .weak   HSEM_Handler        
    .weak   WWDG_IRQHandler            
    .weak   EXTI15_8_IRQHandler         
    .weak   FLASH_IRQHandler         
    .weak   RCC_IRQHandler 
    .weak   EXTI7_0_IRQHandler          
    .weak   SPI1_IRQHandler           
    .weak   DMA1_Channel2_IRQHandler   
    .weak   DMA1_Channel3_IRQHandler   
    .weak   DMA1_Channel4_IRQHandler   
    .weak   DMA1_Channel5_IRQHandler  
    .weak   DMA1_Channel6_IRQHandler   
    .weak   DMA1_Channel7_IRQHandler   
    .weak   DMA1_Channel8_IRQHandler  
    .weak   USART2_IRQHandler          
    .weak   I2C1_EV_IRQHandler        
    .weak   I2C1_ER_IRQHandler         
    .weak   USART1_IRQHandler          
    .weak   SPI2_IRQHandler           
    .weak   SPI3_IRQHandler            
    .weak   SPI4_IRQHandler           
    .weak   I2C2_EV_IRQHandler      
    .weak   I2C2_ER_IRQHandler         
    .weak   USBPD_IRQHandler        
    .weak   USBPDWakeUp_IRQHandler         
    .weak   USBHS_IRQHandler           
    .weak   DMA1_Channel1_IRQHandler   
    .weak   CAN1_SCE_IRQHandler       
    .weak   CAN1_TX_IRQHandler      
    .weak   CAN1_RX0_IRQHandler           
    .weak   USBSS_IRQHandler          
    .weak   USBSS_LINK_IRQHandler           
    .weak   USBHSWakeup_IRQHandler     
    .weak   USBSSWakeup_IRQHandler    
    .weak   RTCAlarm_IRQHandler        
    .weak   USBFS_IRQHandler          
    .weak   USBFSWakeup_IRQHandler     
    .weak   ADC1_2_IRQHandler                                
    .weak   TIM1_BRK_IRQHandler              
    .weak   TIM1_UP_IRQHandler               
    .weak   TIM1_TRG_COM_IRQHandler         
    .weak   TIM1_CC_IRQHandler             
    .weak   TIM2_IRQHandler                  
    .weak   TIM3_IRQHandler                  
    .weak   TIM4_IRQHandler                 
    .weak   TIM5_IRQHandler                 
    .weak   I2C3_EV_IRQHandler               
    .weak   I2C3_ER_IRQHandler               
    .weak   I2C4_EV_IRQHandler               
    .weak   I2C4_ER_IRQHandler              
    .weak   QSPI1_IRQHandler              
    .weak   SERDES_IRQHandler               
    .weak   USART3_IRQHandler              
    .weak   USART4_IRQHandler             
    .weak   TIM8_BRK_IRQHandler              
    .weak   TIM8_UP_IRQHandler               
    .weak   TIM8_TRG_COM_IRQHandler          
    .weak   TIM8_CC_IRQHandler              
    .weak   TIM9_IRQHandler                
    .weak   TIM10_IRQHandler               
    .weak   TIM11_IRQHandler                
    .weak   TIM12_IRQHandler               
    .weak   FMC_IRQHandler                  
    .weak   SDMMC_IRQHandler                
    .weak   LPTIM1_IRQHandler              
    .weak   LPTIM2_IRQHandler               
    .weak   USART5_IRQHandler               
    .weak   USART6_IRQHandler              
    .weak   TIM6_IRQHandler                 
    .weak   TIM7_IRQHandler                 
    .weak   DMA2_Channel1_IRQHandler         
    .weak   DMA2_Channel2_IRQHandler         
    .weak   DMA2_Channel3_IRQHandler         
    .weak   DMA2_Channel4_IRQHandler         
    .weak   DMA2_Channel5_IRQHandler        
    .weak   DMA2_Channel6_IRQHandler       
    .weak   DMA2_Channel7_IRQHandler        
    .weak   DMA2_Channel8_IRQHandler         
    .weak   ETH_IRQHandler                  
    .weak   ETH_WKUP_IRQHandler  
    .weak   CAN2_SCE_IRQHandler       
    .weak   CAN2_TX_IRQHandler      
    .weak   CAN2_RX0_IRQHandler                
    .weak   USART7_IRQHandler               
    .weak   USART8_IRQHandler             
    .weak   I3C_EV_IRQHandler                
    .weak   I3C_ER_IRQHandler                
    .weak   DVP_IRQHandler                   
    .weak   ECDC_IRQHandler                                   
    .weak   PIOC_IRQHandler               
    .weak   SAI_IRQHandler
    .weak   LTDC_IRQHandler               
    .weak   GPHA_IRQHandler               
    .weak   DFSDM0_IRQHandler              
    .weak   DFSDM1_IRQHandler              
    .weak   SWPMI_IRQHandler                 
    .weak   QSPI2_IRQHandler              
    .weak   SWPMI_WKUP_IRQHandler          
    .weak   CAN3_SCE_IRQHandler           
    .weak   CAN3_TX_IRQHandler             
    .weak   CAN3_RX0_IRQHandler                    
    .weak   LPTIM2_WKUP_IRQHandler         
    .weak   LPTIM1_WKUP_IRQHandler          
    .weak   I3C_WKUP_IRQHandler              
    .weak   RTC_IRQHandler                    
    .weak   HSADC_IRQHandler                  
    .weak   UHSIF_IRQHandler                 
    .weak   RNG_IRQHandler                    
    .weak   SDIO_IRQHandler    

NMI_Handler:              
HardFault_Handler:         
Ecall_M_Mode_Handler:      
Ecall_U_Mode_Handler:      
Break_Point_Handler:      
SysTick0_Handler:          
SysTick1_Handler: 
SW_Handler:          
IPC_CH0_Handler:          
IPC_CH1_Handler:          
IPC_CH2_Handler:          
IPC_CH3_Handler: 
HSEM_Handler:         
WWDG_IRQHandler:            
EXTI15_8_IRQHandler:         
FLASH_IRQHandler:         
RCC_IRQHandler:   
EXTI7_0_IRQHandler:          
SPI1_IRQHandler:           
DMA1_Channel2_IRQHandler:   
DMA1_Channel3_IRQHandler:   
DMA1_Channel4_IRQHandler:   
DMA1_Channel5_IRQHandler:  
DMA1_Channel6_IRQHandler:   
DMA1_Channel7_IRQHandler:   
DMA1_Channel8_IRQHandler:  
USART2_IRQHandler:          
I2C1_EV_IRQHandler:        
I2C1_ER_IRQHandler:         
USART1_IRQHandler:          
SPI2_IRQHandler:           
SPI3_IRQHandler:            
SPI4_IRQHandler:           
I2C2_EV_IRQHandler:      
I2C2_ER_IRQHandler:         
USBPD_IRQHandler:        
USBPDWakeUp_IRQHandler:         
USBHS_IRQHandler:           
DMA1_Channel1_IRQHandler:   
CAN1_SCE_IRQHandler:       
CAN1_TX_IRQHandler:      
CAN1_RX0_IRQHandler:             
USBSS_IRQHandler:          
USBSS_LINK_IRQHandler:           
USBHSWakeup_IRQHandler:     
USBSSWakeup_IRQHandler:    
RTCAlarm_IRQHandler:        
USBFS_IRQHandler:          
USBFSWakeup_IRQHandler:     
ADC1_2_IRQHandler:                                
TIM1_BRK_IRQHandler:              
TIM1_UP_IRQHandler:               
TIM1_TRG_COM_IRQHandler:         
TIM1_CC_IRQHandler:             
TIM2_IRQHandler:                  
TIM3_IRQHandler:                  
TIM4_IRQHandler:                 
TIM5_IRQHandler:                 
I2C3_EV_IRQHandler:               
I2C3_ER_IRQHandler:               
I2C4_EV_IRQHandler:               
I2C4_ER_IRQHandler:              
QSPI1_IRQHandler:              
SERDES_IRQHandler:               
USART3_IRQHandler:              
USART4_IRQHandler:             
TIM8_BRK_IRQHandler:              
TIM8_UP_IRQHandler:               
TIM8_TRG_COM_IRQHandler:          
TIM8_CC_IRQHandler:              
TIM9_IRQHandler:                
TIM10_IRQHandler:               
TIM11_IRQHandler:                
TIM12_IRQHandler:               
FMC_IRQHandler:                  
SDMMC_IRQHandler:                
LPTIM1_IRQHandler:              
LPTIM2_IRQHandler:               
USART5_IRQHandler:               
USART6_IRQHandler:              
TIM6_IRQHandler:                 
TIM7_IRQHandler:                 
DMA2_Channel1_IRQHandler:         
DMA2_Channel2_IRQHandler:         
DMA2_Channel3_IRQHandler:         
DMA2_Channel4_IRQHandler:         
DMA2_Channel5_IRQHandler:        
DMA2_Channel6_IRQHandler:       
DMA2_Channel7_IRQHandler:        
DMA2_Channel8_IRQHandler:         
ETH_IRQHandler:                  
ETH_WKUP_IRQHandler:   
CAN2_SCE_IRQHandler:       
CAN2_TX_IRQHandler:      
CAN2_RX0_IRQHandler:           
USART7_IRQHandler:               
USART8_IRQHandler:             
I3C_EV_IRQHandler:                
I3C_ER_IRQHandler:                
DVP_IRQHandler:                   
ECDC_IRQHandler:                  
PIOC_IRQHandler:               
SAI_IRQHandler:
LTDC_IRQHandler:               
GPHA_IRQHandler:               
DFSDM0_IRQHandler:              
DFSDM1_IRQHandler:              
SWPMI_IRQHandler:                 
QSPI2_IRQHandler:              
SWPMI_WKUP_IRQHandler:          
CAN3_SCE_IRQHandler:           
CAN3_TX_IRQHandler:             
CAN3_RX0_IRQHandler:                       
LPTIM2_WKUP_IRQHandler:         
LPTIM1_WKUP_IRQHandler:          
I3C_WKUP_IRQHandler:              
RTC_IRQHandler:                    
HSADC_IRQHandler:                  
UHSIF_IRQHandler:                 
RNG_IRQHandler:                    
SDIO_IRQHandler: 
1:
	j 1b

	.section	.handle_reset,"ax",@progbits
	.weak	handle_reset
	.align	1
handle_reset:
.option push 
.option	norelax 
	la gp, __global_pointer$
.option	pop 

	la sp, _eusrstack 

    /*Enable RCC 4*HSI = 100MHz*/
    lui  s1 ,0x40021
    li  a1, 0x0
    sw a1 ,8(s1)
    nop

    /*enable pll*/
    lw t0,0(s1)
    li t1,0x1000000
    or t0,t0,t1
    sw t0,0(s1)
    fence

    1:
    lw t2,0(s1)   
    li t3,0x2000000
    and t2,t2,t3
    beqz t2 ,1b

    /*enable pll gate*/
    lw t4,8(s1)
    li t5,0x80000000
    or t4,t4,t5
    sw t4,8(s1)
    fence
    nop

    /*choose pll */
    li  t6, 0x2
    sw t6 ,4(s1)
    fence
    nop

    1:
    lw s2, 4(s1)
    li s3 ,0x8
    and s2,s2,s3
    beqz s2, 1b

/* Load highcode code  section from flash to RAM */
    la a0, _highcode_lma
    la a1, _highcode_vma_start
    la a2, _highcode_vma_end
    bgeu a1, a2, 2f
1:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b

/* Load highcode code  section from flash to RAM */
2:
    la a0, _highcode_lma1
    la a1, _highcode_vma_start1
    la a2, _highcode_vma_end1
    bgeu a1, a2, 2f
1:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b
/* Load data section from flash to RAM */
2:
	la a0, _data_lma
	la a1, _data_vma
	la a2, _edata
	bgeu a1, a2, 2f
1:
	lw t0, (a0)
	sw t0, (a1)
	addi a0, a0, 4
	addi a1, a1, 4
	bltu a1, a2, 1b
2:
/* Clear bss section */
	la a0, _sbss
	la a1, _ebss
	bgeu a0, a1, 2f
1:
	sw zero, (a0)
	addi a0, a0, 4
	bltu a0, a1, 1b
2:
/* Configure Prefetch */
    li t0, 0x123703E1
    csrw 0xBC0, t0
/* Configure nesting level */
	li t0, 0x01
	csrw 0xBC1, t0
/* Enable interrupt nesting and hardware stack */
    li t0, 0x0B
    csrw 0x804, t0
/* Enable floating point and global interrupt, configure privileged mode */
   	li t0, 0x6088           
   	csrw mstatus, t0
/* Enable cache*/
    li t0 ,0x2
    csrc 0xBC2,t0
/* Configure the interrupt vector table recognition mode and entry address mode */
 	la t0, _vector_base
    ori t0, t0, 3           
	csrw mtvec, t0

    call SystemInit
BP:	la t0, main
	csrw mepc, t0
	mret


