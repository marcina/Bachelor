/**
 *  Defines for  entire project at one place
*/

#ifndef DEFINES_H
#define DEFINES_H

#include "stdint.h"
/*********************************************************** Timer ***************************************************************************/
#define TIM_Name1 				TIM7
#define TIM_Time1				200 // ms
#define TIM_IRQChannel_Name1	TIM7_IRQn
#define TIM_RCC1				RCC_APB1Periph_TIM7

#define TIM_Name2				TIM6
#define TIM_Time2				70 // ms
#define TIM_IRQChannel_Name2	TIM6_DAC_IRQn
#define TIM_RCC2				RCC_APB1Periph_TIM6


/*********************************************************** FatFs ***************************************************************************/

#define FATFS_USE_DETECT_PIN            	1
#define FATFS_USE_DETECT_PIN_EXTI           1
//#define FATFS_USE_WRITEPROTECT_PIN        1
#define FATFS_USE_SDIO                		1
#define FATFS_SDIO_4BIT         			0 // 0 - FATFS_SDIO_1BIT
											  // 1 - FATFS_SDIO_4BIT


//If you want to overwrite default CD pin, then change this settings
/*
#define FATFS_USE_DETECT_PIN_RCC        RCC_AHB1Periph_GPIOC
#define FATFS_USE_DETECT_PIN_PORT       GPIOC
#define FATFS_USE_DETECT_PIN_PIN        GPIO_Pin_2
*/

#define isCardConn							!GPIO_ReadOutputDataBit(FATFS_USE_DETECT_PIN_PORT,FATFS_USE_DETECT_PIN_PIN)

//If you want to overwrite default EXTI pin, then change this settings and EXTIn_IRQ_Handler()
/*
#define FATFS_USE_DETECT_PIN_EXTI_LINE		EXTI_Line2
#define FATFS_USE_DETECT_PIN_EXTI_IRQ		EXTI2_IRQn
#define FATFS_USE_DETECT_PIN_EXTI_PORT		EXTI_PortSourceGPIOC
#define FATFS_USE_DETECT_PIN_EXTI_PIN		EXTI_PinSource2
*/
//If you want to overwrite default WP pin, then change this settings
/*
#define FATFS_USE_WRITEPROTECT_PIN_RCC        RCC_AHB1Periph_GPIOB
#define FATFS_USE_WRITEPROTECT_PIN_PORT        GPIOB
#define FATFS_USE_WRITEPROTECT_PIN_PIN        GPIO_Pin_7
*/
//Select your SPI settings
/*
#define FATFS_SPI                SPI1
#define FATFS_SPI_PINSPACK        TM_SPI_PinsPack_1
*/
//Custom CS pin for SPI communication
/*
#define FATFS_CS_RCC        RCC_AHB1Periph_GPIOB
#define FATFS_CS_PORT        GPIOB
#define FATFS_CS_PIN        GPIO_Pin_5
*/

/********************************************************** NVIC *****************************************************************************/
 /*
  *    ==========================================================================================================================
  *      NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  |       Description
  *    ==========================================================================================================================
  *     NVIC_PriorityGroup_0  |                0                  |            0-15             | 0 bits for pre-emption priority
  *                           |                                   |                             | 4 bits for subpriority
  *    --------------------------------------------------------------------------------------------------------------------------
  *     NVIC_PriorityGroup_1  |                0-1                |            0-7              | 1 bits for pre-emption priority
  *                           |                                   |                             | 3 bits for subpriority
  *    --------------------------------------------------------------------------------------------------------------------------
  *     NVIC_PriorityGroup_2  |                0-3                |            0-3              | 2 bits for pre-emption priority
  *                           |                                   |                             | 2 bits for subpriority
  *    --------------------------------------------------------------------------------------------------------------------------
  *     NVIC_PriorityGroup_3  |                0-7                |            0-1              | 3 bits for pre-emption priority
  *                           |                                   |                             | 1 bits for subpriority
  *    --------------------------------------------------------------------------------------------------------------------------
  *     NVIC_PriorityGroup_4  |                0-15               |            0                | 4 bits for pre-emption priority
  *                           |                                   |                             | 0 bits for subpriority
  *    ==========================================================================================================================
  */
