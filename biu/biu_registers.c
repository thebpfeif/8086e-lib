/*	File name: eu_registers.c
Description: Handles the basic storage, input and output processing
for all 8086 registers
Abbreviation Notes: biu = business interface unit 
*/

#include "stdint.h"
#include "string.h"

#include "biu_pub_registers.h"

static uint16_t s_reg_array[ BIU_REG_COUNT ];

void BIU_reg_init( void )
{
	memset( s_reg_array, 0x00, sizeof( s_reg_array[ BIU_REG_COUNT ] ) );
}

void BIU_reg_set( BIU_reg_t8 reg, uint16_t val )
{
	if (reg < BIU_REG_COUNT)
	{
		/* set register to requested value */
		s_reg_array[ reg ] = val;
	}
}

uint16_t BIU_reg_get( BIU_reg_t8 reg )
{
	/* local variables */
	uint16_t val = 0;

	if (reg < BIU_REG_COUNT)
	{
		/* set value of register to val */
		val = s_reg_array[ reg ];
	}

	return ( val );
}