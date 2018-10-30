/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *		
 * Description: Generate a set of XML documents with three different scaling 
 *				factors (1,10,100).  The default scaling factor is 1.
 *
 *
 * Filename:   DocGen.cpp
 ****************************************************************************/


#include "DocGen.h"
#include "ErrorHandlers.h"
#include <math.h>

// element tag name
const char *BASETYPE_ELEM_NAME = "eNest";
const char *OCCASIONAL_ELEM_NAME = "eOccasional";
const char *ROOT_ELEM_NAME = "root";

const int CONST_ATTR1 = 4;
const int CONST_ATTR2 = 16;
const int CONST_ATTR3 = 64;

const int MAX_STR_LENGTH = 600;

const int ROOT_ID = 1;

// namespace references
const char *XMLNS_XSI = "\"http://www.w3.org/2001/XMLSchema-instance\"";
const char *SCHEMA_LOCATION ="\"http://www.eecs.umich.edu/db/mbench/bm.xsd\"";

const int NUM_NODES_PRINT_STEP = 10000;



//=============================================================================
// Constructor.
//=============================================================================
DocGen::DocGen() {
}

DocGen::DocGen(DataGen *_dg) {
	dg = _dg;
}


//=============================================================================
// Destructor.
//=============================================================================
DocGen::~DocGen() {
}


//=============================================================================
// Set configuration of the document according to the scaling factor.
// The configuration here includes the number of (cumulative) nodes at
// each level and number of nodes in the document
//=============================================================================
void DocGen::setConfig() {
	int i;

	// copy these variables to avoid the overhead in making references
	rootLevel = dg->rootLevel;
	deepestLevel = dg->deepestLevel;
	scaleFactor = dg->scaleFactor;

	// initialize counter at each level.  this is useful for 
	// aUnique1 assignment
	for (i = rootLevel; i <= deepestLevel; i++) {
		nodes[i] = 1;
	}

	// compute number of nodes at each level
	computeNumNodes();

	// we need to have a unique random number generated for aUnique2 attribute
	// initialize flag of each number not used.  we need to do this to 
	// ensure that we don't reuse the numbers that were 
	// already used.
	numDocs = numNodes[rootLevel];
	if (rootLevel == 1) 
		numDatasetNodes = numTotalNodes[deepestLevel];
	else
		numDatasetNodes = docNumCumNodes[deepestLevel]*numDocs;
	aUnique1Used = new bool[numDatasetNodes+1];
	aUnique2Used = new bool[numDatasetNodes+1];
	for (i = 1; i <= numDatasetNodes; i++) {
		aUnique1Used[i] = false;
		aUnique2Used[i] = false;
	}



}
 


//=============================================================================
// Set number of nodes at each level according to the scale factor
// This function depends on the fanout at each level which is defined in the 
// constant global variable 'fanout' 
//=============================================================================
void DocGen::computeNumNodes() {
	int l;
	
	// init num nodes per level per data set
	numNodes[0] = 0;
	numNodes[1] = 1;
	for (l = 2; l <= MAX_NUM_LEVELS; l++) {
		numNodes[l] = static_cast<int>(numNodes[l-1]*fanout[scaleFactor][l-1]);
	}

	numTotalNodes[0] = 0;
	numTotalNodes[1] = 1;
	for (l = 2; l <= MAX_NUM_LEVELS; l++) {	
		numTotalNodes[l] = numTotalNodes[l-1] + numNodes[l];
	}

	numDocs = numNodes[rootLevel];
	docNumCumNodes[rootLevel-1] = 0;
	docNumCumNodes[rootLevel] = 1;
	for (l = rootLevel+1; l <= MAX_NUM_LEVELS; l++) {
		docNumCumNodes[l] = docNumCumNodes[l-1] + numNodes[l]/numDocs;
	}
}

