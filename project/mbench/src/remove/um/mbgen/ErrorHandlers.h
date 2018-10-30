/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *		
 * Description: 
//@{
// This class checks and handles error conditions
//
//@}
 *
 * Filename:   ErrorHandlers.h
 ****************************************************************************/

#ifndef _ERROR_HANDLERS_H
#define _ERROR_HANDLERS_H

 

#ifdef use_namespace
namespace MBENCH {
#endif

//@{
// Print out the error message and then exit the program
// @param errMsg  The error message to be printed out
//@}	
void exitError(const char *errMsg);

//@{
// Check whether the error condition is true.  If it is,
// then call 'exitError'.  
// @param errCond The error condition
// @param errMsg  The error message to be printed out
//@}
void checkError(const bool errCond, const char *errMsg);

#ifdef use_namespace
}
#endif 
#endif