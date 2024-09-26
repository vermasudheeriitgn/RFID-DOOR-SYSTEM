/*
 * keypad.c
 *
 *  Created on: Apr 20, 2024
 *      Author: APURVA
 */


/*
 * keypad.c
 *
 *  Created on: Apr 12, 2024
 *      Author: APURVA
 */


#include "stm32f4xx.h"

#include "keypad.h"

static char decode_keypad(uint8_t col, uint8_t row);



const unsigned char keymap[4][4]=
	{
		{'1', '2', '3', 'A' },
		{'4', '5', '6', 'B' },
		{'7', '8', '9', 'C' },
		{'*', '0', '#', 'D' }


	};


const uint32_t clo_state[4]={	(GPIO_BSRR_BR12|GPIO_BSRR_BS10|GPIO_BSRR_BS6|GPIO_BSRR_BS7),
						(GPIO_BSRR_BS12|GPIO_BSRR_BR10|GPIO_BSRR_BS6|GPIO_BSRR_BS7),
						(GPIO_BSRR_BS12|GPIO_BSRR_BS10|GPIO_BSRR_BR6|GPIO_BSRR_BS7),
						(GPIO_BSRR_BS12|GPIO_BSRR_BS10|GPIO_BSRR_BS6|GPIO_BSRR_BR7)
};




void keypad_init(void)
{

	/*Enable clock access to GPIOC*/
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;

	/*Set PC0 to PC3 as input*/
	GPIOC->MODER &= ~(GPIO_MODER_MODE0|GPIO_MODER_MODE11|GPIO_MODER_MODE2|GPIO_MODER_MODE3);

	/* Activate internal pullup resistor for PC0 to PC3*/
	GPIOC->PUPDR|=GPIO_PUPDR_PUPD0_0|GPIO_PUPDR_PUPD11_0|GPIO_PUPDR_PUPD2_0|GPIO_PUPDR_PUPD3_0;

	/*Set PC4 to PC7 as output*/
	GPIOC->MODER |= GPIO_MODER_MODE12_0|GPIO_MODER_MODE10_0|GPIO_MODER_MODE6_0|GPIO_MODER_MODE7_0;

	GPIOC->MODER &=~( GPIO_MODER_MODE12_1|GPIO_MODER_MODE10_1|GPIO_MODER_MODE6_1|GPIO_MODER_MODE7_1);

	/*Set PC4 to PC7 as high*/

	GPIOC->BSRR = GPIO_BSRR_BS12|GPIO_BSRR_BS10|GPIO_BSRR_BS6|GPIO_BSRR_BS7;
}


char keypad_read(void)
{

	unsigned char key=0,data=0;

	for (int i=0;i<4;i++)
	{

		GPIOC->BSRR=clo_state[i];

		data=(GPIOC->IDR)&0xF; /*Get rid of data from bit 5 to bit31*/

		if(data != 0xF)
		{
			key=decode_keypad(i,data);
		}

	}

	return key;
}


static char decode_keypad(uint8_t col, uint8_t row)
{

	if (row == 0xE) return keymap[0][col];
	if (row == 0xD) return keymap[1][col];
	if (row == 0xB) return keymap[2][col];
	if (row == 0x7) return keymap[3][col];
	return 0;
}