//=============================================================================
// Initialize the fanouts, node counters, and random generator methods
//=============================================================================
void DocGen::initDoc() {

	// initialize current level to be one less than rootLevel since
	// we always increment the level as we start to write begin tag


	level = rootLevel -1;

	// total number of nodes in the document
	numNodesCount = 0;

	// initialize total number of eNest nodes
	numENestNodes = 0;

	// initialize total number of eOccasional nodes
	numEOccNodes = 0;	

}

 
//=============================================================================
// Compute the reference attribute.
//=============================================================================
int DocGen::computeARef(int parentID) {

	// currently, the reference attribute is computed by subtracting
	// 11 from the parentID.
	int aRef = parentID - 11;
	if (aRef < ROOT_ID) {
			return ROOT_ID;
	} else {
			return aRef;
	}
}

//=============================================================================
// Write string attributes and element content
//=============================================================================
void DocGen::writeStrAttrs(int aUnique1, int aSixtyFour) {
  char *word = new char[MAX_WORD_LENGTH];
  char *str = new char[MAX_STR_LENGTH];

  // this is content of string attribute 
  gs.genWord(word);
  fpOut << " aString=\"";
  fpOut << "Sing a song of " << word;
  fpOut << "\">" << endl;

  if (dg->prtElemContFlag) {
	strcpy(str,"Sing a song of ");
	strcat(str,word);
	strcat(str,"\n");

	// we generate each word for each line in the template
	gs.genWord(word);
	strcat(str,"A pocket full of ");
	strcat(str,word);
	strcat(str,"\n");

	gs.genWord(word);
	strcat(str,"Four and twenty ");
	strcat(str,word);
	strcat(str,"\n");

	gs.genWord(word);
	strcat(str,"All baked in a ");
	strcat(str,word);
	strcat(str,".\n\n");

	gs.genWord(word);
	strcat(str,"When the ");
	strcat(str,word);
	strcat(str," was opened,\n");

	gs.genWord(word);
	strcat(str,"The ");
	strcat(str,word);
	strcat(str," began to sing;\n");

	gs.genWord(word);
	strcat(str,"Wasn't that a dainty ");
	strcat(str,word);
	strcat(str,"\n");

	gs.genWord(word);
	strcat(str,"To set before the ");
	strcat(str,word);
	strcat(str,"?\n\n");
  
	gs.genWord(word);
	strcat(str,"The King was in his ");
	strcat(str,word);
	strcat(str,",\n");

	gs.genWord(word);
	strcat(str,"Counting out his ");
	strcat(str,word);
	strcat(str,";\n");

	gs.genWord(word);
	strcat(str,"The Queen was in the ");
	strcat(str,word);
	strcat(str,"\n");

	gs.genWord(word);
	strcat(str,"Eating bread and ");
	strcat(str,word);
	strcat(str,".\n\n");
  
	gs.genWord(word);
	strcat(str,"The maid was in the ");
	strcat(str,word);
	strcat(str,"\n");

	gs.genWord(word);
	strcat(str,"Hanging out the ");
	strcat(str,word);
	strcat(str,";\n");

	gs.genWord(word);
	strcat(str,"When down came a ");
	strcat(str,word);
	strcat(str,",\n");

	gs.genWord(word);
	strcat(str,"And snipped off her ");
	strcat(str,word);
	strcat(str,"!\n");
	fpOut << str;  
  }

  write_eOccasional(aUnique1, aSixtyFour, str);

  delete[] word;
  delete[] str;  
}

//=============================================================================
// Write eOccasional element if the condition is satisfied.
//=============================================================================
void DocGen::write_eOccasional(int aUnique1, int aSixtyFour, char *str) {

  // The presence or absence of the eOccasionalType element is determined
  // by the value of the attribute aSixtyFour
  if (aSixtyFour == 0) {
	numEOccNodes++;
	numNodesCount++;
	int l;
    	for (l = 1; l < level; l++) {
      		fpOut << "   ";
    	}
    	fpOut << "<eOccasional aRef=\"" 
	      << computeARef(aUnique1) << "\">" << endl;
		if (dg->prtElemContFlag) 
    		fpOut << str;
    	for (l = 1; l < level; l++) {
      		fpOut << "   ";
    	}
    	fpOut << "</eOccasional>" << endl;
  } 
}

