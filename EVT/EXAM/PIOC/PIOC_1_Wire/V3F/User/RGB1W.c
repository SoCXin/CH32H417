/********************************** (C) COPYRIGHT *******************************
 * File Name          : RGB1W.c
 * Author             : WCH
 * Version            : V1.0.1
 * Date               : 2025/03/01
 * Description        : 1-wire example 1W-RGB, 1W-DS1820
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

__attribute__((aligned(16)))  const unsigned char PIOC_1W_CODE[] =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x60,0x00,0x00,0x00,0x00,0x00,0x00,	/* .........`...... */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x08,0x70,	/* ..........0....p */
	0x00,0x00,0x08,0x70,0x00,0x00,0x08,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x70,	/* ...p...p.......p */
	0x08,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x1C,0x5E,	/* .p......0......^ */
	0x1C,0x47,0x1C,0x5D,0x1F,0x60,0x1C,0x47,0x1E,0x02,0x09,0x10,0x3C,0xC1,0x49,0xC2,	/* .G.].`.G....<.I. */
	0x3F,0xC3,0x3A,0x80,0x20,0x2F,0x4C,0x38,0x60,0x2F,0x9E,0x38,0x87,0x2F,0x3A,0x38,	/* ?.:...L8`..8..:8 */
	0xFC,0x2F,0xED,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* ...8............ */
	0x00,0x00,0x00,0x00,0x01,0x28,0x99,0x60,0x00,0x00,0x2A,0x72,0x99,0x60,0x00,0x00,	/* .....(.`..*r.`.. */
	0x2A,0x72,0x99,0x30,0x4B,0x24,0x28,0x22,0xE8,0x71,0x04,0x15,0x44,0x30,0x09,0x15,	/* *r.0K$(".q..D0.. */
	0x43,0x30,0x00,0x00,0x36,0x72,0x99,0x60,0x00,0x00,0x08,0x01,0x0B,0x40,0x0A,0x48,	/* C0..6r.`.....@.H */
	0x0C,0x01,0x06,0x28,0x0B,0x54,0x99,0x60,0x09,0x02,0x04,0x10,0x20,0x24,0x00,0x00,	/* ...(.T.`.....$.. */
	0x0B,0x48,0x15,0x70,0x01,0x5F,0x0B,0x40,0x0E,0x70,0x0B,0x40,0x14,0x70,0x0B,0x48,	/* .H.p._.@.p.@.p.H */
	0x15,0x70,0x01,0x5E,0x0B,0x40,0x0E,0x70,0x0B,0x40,0x14,0x70,0x0B,0x48,0x15,0x70,	/* .p.^.@.p.@.p.H.p */
	0x01,0x5D,0x0B,0x40,0x0E,0x70,0x0B,0x40,0x14,0x70,0x0B,0x48,0x15,0x70,0x01,0x5C,	/* .].@.p.@.p.H.p.\ */
	0x0B,0x40,0x0E,0x70,0x0B,0x40,0x14,0x70,0x0B,0x48,0x15,0x70,0x01,0x5B,0x0B,0x40,	/* .@.p.@.p.H.p.[.@ */
	0x0E,0x70,0x0B,0x40,0x14,0x70,0x0B,0x48,0x15,0x70,0x01,0x5A,0x0B,0x40,0x0E,0x70,	/* .p.@.p.H.p.Z.@.p */
	0x0B,0x40,0x14,0x70,0x0B,0x48,0x15,0x70,0x01,0x59,0x0B,0x40,0x0E,0x70,0x0B,0x40,	/* .@.p.H.p.Y.@.p.@ */
	0x14,0x70,0x0B,0x48,0x15,0x70,0x01,0x58,0x0B,0x40,0x0F,0x70,0x01,0x02,0x0B,0x40,	/* .p.H.p.X.@.p...@ */
	0x17,0x70,0x04,0x15,0x58,0x30,0x1E,0x28,0xED,0x71,0xED,0x71,0x04,0x00,0x0B,0x54,	/* .p..X0.(.q.q...T */
	0x04,0x28,0x1D,0x10,0x1C,0x4F,0x1F,0x60,0x02,0x28,0x99,0x60,0x00,0x00,0x09,0x46,	/* .(...O.`.(.`...F */
	0x08,0x01,0x0B,0x41,0x0A,0x49,0x0C,0x01,0x06,0x28,0x0B,0x55,0x99,0x60,0x09,0x02,	/* ...A.I...(.U.`.. */
	0x04,0x10,0x20,0x24,0x00,0x00,0x0B,0x49,0x15,0x70,0x01,0x5F,0x0B,0x41,0x0E,0x70,	/* ...$...I.p._.A.p */
	0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x01,0x5E,0x0B,0x41,0x0E,0x70,0x0B,0x41,	/* .A.p.I.p.^.A.p.A */
	0x14,0x70,0x0B,0x49,0x15,0x70,0x01,0x5D,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,	/* .p.I.p.].A.p.A.p */
	0x0B,0x49,0x15,0x70,0x01,0x5C,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,	/* .I.p.\.A.p.A.p.I */
	0x15,0x70,0x01,0x5B,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,	/* .p.[.A.p.A.p.I.p */
	0x01,0x5A,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x01,0x59,	/* .Z.A.p.A.p.I.p.Y */
	0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x01,0x58,0x0B,0x41,	/* .A.p.A.p.I.p.X.A */
	0x0F,0x70,0x01,0x02,0x0B,0x41,0x17,0x70,0x04,0x15,0xAB,0x30,0x1E,0x28,0xED,0x71,	/* .p...A.p...0.(.q */
	0xED,0x71,0x04,0x00,0x0B,0x55,0x04,0x28,0x99,0x60,0x00,0x00,0x22,0x50,0x45,0x61,	/* .q...U.(.`.."PEa */
	0x08,0x01,0x0B,0x40,0x80,0x28,0x0C,0x10,0x20,0x02,0x21,0x0A,0x9C,0x34,0x0A,0x48,	/* ...@.(....!..4.H */
	0x09,0x47,0x3E,0x01,0x04,0x01,0x06,0x28,0x0B,0x54,0x99,0x60,0x02,0x28,0x3F,0x10,	/* .G>....(.T.`.(?. */
	0x18,0x00,0x1F,0x10,0x80,0x29,0x09,0x0A,0x00,0x00,0x08,0x10,0x13,0x00,0xAE,0x00,	/* .....).......... */
	0x13,0x00,0xAD,0x00,0x13,0x00,0xAC,0x00,0x13,0x00,0xAB,0x00,0x13,0x00,0xAA,0x00,	/* ................ */
	0x13,0x00,0x20,0x15,0x20,0x04,0x03,0x52,0x21,0x15,0xA9,0x00,0x13,0x00,0x20,0x02,	/* .......R!....... */
	0x21,0x0A,0x3F,0x35,0xA8,0x00,0x13,0x00,0x04,0x02,0x1F,0x10,0xAF,0x00,0x13,0x00,	/* !.?5............ */
	0xAE,0x00,0x13,0x00,0xAD,0x00,0x13,0x00,0xAC,0x00,0x13,0x00,0x20,0x15,0x20,0x04,	/* ................ */
	0x03,0x52,0x21,0x15,0xAB,0x00,0x13,0x00,0x3E,0x14,0x03,0x52,0x3F,0x14,0xAA,0x00,	/* .R!.....>..R?... */
	0x13,0x00,0x3E,0x02,0x04,0x10,0xA9,0x00,0x13,0x00,0x20,0x02,0x21,0x0A,0x3F,0x35,	/* ..>.........!.?5 */
	0x3F,0x02,0xA8,0x00,0x13,0x00,0x18,0x00,0x1F,0x10,0xAF,0x00,0x06,0x61,0xA8,0x00,	/* ?............a.. */
	0x13,0x00,0x08,0x47,0x12,0x00,0x08,0x01,0x93,0x60,0x00,0x00,0x08,0x01,0x0C,0x01,	/* ...G.....`...... */
	0x0B,0x41,0x20,0x02,0x21,0x0A,0x9C,0x34,0x0A,0x49,0x3E,0x01,0x04,0x01,0x06,0x28,	/* .A..!..4.I>....( */
	0x0B,0x54,0x99,0x60,0x02,0x28,0x3F,0x10,0x18,0x00,0x1F,0x10,0x0B,0x49,0x15,0x70,	/* .T.`.(?......I.p */
	0x1F,0x5F,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5E,	/* ._.A.p.A.p.I.p.^ */
	0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5D,0x0B,0x41,	/* .A.p.A.p.I.p.].A */
	0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5C,0x0B,0x41,0x0E,0x70,	/* .p.A.p.I.p.\.A.p */
	0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5B,0x0B,0x41,0x0E,0x70,0x0B,0x41,	/* .A.p.I.p.[.A.p.A */
	0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5A,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,	/* .p.I.p.Z.A.p.A.p */
	0x0B,0x49,0x15,0x70,0x1F,0x59,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,	/* .I.p.Y.A.p.A.p.I */
	0x15,0x70,0x1F,0x58,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x00,0x00,0x00,0x00,0x00,0x00,	/* .p.X.A.p.A...... */
	0x00,0x00,0x20,0x15,0x20,0x04,0x03,0x52,0x21,0x15,0x20,0x02,0x21,0x0A,0xE6,0x34,	/* .......R!...!..4 */
	0x04,0x02,0x1F,0x10,0x0B,0x49,0x15,0x70,0x1F,0x5F,0x0B,0x41,0x0E,0x70,0x0B,0x41,	/* .....I.p._.A.p.A */
	0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5E,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,	/* .p.I.p.^.A.p.A.p */
	0x0B,0x49,0x15,0x70,0x1F,0x5D,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,	/* .I.p.].A.p.A.p.I */
	0x15,0x70,0x1F,0x5C,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,	/* .p.\.A.p.A.p.I.p */
	0x1F,0x5B,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x5A,	/* .[.A.p.A.p.I.p.Z */
	0x0B,0x41,0x0E,0x70,0x0B,0x41,0x14,0x70,0x0B,0x49,0x15,0x70,0x1F,0x59,0x0B,0x41,	/* .A.p.A.p.I.p.Y.A */
	0x0E,0x70,0x0B,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x15,0x20,0x04,	/* .p.A............ */
	0x03,0x52,0x21,0x15,0x3E,0x14,0x03,0x52,0x3F,0x14,0x3E,0x02,0x04,0x10,0x0B,0x49,	/* .R!.>..R?.>....I */
	0x15,0x70,0x1F,0x58,0x0B,0x41,0x0E,0x70,0x0B,0x41,0x00,0x00,0x00,0x00,0x00,0x00,	/* .p.X.A.p.A...... */
	0x00,0x00,0x20,0x02,0x21,0x0A,0xE6,0x34,0x3F,0x02,0x18,0x00,0x1F,0x10,0x56,0x61,	/* ....!..4?.....Va */
	0xFA,0x28,0xED,0x61,0x41,0x28,0xED,0x61,0x02,0x28,0x14,0x70,0x00,0x00,0x14,0x70,	/* .(.aA(.a.(.p...p */
	0x00,0x00,0x14,0x70,0x00,0x00,0x08,0x70,0x00,0x00,0xFF,0x2C,0xED,0x31,0x30,0x00,	/* ...p...p...,.10. */
	0x0A,0x40,0x08,0x01,0x0C,0x01,0x05,0x28,0xED,0x71,0x0B,0x40,0x0A,0x48,0xE8,0x71,	/* .@.....(.q.@.H.q */
	0xE8,0x71,0x0A,0x40,0xEA,0x71,0x09,0x01,0x0B,0x54,0x04,0x24,0xE8,0x71,0x09,0x02,	/* .q.@.q...T.$.q.. */
	0x30,0x00,0x09,0x10,0x08,0x22,0x0B,0x40,0x0A,0x48,0xEC,0x71,0x09,0x50,0x0A,0x40,	/* 0....".@.H.q.P.@ */
	0xEA,0x71,0x0A,0x40,0x05,0x28,0x09,0x58,0xED,0x71,0x09,0x1F,0x04,0x15,0x0B,0x32,	/* .q.@.(.X.q.....2 */
	0x30,0x00,0x08,0x22,0x0B,0x40,0x0A,0x48,0xEC,0x71,0x0A,0x40,0x0A,0x28,0xED,0x71,	/* 0..".@.H.q.@.(.q */
	0x09,0x1F,0x09,0x47,0x0B,0x54,0x09,0x4F,0x37,0x28,0xED,0x71,0x04,0x15,0x1A,0x32,	/* ...G.T.O7(.q...2 */
	0x09,0x02,0x30,0x00,0xF8,0x71,0x35,0x32,0xCC,0x28,0x09,0x72,0x44,0x28,0x09,0x72,	/* ..0..q52.(.rD(.r */
	0x1C,0x5C,0x34,0x62,0x0B,0x48,0x0A,0x48,0x04,0x00,0x30,0x00,0xF8,0x71,0x41,0x32,	/* .\4b.H.H..0..qA2 */
	0xCC,0x28,0x09,0x72,0xBE,0x28,0x09,0x72,0x19,0x72,0x20,0x10,0x19,0x72,0x21,0x10,	/* .(.r.(.r.r...r!. */
	0xF8,0x71,0x30,0x00,0x00,0x00};	/* .q0... */




