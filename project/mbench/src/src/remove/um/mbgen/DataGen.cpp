/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *
 * Filename:   DataGen.cpp
 ****************************************************************************/


#include "DataGen.h"
#include "DocGen.h"
#include "ErrorHandlers.h"
#include <math.h>
#include <time.h>

//=============================================================================
// Constructor.
// Initialize common default settings of documents in the data set.
//=============================================================================
DataGen::DataGen() {
	// Enum are defined for scale factors to be easily indexed in an array
	// Valid scale factors are 1,10,100.  
	scaleFactor = one;
	supportSchemaFlag = true;
	prtElemContFlag = true;
	supportDTDFlag = false;
	rootLevel = 1;
	interLevel = MAX_NUM_LEVELS;
	deepestLevel = MAX_NUM_LEVELS;
	strcpy(filenamePrefix,"doc");
}



//=============================================================================
// Destructor.
//=============================================================================
DataGen::~DataGen() {

}


//=============================================================================
// Set scale factor as requested.  Currently, only 3 options of scale factors
// are available: 1,10, and 100
//=============================================================================
void DataGen::setScaleFactor(int _scaleFactor) {
	if (_scaleFactor == 1) {
				scaleFactor = one;
	} else if (_scaleFactor == 10) {
				scaleFactor = ten;
	} else if (_scaleFactor == 100) {
				scaleFactor = oneHundred;
	}
}

//=============================================================================
// Print options of the program generator
// Available options allow the users to
//  - Set the scale factor. Valid values are {1,10,100}
//  - Set the root level of the data set. Valid values are {1-16} 
//  - Set the deepest level of the data set.  Valid values are {1-16}
//  - Set the prefix of the document name
//  - Set the schema support flag
//  - Print available options  
//=============================================================================

void DataGen::printUsage() {
	cerr << "usage: mbgen (options)" << endl;
	cerr << "options:" << endl;
	cerr.setf(ios::left);
	
	// scale factor
	cerr << setw(5)  << ""  << setw(20) << "-sf=scale_factor" 
		 << setw(50) << "Valid scale factors are {1,10,100} [default=1]" 
		             << endl;
	// root level
	cerr << setw(5)  << ""  << setw(20) << "-rl=root_level"		  
		 << setw(50) << "Set the root level of the data set" << endl 
		 << setw(25) << " " 
		 << setw(50) << "Valid root levels are {1-16} [default=1]" 
		             << endl;

	// deepest level
	cerr << setw(5)  << ""  << setw(20) << "-dl=deepest_level"		  
		 << setw(50) << "Set the deepest level of the data set" << endl 
		 << setw(25) << " " 
		 << setw(50) << "Valid deepest levels are {1-16} [default=16]" 
		             << endl;

	// document name
	cerr << setw(5)  << ""  << setw(20) << "-n=doc_name"		  
		 << setw(50) << "Set document file name [default='doc'] " << endl;

	// schema support
	cerr << setw(5)  << ""  << setw(20) << "-s | -S"		  
		 << setw(50) << "Turn on/off schema support [default=on]" << endl;

	// print element content
	cerr << setw(5)  << ""  << setw(20) << "-c | -C"		  
		 << setw(50) << "Turn on/off element content printed out [default=on]" << endl;

	// DTD support
	cerr << setw(5)  << ""  << setw(20) << "-d | -D"		  
		 << setw(50) << "Turn on/off DTD support [default=off]" << endl;

	// print program usage
	cerr << setw(5)  << ""  << setw(20) << "-h | -H" 
		 << setw(50) << "Print available options" << endl;

	exit(0);
}

// Change schema support flag
//=============================================================================
void DataGen::toggleSchemaSupport() {
	supportSchemaFlag = !supportSchemaFlag;
}

// Change print element content flag
//=============================================================================
void DataGen::togglePrtElemCont() {
	prtElemContFlag = !prtElemContFlag;
}


// Change DTD support flag
//=============================================================================
void DataGen::toggleDTDSupport() {
	supportDTDFlag = !supportDTDFlag;
}