//=============================================================================
// Computer aUnique1 attribute
//=============================================================================
int DocGen::computeAUnique1() {
	
	// aUnique1 is a unique integer value generated by traversing the entire
	// data tree in a breadth-first manner
	int aUnique1;
	if (level ==  rootLevel) {
		aUnique1 = nodes[level];
	} else {
		aUnique1 = numTotalNodes[level-1]  + nodes[level];
	}

	// check whether aUnique1 is unique
	if (aUnique1Used[aUnique1] == true) {
		cerr << "aUnique1 is repeated" << endl;
		exit(1);
	} else {
		aUnique1Used[aUnique1] = true;
	}
	return aUnique1;
}

//=============================================================================
// Computer aUnique2 attribute
//=============================================================================
int DocGen::computeAUnique2() {
   // aUnique2: a unique integer value generated randomly
	int u2index = aUnique2RNG.genNum(1,numDatasetNodes);

	while (aUnique2Used[u2index] == true) {
			u2index = aUnique2RNG.genNum(1,numDatasetNodes);
	}
 
	aUnique2Used[u2index] = true;
	return u2index;
}

//=============================================================================
// Compute attributes that are based on the mod  operation between two numbers
//=============================================================================
int DocGen::computeAttr(int baseNum, int modNum) {
	return baseNum % modNum;
}

//=============================================================================
// Write element begin tag along with the attributes of the element
//=============================================================================
void DocGen::writeBeginTag(const char *elemName, int level) {
	for (int l = 1; l < level; l++) {
		fpOut << "   ";
	}
	
	if (level > rootLevel) {
		// open begin element tag
		fpOut << "<" << elemName;
	} else {
		fpOut << "<" << ROOT_ELEM_NAME;
		// print out schema-reference only if XML schema sis supported
		if (dg->supportSchemaFlag == true) {
			fpOut   << " xmlns:xsi=" << XMLNS_XSI  
					<< " xsi:schemaLocation=" << SCHEMA_LOCATION 
					<< " ";
		}
	}

	// aUnique1: a unique integer generated by traversing the entire data tree
	// in a breadth-first manner
	int aUnique1 = computeAUnique1();
	fpOut << " aUnique1=\"" << aUnique1 << "\"";
  
	// aUnique2: a unique integer value generated randomly.
	int aUnique2 = computeAUnique2();
	fpOut << " aUnique2=\"" << aUnique2 << "\"";
  
	// aLevel: an integer avlaue to store the level of the node
	fpOut << " aLevel=\"" << level << "\"";
  
	// aFour: set to aUnique1 mod 4
	int aFour = computeAttr(aUnique1,4);
	fpOut << " aFour=\"" << aFour << "\"";
  
	// aSixteen: set to aUnique2 mod 16
	int aSixteen = computeAttr(aUnique1 + aUnique2,16);
	fpOut << " aSixteen=\"" << aSixteen << "\"" ;
  
	// aSixtyFour: set to aUnique2 mod 64
	int aSixtyFour = computeAttr(aUnique2,64);
	fpOut << " aSixtyFour=\"" << aSixtyFour << "\"";
  

	// write string attributes and content
	writeStrAttrs(aUnique1, aSixtyFour);
    nodes[level]++;
}

//=============================================================================
// Write element end tag 
//=============================================================================
void DocGen::writeEndTag(const char *elemName, int level) {
	for (int l = 1; l < level; l++) {
      fpOut << "   ";
	}


	// to test the correctness of producing expected number of nodes 
	// in each level
	// fpOut << "</" << elemName << " L" << level << " N" << nodes[level] 
	// << ">" << endl; 
	fpOut << "</" << elemName << ">" << endl; 
}
	
