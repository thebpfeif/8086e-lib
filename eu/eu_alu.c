/*	File name: eu_alu.c
Description: Handles the ALU (arithmetic logic unit) processing 
for the 8086 emulator 
Abbreviation Notes: eu = Execution Unit
*/

#include "stdint.h"

#include "eu_pub_alu.h"
#include "eu_pub_flags.h"

/* 16-bit Move instruction */
void EU_mov( uint16_t * dest, uint16_t * src )
{
	/* copy the data from the source 
	address to destination address */
	*dest = *src; 
}

void EU_add( uint16_t * dest, uint16_t * src )
{
	//BRP TODO: Verify only one address is located in memory 

	//BRP TODO: Modify flag register 

	/* Add source to destination and 
	store in destination */
	*dest = *dest + *src; 

}
