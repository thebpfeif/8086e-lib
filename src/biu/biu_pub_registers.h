#pragma once

/* TYPES */
typedef uint8_t BIU_reg_t8;
enum
{
	BIU_CS,				/* code segment					*/
	BIU_DS,				/* data segment					*/
	BIU_SS,				/* stack segment				*/
	BIU_ES,				/* extra segment				*/
	BIU_IP,				/* instruction pointer			*/
	BIU_REG_COUNT	/* total biu 16-bit reg count	*/
};

/* PROCEDURES */
void BIU_reg_init
( 
	void 
);

uint16_t BIU_reg_get
( 
	BIU_reg_t8 reg 
);

void BIU_reg_set
( 
	BIU_reg_t8 reg, 
	uint16_t val 
);