//=============================================================================
// Write element content
//=============================================================================
void DocGen::writeContent(const char *elemContent) {
	fpOut << elemContent;
}


//=============================================================================
// Write element 
//=============================================================================
void DocGen::writeElem() {
  level++;

  // need to distinguish between the root element and non-root elements
  // since the root element has special element tag name.
  if (level == rootLevel) 
    writeBeginTag(ROOT_ELEM_NAME, rootLevel);
  else
    writeBeginTag(BASETYPE_ELEM_NAME, level);

  numENestNodes++;
  numNodesCount++;
  if ((numNodesCount % NUM_NODES_PRINT_STEP) == 0) {
	  cerr << "-- Written " << numNodesCount
	       << " elements --" << endl; 
  }

  // if number of fanouts at the current level is greater than 0, then
  // we need to call this function recursively so that we generate data
  // in depth-first tarversal manner
  if (level < deepestLevel && fanout[scaleFactor][level] > 0) {
    writeContent("\n");
    if (fanout[scaleFactor][level] > 1) {
      for (int i = 0; i < fanout[scaleFactor][level]; i++) {
		writeElem();
      } 
    } else {
      int f = (int) (1/fanout[scaleFactor][level]);
	  if ((nodes[level] % f) == 0) {
	   writeElem();  
	  }
	  
    }
  }

  // need to distinguish between the root element and non-root elements
  // since the root element has special element tag name.
  if (level == rootLevel)
    writeEndTag(ROOT_ELEM_NAME,rootLevel);
  else
    writeEndTag(BASETYPE_ELEM_NAME, level);
  level--;      
}

//=============================================================================
// Write document declaration
//=============================================================================
void DocGen::writeDocDeclaration() {
    fpOut << "<?xml version=\"1.0\"?>" << endl;
}

//=============================================================================
// Write statistics of the generated documents
//=============================================================================
void DocGen::writeStats() {
	cerr << endl << endl << "Statistics  of this data set:" << endl;	
	cerr		 << "============================" << endl;
	cerr << "There are total " << numENestNodes << " 'eNest' nodes" << endl;
	cerr << "There are total " << numEOccNodes << " 'eOccasional' nodes" << endl;
	cerr << "There are total " << numNodesCount << " nodes " << endl;
}

//=============================================================================
// Write an XML document
//=============================================================================
void DocGen::writeDoc(int docIndex) {
	strstream filename;
	filename << dg->filenamePrefix << setw(filenameWidth)
		 << setfill('0') << docIndex << ".xml" << ends;	
	cerr << "Writing '" << filename.str() << "' ..." << endl;
	fpOut.open(filename.str(),ios::out);
	writeDocDeclaration();
	writeElem();
	fpOut.close();
}


void DocGen::prtConfig() {
	cerr << "Configuration of this data set:" << endl;
	cerr << "===============================" << endl;
	cerr << "the root level = " << rootLevel << endl;
	cerr << "the deepest level = " << deepestLevel << endl;
	cerr << "the scale factor =" << mapScales[scaleFactor] << endl;
	if (dg->supportSchemaFlag == true) {
		cerr << "XML Schema is referenced" << endl;
    } else {
		cerr <<  "XML Schema is NOT referenced" << endl;
	}
	if (dg->prtElemContFlag == true) {
		cerr << "Element content is printed" << endl;
    } else {
		cerr << "Element content is not printed" << endl;
	}	
	cerr << endl << endl;	
	filenameWidth = static_cast<int>(floor(log10(numDocs))) + 1; 

	cerr << "Generating " << numDocs 
		 << " documents " << endl;
	cerr << "===========" << setw(filenameWidth) << setfill('=') 
		 << "========== " << endl;
}

//=============================================================================
// Write a set of XML documents in the data set.
//=============================================================================
void DocGen::writeDocs() {
	setConfig();
	initDoc();
	
	for (int i = 1; i <= numDocs; i++) {
		writeDoc(i);
	}
	writeStats();
}