#include "RGB1W.h"
#include "ch32h417.h"
#include <string.h>

/* PIOC IO 0/1 pin select definition */
#define	PIOC_IO0_1	1 //PB8
#define PIOC_IO0_2  2 //PC1 
#define PIOC_IO0_3  3 //PE3
#define PIOC_IO0_4  4 //PF12
#define PIOC_IO1_1	5 //PB9
#define PIOC_IO1_2	6 //PC0
#define PIOC_IO1_3	7 //PC2
#define PIOC_IO1_4	8 //PE4
#define PIOC_IO1_5	9 //PF13
#define PIOC_IO1_6	10 //PF14

#define  PIOC_IO    PIOC_IO0_2

__IO  uint8_t	stat;


void PIOC_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      PIOC_IRQHandler
 *
 * @brief   This function handles PIOC exception.
 *
 * @return  none
 */
void PIOC_IRQHandler( void )
{
//	uint8_t	stat;
	stat = PIOC->D8_CTRL_RD;//auto remove interrupt request after reading
//	if ( stat == RGB1W_ERR_OK ) printf("1-wire finished\r\n");
//	else printf("1-wire error %02x\r\n", stat);
//	temper = PIOC->D16_DATA_REG0_1;//for DS1820 only
}

/*********************************************************************
 * @fn      RGB1W_Init
 *
 * @brief   Init RGB1W.
 *
 * @return  none
 */
