/* ###################################################################
 **     Filename    : main.c
 **     Project     : OSv1
 **     Processor   : MC9S08QE8CLC
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2018-01-12, 16:05, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "OSV1.h"
#define LED PTCD_PTCD0
#define LED2 PTCD_PTCD1
/* User includes (#include below this line is not maintained by Processor Expert) */
void toto_func(void) {
	PTCDD_PTCDD0 = 1;
	LED = 1;
	os_sleep(500);
	LED = 0;
	os_sleep(500);
}
void titi_func(void) {
	PTCDD_PTCDD0 = 1;
	LED2 = 1;
	os_sleep(500);
	LED2 = 0;
	os_sleep(500);
}
void main(void) {
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	PE_low_level_init();

	os_init();
	process_init(&processes[0], "TOTO", toto_func);
	process_init(&processes[1], "TITI", titi_func);
	process_start(&processes[0]);
	process_start(&processes[1]);
	os_start();
	for (;;) {
	}
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* Forexample: for(;;) { } */

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale HCS08 series of microcontrollers.
 **
 ** ###################################################################
 */
