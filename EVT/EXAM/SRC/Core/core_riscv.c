/********************************** (C) COPYRIGHT  *******************************
* File Name          : core_riscv.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2025/03/01
* Description        : RISC-V V3F_V5F Core Peripheral Access Layer Source File for CH32H417
*********************************************************************************
* Copyright (c) 2025 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#include <stdint.h>

/* define compiler specific symbols */
#if defined ( __CC_ARM   )
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler          */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler       */

#elif defined ( __ICCARM__ )
  #define __ASM           __asm                                       /*!< asm keyword for IAR Compiler          */
  #define __INLINE        inline                                      /*!< inline keyword for IAR Compiler. Only avaiable in High optimization mode! */

#elif defined   (  __GNUC__  )
  #define __ASM            __asm                                      /*!< asm keyword for GNU Compiler          */
  #define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */

#elif defined   (  __TASKING__  )
  #define __ASM            __asm                                      /*!< asm keyword for TASKING Compiler      */
  #define __INLINE         inline                                     /*!< inline keyword for TASKING Compiler   */

#endif


/*********************************************************************
 * @fn      __get_FFLAGS
 *
 * @brief   Return the Floating-Point Accrued Exceptions
 *
 * @return  fflags value
 */
uint32_t __get_FFLAGS(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "fflags" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_FFLAGS
 *
 * @brief   Set the Floating-Point Accrued Exceptions
 *
 * @param   value  - set FFLAGS value
 *
 * @return  none
 */
void __set_FFLAGS(uint32_t value)
{
  __ASM volatile ("csrw fflags, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_FRM
 *
 * @brief   Return the Floating-Point Dynamic Rounding Mode
 *
 * @return  frm value
 */
uint32_t __get_FRM(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "frm" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_FRM
 *
 * @brief   Set the Floating-Point Dynamic Rounding Mode
 *
 * @param   value  - set frm value
 *
 * @return  none
 */
void __set_FRM(uint32_t value)
{
  __ASM volatile ("csrw frm, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_FCSR
 *
 * @brief   Return the Floating-Point Control and Status Register
 *
 * @return  fcsr value
 */
uint32_t __get_FCSR(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "fcsr" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_FCSR
 *
 * @brief   Set the Floating-Point Dynamic Rounding Mode
 *
 * @param   value  - set fcsr value
 *
 * @return  none
 */
void __set_FCSR(uint32_t value)
{
  __ASM volatile ("csrw fcsr, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MSTATUS
 *
 * @brief   Return the Machine Status Register
 *
 * @return  mstatus value
 */
uint32_t __get_MSTATUS(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mstatus" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MSTATUS
 *
 * @brief   Set the Machine Status Register
 *
 * @param   value  - set mstatus value
 *
 * @return  none
 */
void __set_MSTATUS(uint32_t value)
{
  __ASM volatile ("csrw mstatus, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MISA
 *
 * @brief   Return the Machine ISA Register
 *
 * @return  misa value
 */
uint32_t __get_MISA(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "misa" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MISA
 *
 * @brief   Set the Machine ISA Register
 *
 * @param   value  - set misa value
 *
 * @return  none
 */
void __set_MISA(uint32_t value)
{
  __ASM volatile ("csrw misa, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MTVEC
 *
 * @brief   Return the Machine Trap-Vector Base-Address Register
 *
 * @return  mtvec value
 */
uint32_t __get_MTVEC(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mtvec" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MTVEC
 *
 * @brief   Set the Machine Trap-Vector Base-Address Register
 *
 * @param   value  - set mtvec value
 *
 * @return  none
 */
void __set_MTVEC(uint32_t value)
{
  __ASM volatile ("csrw mtvec, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MSCRATCH
 *
 * @brief   Return the Machine Seratch Register
 *
 * @return  mscratch value
 */
uint32_t __get_MSCRATCH(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mscratch" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MSCRATCH
 *
 * @brief   Set the Machine Seratch Register
 *
 * @param   value  - set mscratch value
 *
 * @return  none
 */
void __set_MSCRATCH(uint32_t value)
{
  __ASM volatile ("csrw mscratch, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MEPC
 *
 * @brief   Return the Machine Exception Program Register
 *
 * @return  mepc value
 */
uint32_t __get_MEPC(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mepc" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MEPC
 *
 * @brief   Set the Machine Exception Program Register
 *
 * @return  mepc value
 */
void __set_MEPC(uint32_t value)
{
  __ASM volatile ("csrw mepc, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MCAUSE
 *
 * @brief   Return the Machine Cause Register
 *
 * @return  mcause value
 */
uint32_t __get_MCAUSE(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mcause" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MEPC
 *
 * @brief   Set the Machine Cause Register
 *
 * @return  mcause value
 */
void __set_MCAUSE(uint32_t value)
{
  __ASM volatile ("csrw mcause, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MTVAL
 *
 * @brief   Return the Machine Trap Value Register
 *
 * @return  mtval value
 */
uint32_t __get_MTVAL(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mtval" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __set_MTVAL
 *
 * @brief   Set the Machine Trap Value Register
 *
 * @return  mtval value
 */
void __set_MTVAL(uint32_t value)
{
  __ASM volatile ("csrw mtval, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MVENDORID
 *
 * @brief   Return Vendor ID Register
 *
 * @return  mvendorid value
 */
uint32_t __get_MVENDORID(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mvendorid" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __get_MARCHID
 *
 * @brief   Return Machine Architecture ID Register
 *
 * @return  marchid value
 */
uint32_t __get_MARCHID(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "marchid" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __get_MIMPID
 *
 * @brief   Return Machine Implementation ID Register
 *
 * @return  mimpid value
 */
uint32_t __get_MIMPID(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mimpid" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __get_MHARTID
 *
 * @brief   Return Hart ID Register
 *
 * @return  mhartid value
 */
uint32_t __get_MHARTID(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mhartid" : "=r" (result) );
  return (result);
}

/*********************************************************************
 * @fn      __get_SP
 *
 * @brief   Return SP Register
 *
 * @return  SP value
 */
uint32_t __get_SP(void)
{
  uint32_t result;

  __ASM volatile ( "mv %0," "sp" : "=r"(result) : );
  return (result);
}

/*********************************************************************
 * @fn      __set_MCOUNT_INHIBIT
 *
 * @brief   Set Instruction and cycle count shield switch in machine mode
 *
 * @return  mcause value
 */
void __set_MCOUNT_INHIBIT(uint32_t value)
{
  __ASM volatile ("csrw mucounteren, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MCOUNT_INHIBIT
 *
 * @brief   Return Instruction and cycle count shield switch in machine mode
 *
 * @return  SP value
 */
uint32_t __get_MCOUNT_INHIBIT(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mucounteren" : "=r"(result) : );
  return (result);
}

/*********************************************************************
 * @fn      __set_MCYCLE
 *
 * @brief   Set the number of cycles in machine mode
 *
 * @return  mcause value
 */
void __set_MCYCLE(uint32_t value)
{
  __ASM volatile ("csrw mcycle, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MCYCLE
 *
 * @brief   Return the number of cycles in machine mode
 *
 * @return  SP value
 */
uint32_t __get_MCYCLE(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "mcycle" : "=r"(result) : );
  return (result);
}

/*********************************************************************
 * @fn      __set_MINSTRET
 *
 * @brief   Set the number of completed instructions in machine mode
 *
 * @return  mcause value
 */
void __set_MINSTRET(uint32_t value)
{
  __ASM volatile ("csrw minstret, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_MINSTRET
 *
 * @brief   Return the number of completed instructions in machine mode
 *
 * @return  SP value
 */
uint32_t __get_MINSTRET(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "minstret" : "=r"(result) : );
  return (result);
}

/*********************************************************************
 * @fn      __set_UCYCLE
 *
 * @brief   Set the number of cycles in user mode
 *
 * @return  mcause value
 */
void __set_UCYCLE(uint32_t value)
{
  __ASM volatile ("csrw cycle, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_UCYCLE
 *
 * @brief   Return the number of cycles in user mode
 *
 * @return  SP value
 */
uint32_t __get_UCYCLE(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "cycle" : "=r"(result) : );
  return (result);
}

/*********************************************************************
 * @fn      __set_UINSTRET
 *
 * @brief   Set the number of completed instructions in user mode
 *
 * @return  mcause value
 */
void __set_UINSTRET(uint32_t value)
{
  __ASM volatile ("csrw instret, %0" : : "r" (value) );
}

/*********************************************************************
 * @fn      __get_UINSTRET
 *
 * @brief   Return the number of completed instructions in user mode
 *
 * @return  SP value
 */
uint32_t __get_UINSTRET(void)
{
  uint32_t result;

  __ASM volatile ( "csrr %0," "instret" : "=r"(result) : );
  return (result);
}