void RGB1W_Init ( void ) 
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

/***** PIOC IO0 pin select *****/
#if(PIOC_IO == PIOC_IO0_1)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOB, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO0_2)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOC, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource1, GPIO_AF7);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO0_3)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOE, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource3, GPIO_AF5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO0_4)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOF, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource12, GPIO_AF4);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOF, &GPIO_InitStructure);

/***** PIOC IO1 pin select *****/
#elif(PIOC_IO == PIOC_IO1_1)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOB, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF7);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO1_2)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOC, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource0, GPIO_AF5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO1_3)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOC, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF8);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO1_4)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOE, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource4, GPIO_AF4);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO1_5)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOF, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource13, GPIO_AF5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOF, &GPIO_InitStructure);

#elif(PIOC_IO == PIOC_IO1_6)
    RCC_HB2PeriphClockCmd(RCC_HB2Periph_AFIO | RCC_HB2Periph_GPIOF, ENABLE);
    RCC_HBPeriphClockCmd(RCC_HBPeriph_PIOC, ENABLE);
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource14, GPIO_AF5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Very_High;
    GPIO_Init(GPIOF, &GPIO_InitStructure);

#endif

	PIOC->D8_SYS_CFG = RB_MST_RESET | RB_MST_IO_EN0| RB_MST_IO_EN1;	// reset PIOC & enable IO0 IO1

	memcpy( (uint8_t *)(PIOC_SRAM_BASE), PIOC_1W_CODE, sizeof( PIOC_1W_CODE ) ); // load code for PIOC