#define NVIC_PRIORITY_GROUP		NVIC_PriorityGroup_1

#if FATFS_USE_DETECT_PIN_EXTI > 0
#define CARD_DETECT_PREEMPTION_PRIORITY		1
#define CARD_DETECT_SUB_PRIORITY			7
#endif

#if	FATFS_USE_SDIO > 0
#define SD_SDIO_PREEMPTION_PRIORITY			1
#define SD_SDIO_SUB_PRIORITY				0
#define SD_SDIO_DMA_PREEMPTION_PRIORITY		1
#define SD_SDIO_DMA_SUB_PRIORITY			0
#endif

#define CAN1_PREEMPTION_PRIORITY			1
#define CAN1_SUB_PRIORITY					1

#define TIM_PREEMPTION_PRIORITY				1
#define TIM_SUB_PRIORITY					6


/********************************************************** CAN *****************************************************************************/

/* CAN Identifiers */
/*
#define CAN_ID_ECU_PE1 	0x0CFFF048 	// 	0 1100 1111 1111 1111 0000 0100 1000
#define CAN_ID_ECU_PE2 	0x0CFFF148 	// 	0 1100 1111 1111 1111 0001 0100 1000
#define CAN_ID_ECU_PE3 	0x0CFFF248 	// 	0 1100 1111 1111 1111 0010 0100 1000
#define CAN_ID_ECU_PE4 	0x0CFFF348 	// 	0 1100 1111 1111 1111 0011 0100 1000
#define CAN_ID_ECU_PE5 	0x0CFFF448 	// 	0 1100 1111 1111 1111 0100 0100 1000
#define CAN_ID_ECU_PE6 	0x0CFFF548 	// 	0 1100 1111 1111 1111 0101 0100 1000
#define CAN_ID_ECU_PE7 	0x0CFFF648 	// 	0 1100 1111 1111 1111 0110 0100 1000
*/

typedef struct {
	uint32_t ID;
	uint16_t Adress[16];
}HUB_TypeDef;

typedef struct {
	HUB_TypeDef HUB [14];
	uint32_t Mask;
}CAN_ID_TypeDef;

#define	CAN_ID_HUB12	0x12FFF048	//	1 0010 1111 1111 1111 0000 0100 1000*** Lowest Priority ***
#define	CAN_ID_HUB11	0x11FFF048	//	1 0001 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB10	0x10FFF048	//	1 0000 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB9		0x0FFFF048	//	0 1111 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB8		0x0EFFF048	//	0 1110 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB7		0x0DFFF048	//	0 1101 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB6		0x0CFFF048	//	0 1100 1111 1111 1111 0000 0100 1000 ECU
#define	CAN_ID_HUB5		0x0BFFF048	//	0 1011 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB4		0x0AFFF048	//	0 1010 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB3		0x09FFF048	//	0 1001 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB2		0x08FFF048	//	0 1000 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB1		0x07FFF048	//	0 0111 1111 1111 1111 0000 0100 1000
#define	CAN_ID_HUB0		0x06FFF048	//	0 0110 1111 1111 1111 0000 0100 1000 *** Highest Priority ***

#define	CAN_ID_MASK		0x1F000000	//	1 1111 0000 0000 0000 0000 0000 0000

//enum CAN_ID = { CAN_ID_HUB0, CAN_ID_HUB1, CAN_ID_HUB2, CAN_ID_HUB3, CAN_ID_HUB4, CAN_ID_HUB5, CAN_ID_ECU, CAN_ID_HUB7, CAN_ID_HUB8, CAN_ID_HUB9, CAN_ID_HUB10, CAN_ID_HUB11, CAN_ID_HUB12, CAN_ID_HUB13, }



/* CAN Filters */
#define CAN_FILTER_ECU_NUMBER				12
#define CAN_FILTER_ECU_ID					0x00000002<<3//0x0CFFF048 // 0 1100 1111 1111 1111 0000 0100 1000
#define CAN_FILTER_ECU_MASK					0x1FFFFFFF<<3//0x1FFFF0FF // 1 1111 1111 1111 1111 0000 1111 1111
#define CAN_FILTER_ECU_ASSIGMENT			CAN_FIFO1



/*CAN_FilterInitStructure.CAN_FilterNumber = 1;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
*/
#endif
