#pragma once

/* TYPES */
typedef uint8_t EU_reg_16_t8;
enum
{
	EU_AX,				/* accumulator					*/
	EU_BX,				/* base addressing				*/
	EU_CX,				/* counter loop					*/
	EU_DX,				/* data pointer					*/
	EU_DI,				/* destination index			*/
	EU_SI,				/* source index					*/
	EU_SP,				/* stack pointer				*/
	EU_BP,				/* base pointer					*/
	EU_REG_16_COUNT		/* total eu 16-bit reg count	*/
};

typedef uint8_t EU_reg_8_t8; 
enum
{
	EU_AH,				/* high-byte accumulator			*/
	EU_AL,				/* low-byte accumulator				*/
	EU_BH,				/* high-byte base addresser			*/
	EU_BL,				/* low-byte base addresser			*/
	EU_CH,				/* high-byte looper counter			*/
	EU_CL,				/* low-byte looper counter			*/
	EU_DH,				/* high-byte data pointer			*/
	EU_DL,				/* low-byte data pointer			*/
	EU_REG_8_COUNT		/* total eu 8-bit reg count			*/
};

/* PROCEDURES */

void EU_16_bit_reg_init
( 
	void 
);

uint16_t EU_16_bit_reg_get
( 
	EU_reg_16_t8 reg 
);

void EU_16_bit_reg_set
( 
	EU_reg_16_t8 reg, 
	uint16_t val 
);

void EU_8_bit_reg_set
( 
	EU_reg_8_t8 reg, 
	uint8_t val 
);