//    NVIC_EnableIRQ(PIOC_IRQn);//enable interrupt
//    NVIC_SetPriority(PIOC_IRQn,0xf0);
}

/*********************************************************************
 * @fn      RGB1W_SendSFR
 *
 * @brief   SFR mode for 1~32 bytes data.
 *
 * @param   total_bytes - total data number(byte).
 *          p_source_addr - data.
 *          mod - 0:PIOC IO 0
 *                1:PIOC IO 1
 *
 * @return  none
 */
void RGB1W_SendSFR( uint16_t total_bytes, uint8_t *p_source_addr ,uint8_t mod) {//SFR mode for 1~32 bytes data
// p_source_addr: point source data buffer start address, set NULL if copy into PIOC buffer already.HCLK default is 96MHz.
	if ( total_bytes > RGB1W_SFR_SIZE ) return;
	PIOC->D8_SYS_CFG = RB_MST_RESET | RB_MST_IO_EN0 | RB_MST_IO_EN1;//clear&halt PIOC
	PIOC->D8_SYS_CFG = RB_MST_CLK_GATE | RB_MST_IO_EN0 | RB_MST_IO_EN1;//run PIOC before write SFR
	if ( p_source_addr ) memcpy( RGB1W_SFR_ADDR, p_source_addr, total_bytes );//copy source data to RGB1W SFR, @PIOC run
	if(mod)
	    RGB1W_COMMAND = ((uint8_t)total_bytes|0X40);// PIOC start send
	else
	    RGB1W_COMMAND = (uint8_t)total_bytes;// PIOC start send
}

