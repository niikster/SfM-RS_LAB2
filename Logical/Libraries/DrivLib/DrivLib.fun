
{REDUND_ERROR} FUNCTION_BLOCK LedStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : {REDUND_UNREPLICABLE} states;
	END_VAR
	VAR_OUTPUT
		led1 : BOOL;
		led2 : BOOL;
		led3 : BOOL;
		led4 : BOOL;
		timer : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK DoorStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : {REDUND_UNREPLICABLE} states;
		sw1 : BOOL;
		sw2 : BOOL;
		sw3 : BOOL;
		sw4 : BOOL;
		direction : BOOL;
	END_VAR
	VAR_OUTPUT
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DriveStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : {REDUND_UNREPLICABLE} states;
		enable : {REDUND_UNREPLICABLE} BOOL;
	END_VAR
	VAR_OUTPUT
		command : {REDUND_UNREPLICABLE} UINT;
		speed : {REDUND_UNREPLICABLE} INT;
	END_VAR
END_FUNCTION_BLOCK
