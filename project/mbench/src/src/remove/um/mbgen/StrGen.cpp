/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *		
 * Description: Generate string 'PickWord' with a discrete Zipf distribution
 *
 * Filename:   StrGen.cpp
 ****************************************************************************/


#include <iostream.h>
#include <math.h>

#include "StrGen.h"
#include <assert.h> 

#ifdef use_namespace
namespace MIBENCH {
#endif 

// translates between numbers in numeric to numbers in characters
const char *numTranslators[] = {
	"zero",			"one",			"two",			"three",
	"four",			"five",			"six",			"seven",	
	"eight",		"nine",			"ten",			"eleven",
	"twelve",		"thirteen",		"fourteen",		"fifteen",
	"sixteen",		"seventeen",	"eighteen",		"nineteen",
	"twenty",		"twentyone",	"twentytwo",	"twentythree",
	"twentyfour",	"twentyfive",	"twentysix",	"twentyseven",
	"twentyeight",	"twentynine",	"thirty",		"thirtyone",	
	"thirtytwo",	"thirtythree",	"thirtyfour",	"thirtyfive",	
	"thirtysix",	"thirtyseven",	"thirtyeight",	"thirtynine",
	"forty",		"fortyone",		"fortytwo",		"fortythree",
	"fortyfour",	"fortyfive",	"fortysix",		"fortyseven",
	"fortyeight",	"fortynine",	"fifty",		"fiftyone",
	"fiftytwo",		"fiftythree",	"fiftyfour",	"fiftyfive",
	"fiftysix",		"fiftyseven",	"fiftyeight",	"fiftynine",
	"sixty",		"sixtyone",		"sixtytwo",		"sixtythree",
	"sixtyfour"	,	"sixtyfive",	"sixtysix",		"sixtyseven",
	"sixtyeight",	"sixtynine",	"seventy",		"seventyone",
	"seventytwo",	"seventythree",	"seventyfour",	"seventyfive",
	"seventysix",	"seventyseven",	"seventyeight",	"seventynine",
	"eighty",		"eightyone",	"eightytwo",	"eightythree",
	"eightyfour",	"eightyfive",	"eightysix",	"eightyseven",
	"eightyeight",	"eightynine",	"ninety",		"ninetyone",
	"ninetytwo",	"ninetythree",	"ninetyfour",	"ninetyfive",
	"ninetysix",	"ninetyseven",	"ninetyeight",	"ninetynine"
};

//=============================================================================
// Constructor.
//=============================================================================
StrGen::StrGen() {
}


//=============================================================================
// Generate string given the bucket number and the word number
//=============================================================================
void StrGen::genStr(char *word, int bucketNum, int wordNum, bool derivedWord) {
	int firstPartWordNum = wordNum / WORD_NUM_SEPARATOR;
	int secondPartWordNum = wordNum % WORD_NUM_SEPARATOR;
	if (firstPartWordNum > 0) {
		sprintf(word,"%d%sB%d", firstPartWordNum, numTranslators[secondPartWordNum],
						  bucketNum);
	} else {
		sprintf(word,"%sB%d",numTranslators[secondPartWordNum], bucketNum);
	}	
	if (derivedWord) 
		strcat(word,"ing");
}

//=============================================================================
// Generate bucket number and the word number, and use these numbers 
// to generate string based on them.
//=============================================================================
void StrGen::genWord(char *word) {
	int bucketNum = bucketRNG.genNum(1,NUM_BUCKETS);
	int wordUpperBnd = (int) pow(2,bucketNum - 1);
	int wordNum = wordRNG[bucketNum].genNum(1,wordUpperBnd);
	if (bucketNum < NUM_BUCKETS) {

		genStr(word,bucketNum,wordNum, false); 
	} else {
		assert(bucketNum == NUM_BUCKETS);
		computeWordLastBucket(wordNum,word);
	}
}

//=============================================================================
// Words in the last bucket are derived from words in the other buckets by
// adding the suffix "ing" (to get exactly 2^15 words in the sixteenth bucket,
// we add the dummy word "oneB0ing"
//=============================================================================
void StrGen::computeWordLastBucket(int wordNum, char *word) {
	 
// we first find which bucket that this word is belong to
	int bucketNum = (int) (log(wordNum)/log(2));
// given the found bucket, we find the order of the word number
	int modulus = (int) (pow(2,bucketNum));
	int newWordNum = wordNum % modulus;

	// the extra word that does not belong to any bucket
	if (bucketNum == (NUM_BUCKETS-1)) {
			bucketNum = -1;
	} 
	if (wordNum > 0) {
		genStr(word,bucketNum+1,newWordNum+1, true);
	} else {
		// generate word "oneB0ing" 
		genStr(word,0,1,true);
	}
}

#ifdef use_namespace
}
#endif