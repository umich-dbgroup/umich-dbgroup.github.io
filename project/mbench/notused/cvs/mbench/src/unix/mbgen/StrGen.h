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
// This class generates the string attributes
// 
// The string is picked from a word pool that has 2^16 - 1 words.  The words
// are divided into 16 buckets.  The first bucket has only one word, the second
// has two words, and the third has four, and so on.  Bucket i has 2^i - 1
// words.  
//
// How to pick a word:
// A word is picked from a buket which is chosen with equal probability, and
// then a word is chosen from within the bucket, with each word equally likely.
//
// How to construct a word:
// Each word contains information about the bucket from which it is drawn and 
// the word number in the bucket.  For example, "sixB12" indicates that
// this is the 6th word from the twelfth bucket.
//@}
 *
 * Filename:   StrGen.h
 ****************************************************************************/

#ifndef _STR_GEN_H
#define _STR_GEN_H

#include <string.h>
#include <stdio.h>

#include "Random.h"



const int NUM_BUCKETS = 16;  // number of buckets = 15
const int MAX_WORD_LENGTH = 30;   // length of a generated word
const int WORD_NUM_SEPARATOR = 100; // want to write last two digits of word number
									// as characters


#ifdef use_namespace
namespace MIBENCH {
#endif 



class StrGen {
public:
	
	//@{
	// Default constructor
	// initialize the seed
	//@}
	StrGen();


	//@{
	// Generate string
	// @param bucketNum The bucket number
	// @param wordNum The word number
	// @returns The string containing information about the bucket from which it
	//  is drawn and the word number in the bucket.
	//@}
	void genStr(char *word, int bucketNum, int wordNum, bool derivedWord);
	
	//@{
	// Generate a word
	// @param word 
	//@}
	void genWord(char *word);

	//@{
	// get the seed of the generator
	//@}
	unsigned long getBucketSeed() {
			return bucketRNG.getSeed();
	}



	//@{
	// compute the word in the last bucket (sixteenth bucket)
	//@}
	void computeWordLastBucket(int wordNum, char *word);

private:
	
	// random number variable for choosing a bucket
	Random bucketRNG;

	// random number variables for choosing a word in each bucket
	Random wordRNG[NUM_BUCKETS+1];


};

#ifdef use_namespace
}
#endif 

#endif
