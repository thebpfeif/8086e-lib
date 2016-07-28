/*	File name: eu_stack.c
Description: Handles the pushing and popping commands on the stack
and maintains the stack pointer 
Abbreviation Notes: eu = Execution Unit
*/

#include "stdint.h"

#include "eu_pub_registers.h"
#include "eu_pub_stack.h"
#include "biu_pub_registers.h"

/* constants */
//BRP: Later on, this should not be a constant 
#define STACK_SIZE 100

/* static variables */
//BRP: This will later be managed in some sort of memory file
uint8_t s_stack[ STACK_SIZE ];

void EU_stack_init( void )
{
/*local variables */
	uint16_t stack_seg; 

/* initialize the stack pointer 
   to the start of the stack segment */
	stack_seg = BIU_reg_get( BIU_SS );
	EU_16_bit_reg_set( EU_SP, stack_seg );
}

void EU_stack_push( uint16_t data )
{
	/* Local variables */
	uint8_t  low_byte; 
	uint16_t stack_pointer; 
	uint16_t stack_seg; 

	/* Get the stack pointer and stack segment */
	stack_pointer = EU_16_bit_reg_get( EU_SP ); 
	stack_seg = BIU_reg_get( BIU_SS );

	/* Verify we are not blowing the stack */
	if ( stack_pointer > stack_seg + 1 )
	{
		/* save low byte, shift high byte */
		low_byte = ( data & 0x0F );
		data = ( data >> 8 ); 

		/* write high byte to the stack */
		s_stack[ stack_pointer ] = ( uint8_t )data; 

		/* decrement pointer */
		stack_pointer--; 

		/* write low byte to the stack*/
		s_stack[ stack_pointer ] = low_byte; 

		/* decrement the stack pointer */
		stack_pointer--;

		/* save the stack pointer */
		EU_16_bit_reg_set( EU_SP, stack_pointer );
	}
	else
	{
		/* Need to come up with some sort of assert */
	}
}

uint16_t EU_stack_pop( void )
{
	/* Local variables */
	uint16_t stack_pointer; 
	uint16_t stack_data;
	uint8_t  low_byte; 

	/* Get the stack pointer */
	stack_pointer = EU_16_bit_reg_get( EU_SP );

	/* Verify we are not blowing the stack */
	if (stack_pointer - 1 < STACK_SIZE)
	{
		/* increment the stack pointer */
		stack_pointer++; 

		/* copy low byte from stack */
		low_byte = s_stack[ stack_pointer ];

		/* increment stack pointer */
		stack_pointer++; 

		/* copy high byte from stack */
		stack_data = s_stack[ stack_pointer ];

		/* shift high byte to upper 8 bits and OR low byte */
		( stack_data << 8 );
		stack_data |= low_byte; 
	}
	
	return( stack_data );
}

