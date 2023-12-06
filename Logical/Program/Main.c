#include "DrivLib.h"
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif


void _INIT ProgramInit(void)
{
	drive_sm.enable = 1;
	door_sm.state = ST_INIT;
}

void _CYCLIC ProgramCyclic(void)
{
	led_sm.state = door_sm.state;
	DriveStateMachine(&drive_sm);
	speed = door_sm.speed;
	DoorStateMachine(&door_sm);
	LedStateMachine(&led_sm);
}

void _EXIT ProgramExit(void)
{
	drive_sm.enable = 0;
	door_sm.state = ST_INIT;
}

