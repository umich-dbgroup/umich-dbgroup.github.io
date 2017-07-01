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
 // This class accepts the program options provided by the users and set 
 // the configuration parameters of the data set accordingly.  
 //
 // Generate a set of XML documents with three different scaling 
 //			factors (1,10,100).  The default scale factor is 1.
 //@}
 *
 * Filename:   DataGen.h
 ****************************************************************************/
#ifndef _DATA_GENERATOR_H
#define _DATA_GENERATOR_H

#include <string.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <assert.h>
#include <iomanip.h>

#ifdef _MSC_VER
	#include <strstrea.h>
#else
	#include <strstream.h>
#endif

#include "StrGen.h"
#include "Config.h"

#ifdef use_namespace
namespace MBENCH {
#endif 

// maximum number of characters of the prefix of the document name
const int PREFIX_FILENAME_LEN = 10;

class DataGen {
	friend class DocGen;
public:
	//@{
	// Default constructor
	//@}
	DataGen();


	//@{
	// Destructor
	//@}
	~DataGen();

	

	//@{
	// Set the scaling factor of the generated document
	// @param  scaleFactor  The scaling factor of the document
	//@}
	void setScaleFactor(int scaleFactor);



	//@{
	// Print program usage
	//@}
	void printUsage();


	//@{
	// Turn on/off schema support
	//@}
	void toggleSchemaSupport();


	//@{
	// Turn on/off print element content
	//@}
	void togglePrtElemCont();
	
	//@{
	// Set the root level of the document in the data set
	// When the root level = 1, there is a single document generated
	// When the root level > 1, there are multiple documents generated.
	// The number of generated documents is equal to the number 
	// of fanout of nodes at that level.
	//@}
	void setRootLevel(int _rootLevel) {
		rootLevel = _rootLevel;
	}

	//@{
	// Set the deepest level of the document in the data set
	//@}
	void setDeepestLevel(int _deepestLevel) {
		deepestLevel = _deepestLevel;
	}

	//@{
	// Write documents in the data set
	//@}
	void writeDocs();

	//@{
	// Set the prefix of the document file name
	//@}
	void setDocName(char *prefix) {
		strcpy(filenamePrefix,prefix);
	}

private:
	
	// prefix filename of XML documents
	char filenamePrefix[PREFIX_FILENAME_LEN];

	// scale factor
	ScaleFactor scaleFactor;

	// boolean to tell us whether it supports XML schema
	bool supportSchemaFlag;

	// boolean to tell us whether to print element content
	bool prtElemContFlag;

	// root level of the documents in the data set
	int rootLevel;

	// deepest level
	int deepestLevel;

};

#ifdef use_namespace
}
#endif 

#endif








