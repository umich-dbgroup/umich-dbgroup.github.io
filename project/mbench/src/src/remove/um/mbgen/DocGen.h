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
 // This class generate documents that have specified attributes and elements
 // according to the Michigan Benchmark (http://www.eecs.umich.edu/db/mbench
 //@}
 * 
 * Filename:   DocGen.h
 ****************************************************************************/
#ifndef _DOC_GEN_H
#define _DOC_GEN_H

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
#include "DataGen.h"

#ifdef use_namespace
namespace MBENCH {
#endif 


class DataGen;

class DocGen {
	friend class DataGen;
public:
	//@{
	// Default constructor
	//@}
	DocGen();

	//@{
	// Constructor associated with the data generator
	//@}
	DocGen(DataGen *dg);

	//@{
	// Destructor
	//@}
	~DocGen();

	//@{
	// Write document
	//@}
	void writeDoc(int docIndex);

	//@{
	// Write a set of documents in this data set
	//@}
	void writeDocs();

	//@{
	// Write statistics of the generated documents
	//@}
	void writeStats();

	//@{
	// Set configuration of the document 
	//@}
	void setConfig();	

	//@{
	// Compute number of nodes at each level.  
	//@}
	void computeNumNodes();

	//@{
	// Print out the configuration
	//@}
	void prtConfig();

private:
	
    // counter to keep track of number of nodes in each level
	// want to start to access at index = 1, so we increment
	// the number of allocated slots
	int nodes[MAX_NUM_LEVELS+1];	

	// Cumulative number of nodes at each level
	int numTotalNodes[MAX_NUM_LEVELS+1];

	// number of nodes at each level
	int numNodes[MAX_NUM_LEVELS+1];

	// number of cumulative nodes per document
	int docNumCumNodes[MAX_NUM_LEVELS+1];

	// current level that data is written in the document
	int level;

	// file(s) output stream
	ofstream fpOut;
 
	// string generator
	StrGen gs;


	// total number of nodes in the document
	int totalNumNodes;
	
	// random number generator for aUnique2
	Random aUnique2RNG;
	
	int numNodesCount; // total number of nodes
	int numENestNodes; // total number of 'eNest' nodes (counted)
	int numEOccNodes;
	int numDatasetNodes; // total number of 'eNest' nodes (estimated)

	// the data generator that it associates with
	DataGen *dg;
 
	// configuration parameters of the data set, get from
	// the data generator class 
	int rootLevel;
	int interLevel;
	int deepestLevel;
	ScaleFactor scaleFactor;

	// depends on the number of documents
	int filenameWidth;

	
	// the size of this array depends on the scale factor
	// of the document

	// these two variables to check or ensure that aUnique1 
	// and aUnique2 are really unique.
	bool *aUnique1Used;
	bool *aUnique2Used;
	
	// number of generated documents
	int numDocs;

	int curNumNodes;
	int curNumDocs;
	

	//-------------- private methods ---------------------------------
	//@{
	// Initialize fanout and node counters in each level
	//@}
	void initDoc();

	//@{
	// Write begin element tag
	// @param elemName Element tag name
	// @param level Level of the element 
	//@}
	void writeBeginTag(const char *elemName, int level);


	//@{
	// Write end element tag
	// @param elemName Element tag name
	// @param level Level of the element 
	//@}
	void writeEndTag(const char *elemName, int level);
	

	//@{
	// Write element content
	// @param fpOut File output stream of the document
	// @param elemContent Element content 
	//@}
	void writeContent(const char *elemContent);

	//@{
	// Write element
	// recursive function
	//@}
	void writeElem();

	//@{
	// Write long string
	// @param aUnique1 The value of aUnique1 attribute
	// @param aSixtyFour The value of aSixtyFour attribute
	//@}
	void writeStrAttrs(int aUnique1, int aSixtyFour);

	//@{
	// Write optional eOccasional element
	// @param aUnique1 The value of aUnique1 attribute
	// @param aSixtyFour The value of aSixtyFour attribute
	// @param str The string content of eOccasional element
	//@}
	void write_eOccasional(int aUnique1, int aSixtyFour, char *str);

	//@{
	// Write document declaration
	//@}
	void writeDocDeclaration();

	//@{
	// Write DTD declaration
	//@}
	void writeDTDDeclaration();

	//@{
	// Compute aUnique1 attribute
	//@}
	int computeAUnique1();

	//@{
	// Compute aUnique2 attribute
	//@}
	int computeAUnique2();

	//@{
	// Compute other attributes based on aUnique2
	// @param baseNum The base number
	// @param modNum The mod number
	//@}
	int computeAttr(int baseNum, int modNum);

	//@{
	// Compute aRef attribute
	// @param parentID The parentID of the element of the element that
	//                 aRef attribute is belong to
	//@}
	int computeARef(int parentID);

};

#ifdef use_namespace
}
#endif 

#endif








