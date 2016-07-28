
/* TYPES */

typedef uint8_t EU_flag_reg_t8;
enum
{
	EU_CF,					/* carry flag			*/
	EU_U_1,					/* undefined			*/
	EU_PF,					/* parity flag			*/
	EU_U_2,					/* undefined			*/					
	EU_AF,					/* auxiliary carry flag */
	EU_U_3,					/* undefined			*/			 
	EU_ZF,					/* zero flag			*/
	EU_SF,					/* sign flag			*/
	EU_TF,					/* trap flag			*/ 
	EU_IF,					/* interrupt flag		*/	
	EU_DF,					/* direction flag		*/
	EU_OF,					/* overflow flag		*/
	EU_RSRV_1,				/* reserved				*/
	EU_RSRV_2,				/* reserved				*/
	EU_RSRV_3,				/* reserved				*/
	EU_RSRV_4,				/* reserved				*/
	EU_FLAG_REG_COUNT, 
};