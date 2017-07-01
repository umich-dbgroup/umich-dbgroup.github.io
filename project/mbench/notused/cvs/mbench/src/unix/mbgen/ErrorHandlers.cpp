/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *		
 * Description: Check and handle error conditions
 *
 * Filename:   ErrorHandlers.cpp
 ****************************************************************************/
//
// Definitions of ErrorHandler functions
//
#include "ErrorHandlers.h"
#include <iostream.h>
#include <stdlib.h>


//============================================================================
// Print an error message and then exit
//============================================================================
void exitError(const char *msg) {
	//cerr << "Data Generator error:" << msg << endl;
	cerr << msg << endl;
	exit(1);
}  

//============================================================================
// Check if the error condition, 'errCond', is true.  
// If it is, print an error and then exit
//============================================================================
void checkError(const bool errCond, const char *msg) {
	if (errCond == true) {
		exitError(msg);
	} 
		
}  