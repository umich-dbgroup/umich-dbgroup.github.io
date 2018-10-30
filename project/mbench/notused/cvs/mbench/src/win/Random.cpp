/****************************************************************************
 * The Michigan Benchmark Data Generator V 1.0
 *
 * Copyright (c) 2001      EECS Department, University of Michigan
 *
 * Notice: The authors of this software disclaim any liability for any damage 
 *		   resulting from its use.
 *		
 * Description: Generate random numbers
 *
 * Filename: Random.cpp
 ****************************************************************************/

#include <iostream.h>
#include <math.h>

#include "Random.h"

#ifdef use_namespace
namespace RANDOM
#endif

//=============================================================================
// Constructor.
//============================================================================= 
Random::Random() {
	seed = 1; 
}

//=============================================================================
// Constructor.
//=============================================================================
Random::Random(unsigned long _seed) {
	seed = _seed;
}

//=============================================================================
// Initialize seed
//=============================================================================
void Random::initSeed(unsigned long newSeed) {
	// seed must be from 1,2,..,m-1
	if (newSeed >= 1 && newSeed < m)
		seed = newSeed;
}

// getNext() and getNextUniform() methods are the methods that generate random
// numbers based on the algorithm presented in the paper, "Random Number 
// Generators: Good Ones are Hard to Find" by S.K. Park and K.W. Miller, 
// Communications of the ACM 31:10 (Oct 1988)

//=============================================================================
// getNext(): return long number that is in the range 1 to m-1
//=============================================================================
long Random::getNext() {
	unsigned long lo, hi;
	hi = seed / q;
	lo = seed % q;
	long test = a*lo - r*hi;
	if (test > 0)
		seed = test;
	else
		seed = test + m;
	return seed;	
}

//=============================================================================
// getNextUniform(): return long number that is between 0 and 1
//=============================================================================
double Random::getNextUniform() {  
	return (double) (getNext()/(double) m);
}


	
// ============================================================================
// Generate number that is randomly distributed between the given lower bound
// and the given upper bound.
// ============================================================================
int Random::genNum(int lowerBnd, int upperBnd) {
	double rand = getNextUniform();
	
	double step = static_cast<double>(upperBnd - lowerBnd + 1);
	return (static_cast<int>(lowerBnd + step*rand));
}