/*********************************************************************
 * @fn      RGB1W_SendRAM
 *
 * @brief   RAM mode for 1~3072 bytes data.
 *
 * @param   total_bytes - total data number(byte).
 *          p_source_addr - data.
 *          mod - 0:PIOC IO 0
 *                1:PIOC IO 1
 *
 * @return  none
 */
void RGB1W_SendRAM( uint16_t total_bytes, uint8_t *p_source_addr ,uint8_t mod) {//RAM mode for 1~3072 bytes data
// p_source_addr: point source data buffer start address, set NULL if copy into PIOC buffer already
	if ( total_bytes > RGB1W_RAM_SIZE ) return;
	PIOC->D8_SYS_CFG = RB_MST_RESET | RB_MST_IO_EN0| RB_MST_IO_EN1;//clear&halt PIOC
	if ( p_source_addr ) memcpy( RGB1W_RAM_ADDR, p_source_addr, total_bytes );//copy source data to PIOC SRAM, @PIOC halt
	PIOC->D8_SYS_CFG = RB_MST_CLK_GATE | RB_MST_IO_EN0| RB_MST_IO_EN1;//run PIOC after load data in SRAM
	PIOC->D16_DATA_REG0_1 = total_bytes;// data size
	if(mod)
	{
		PIOC->D8_DATA_REG2 = 1;
		RGB1W_COMMAND = 0x55 | RGB1W_CMD_RAM;// default is 100MHz.
	} 
	else
	{
		RGB1W_COMMAND = RGB1W_CYC_100M | RGB1W_CMD_RAM;// set mode 0 bit cycle and PIOC start send
		PIOC->D8_DATA_REG2 = 0;
	}
}

/*********************************************************************
 * @fn      RGB1W_SendSFR_Wait
 *
 * @brief   SFR mode for 1~3072 bytes data wait PIOC operate finish.
 *
 * @param   total_bytes - total data number(byte).
 *          p_source_addr - data.
 *          mod - 0:PIOC IO 0
 *                1:PIOC IO 1
 * @return  none
 */
uint8_t RGB1W_SendSFR_Wait( uint16_t total_bytes, uint8_t *p_source_addr ,uint8_t mod) {//SFR mode for 1~32 bytes data
// p_source_addr: point source data buffer start address, set NULL if copy into PIOC buffer already
	if ( total_bytes == 0 || total_bytes > RGB1W_SFR_SIZE ) return( RGB1W_ERR_PARA );
	RGB1W_SendSFR( total_bytes, p_source_addr , mod);
	while ( ( PIOC->D8_SYS_CFG & RB_INT_REQ ) == 0 );//wait, PIOC request interrupt after finish
	return( PIOC->D8_CTRL_RD );//auto remove interrupt request after reading
}

/*********************************************************************
 * @fn      RGB1W_SendRAM_Wait
 *
 * @brief   RAM mode for 1~3072 bytes data wait PIOC operate finish.
 *
 * @param   total_bytes - total data number(byte).
 *          p_source_addr - data.
 *          mod - 0:PIOC IO 0
 *                1:PIOC IO 1
 * @return  none
 */
uint8_t RGB1W_SendRAM_Wait( uint16_t total_bytes, uint8_t *p_source_addr ,uint8_t mod) {//RAM mode for 1~3072 bytes data
// p_source_addr: point source data buffer start address, set NULL if copy into PIOC buffer already
	if ( total_bytes == 0 || total_bytes > RGB1W_RAM_SIZE ) return( RGB1W_ERR_PARA );
	RGB1W_SendRAM( total_bytes, p_source_addr ,mod);
	while ( ( PIOC->D8_SYS_CFG & RB_INT_REQ ) == 0 );//wait, PIOC request interrupt after finish
	return( PIOC->D8_CTRL_RD );//auto remove interrupt request after reading
}

/*********************************************************************
 * @fn      RGB1W_Halt
 *
 * @brief   halt/sleep PIOC .
 *
 * @return  none
 */
void RGB1W_Halt( void ) {//halt/sleep PIOC
	PIOC->D8_SYS_CFG &= ~ RB_MST_CLK_GATE;
}