//=============================================================================
// Write XML documents
//=============================================================================
void DataGen::writeDocs() {
	DocGen docGen(this);
	docGen.writeDocs();
}

int main(int argC, char *argV[]) {
	DataGen dg;

	int argInd;
	for (argInd = 1; argInd < argC; argInd++) {

		// Break out on first non-dash parameter
		if (argV[argInd][0] != '-')
			break;
		
		// scale factor
		if (!strncmp(argV[argInd],"-sf=",4)  ||
			!strncmp(argV[argInd],"-SF=",4)) {
			const char* const param = &argV[argInd][4];
			int sf = atoi(param);
			if (sf == 1) {
				dg.setScaleFactor(1);
			} else if (sf == 10) {
				dg.setScaleFactor(10);
			} else if (sf == 100) {
				dg.setScaleFactor(100);
			} else {	
				cerr << sf << " is NOT a valid scale factor. ";
				cerr << "Valid scale factors are {1,10,100}" 
				     << endl;
			}	 

		// schema support
		} else if (!strcmp(argV[argInd],"-s") ||
				   !strcmp(argV[argInd],"-S")) {
			dg.toggleSchemaSupport();
		// print element content
		} else if (!strcmp(argV[argInd],"-c") ||
				   !strcmp(argV[argInd],"-C")) {
			dg.togglePrtElemCont();
		// DTD support
		} else if (!strcmp(argV[argInd],"-d") ||
				   !strcmp(argV[argInd],"-D")) {
			dg.toggleDTDSupport();
		// root level
		} else if (!strncmp(argV[argInd],"-rl=",4)  ||
			       !strncmp(argV[argInd],"-RL=",4)) {
			const char* const param = &argV[argInd][4];
			int rootLevel = atoi(param);
			if (rootLevel >=1 && rootLevel <= MAX_NUM_LEVELS) {
				dg.setRootLevel(rootLevel);
			} else {
				cerr << rootLevel 
				     << " is NOT a valid root level. ";
				cerr << "Valid root levels are {1,2,3,...,"
					 << MAX_NUM_LEVELS << "}" 
				     << endl;
				exit(1);
			}

		// deepest level
		} else if (!strncmp(argV[argInd],"-dl=",4)  ||
			       !strncmp(argV[argInd],"-DL=",4)) {
			const char* const param = &argV[argInd][4];
			int deepestLevel = atoi(param);
			if (deepestLevel >=1 && deepestLevel <= MAX_NUM_LEVELS) {
				dg.setDeepestLevel(deepestLevel);
			} else {
				cerr << deepestLevel 
				     << " is NOT a valid deepest level. ";
				cerr << "Valid root levels are {1,2,3,...,"
					 << MAX_NUM_LEVELS << "}" 
				     << endl;
				exit(1);
			}
        // root level
		} else if (!strncmp(argV[argInd],"-il=",4)  ||
			       !strncmp(argV[argInd],"-IL=",4)) {
			const char* const param = &argV[argInd][4];
			int interLevel = atoi(param);
			if (interLevel >=1 && interLevel <= MAX_NUM_LEVELS) {
				dg.setInterLevel(interLevel);
			} else {
				cerr << interLevel
				     << " is NOT a valid intermediate level. ";
				cerr << "Valid root levels are {1,2,3,...,"
					 << MAX_NUM_LEVELS << "}" 
				     << endl;
				exit(1);
			}

		// prefix document name
		} else if (!strncmp(argV[argInd],"-n=",3) ||
				   !strncmp(argV[argInd],"-N=",3)) {
			dg.setDocName(&argV[argInd][3]);

		// print help info
		} else if (!strcmp(argV[argInd],"-h") ||
				   !strcmp(argV[argInd],"-H")) {
			dg.printUsage();

		} else {
			cerr << "Unknown option," << argV[argInd] << endl;
			dg.printUsage();
		}
	}

	// start timing
	clock_t start, end;
	start = clock();

	// write documents
	dg.writeDocs();

	// end timing
	end = clock();

	cerr << endl << "Document generation time is "
		 << (end - start)/CLOCKS_PER_SEC  << " seconds " << endl; 

	return 0;
}

