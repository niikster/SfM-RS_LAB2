
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DrivLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */

	// direction = 0 -> door is opening
	// direction = 1 -> door is closing

	// sensors are placed as follows:
	// OPENED s0 -- s1 -- s2 -- s3 CLOSED
	// sw1 = s0 -> sw1 == OPENED
	// sw2 = s1
	// sw3 = s2
	// sw4 = s3 -> sw4 == CLOSED

	// lights defenitions:
	// * - light is blinking (the door is going to that sensor)
	// 0 - lights off
	// 1 - lights on
void LedStateMachine(struct LedStateMachine* inst)
{
	inst->timer +=1;
	switch(inst->state){
		// INIT and UNKNOWN
		case ST_INIT:
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_UNKNOWN: // state UNKNOWN -> ****
			if(inst->timer % 25 == 0){
				inst->led1 = !inst->led1;
				inst->led2 = inst->led1;
				inst->led3 = inst->led1;
				inst->led4 = inst->led1;
			}
			break;
		
		// from closed to open
		case ST_CLOSED: // full closed
						// 1111
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		case ST_OP: // from full closed stating to open
					// 11*0
			inst->led1 = 1;
			inst->led2 = 1;
			if(inst->timer % 15 == 0) inst->led3 = !inst->led3;
			inst->led4 = 0;
			break;
		case ST_ACC_OP: // middle
						// 1*00
			inst->led1 = 1;
			if(inst->timer % 15 == 0) inst->led2 = !inst->led2;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_SLOW_OP: // almost opened
						 // *000
			if(inst->timer % 15 == 0) inst->led1 = !inst->led1;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_OPENED: // full opened 
						// 0000
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		// from opened to close
		case ST_CL:		// 1*00
			inst->led1 = 1;
			if(inst->timer % 15 == 0) inst->led2 = !inst->led2;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_ACC_CL: // 11*0
			inst->led1 = 1;
			inst->led2 = 1;
			if(inst->timer % 15 == 0) inst->led3 = !inst->led3;
			inst->led4 = 0;
			break;
		case ST_SLOW_CL: // 111*
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			if(inst->timer % 15 == 0) inst->led4 = !inst->led4;
			break;
	}
		
}
