
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
	// CLOSED s3 -- s2 -- s1 -- s0 OPENED
	// sw1 = s0 -> sw1 == opened
	// sw2 = s1
	// sw3 = s2
	// sw4 = s3 -> sw4 == closed

void DoorStateMachine(struct DoorStateMachine* inst)
{
	switch(inst->state){
	// INIT and UNKNOWN
		case ST_INIT:
			inst->state = ST_UNKNOWN;
		// dodelat'
		case ST_UNKNOWN:
			inst->speed = 200;
			if(inst->sw4)
				inst->state = ST_OP;
			else if(inst->sw3)
				inst->state = ST_ACC_OP;
			else if(inst->sw2)
				inst->state = ST_SLOW_OP;
			else if(inst->sw1)
				inst->state = ST_OPENED;
			break;
		
		// fully closed/opened states
			case ST_CLOSED:
				inst->speed = 0;
				if(inst->direction == 0) // if in closed state the dir changed to opening
					inst->state = ST_OP; // normal opening
				break;
			case ST_OPENED:
				inst->speed = 0;
				if(inst->direction == 1) // if in open state the dir is to close
					inst->state = ST_CL; // normal closing
				break;
		
		// dir = 1
		// closing
			case ST_CL:
				inst->speed = -200;
				if(inst->direction == 0)
					inst->state = ST_SLOW_OP;
				else if(inst->sw2)
					inst->state = ST_ACC_CL;
				break;
			case ST_ACC_CL:
				inst->speed = -700;
				if(inst->direction == 0) 
					inst->state = ST_ACC_OP;
				else if(inst->sw3)
					inst->state = ST_SLOW_CL;
				break;
			case ST_SLOW_CL:
				inst->speed = -200;
				if(inst->direction == 0) 
					inst->state = ST_OP;
				else if(inst->sw4)
					inst->state = ST_CLOSED;
				break;
		
		// dir == 0
		// opening
			case ST_OP:
				inst->speed = 200;
				if(inst->direction == 1)
					inst->state = ST_SLOW_CL;
				else if(inst->sw3)
					inst->state = ST_ACC_OP;
				break;
			case ST_ACC_OP:
				inst->speed = 700;
				if(inst->direction == 1)
					inst->state = ST_ACC_CL;
				else if(inst->sw2)
					inst->state = ST_SLOW_OP;
				break;
			case ST_SLOW_OP:
				inst->speed = 200;
				if(inst->direction == 1)
					inst->state = ST_CL;
				else if(inst->sw1)
					inst->state = ST_OPENED;
				break;
		}
		
}
