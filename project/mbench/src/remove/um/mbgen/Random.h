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
 //This class generates random numbers
 //@}
 *
 * Filename: Random.h
 ****************************************************************************/

#ifndef _RANDOM_H_
#define _RANDOM_H

#ifdef use_namespace
namespace MIBENCH {
#endif



const int a = 16807; /* multiplier */
const unsigned long m = 2147483647; /* 2^31 - 1 */
const unsigned long q = 127773; /* m div a */
const int r = 2836; /* m mod a */


class Random {
public:
  Random();           // default seed is 1
  Random(unsigned long _seed);
  void initSeed(unsigned long s);  // resets the seed
  long getNext();      // returns the next random number in the sequence
  double getNextUniform();
  void setMethod(int _method);

  //@{
  // Generate bucket number
  // @param lowerBnd The lower bound of the generated numbers
  // @param upperBnd The upper bound of the generated numbers
  // @returns The integer number between the lower and upper bounds
  //@}
  int genNum(int lowerBnd, int upperBnd);
  
  unsigned long getSeed() {
		return seed;
  }

 	
private:
  unsigned long seed;				// current seed value
};


#ifdef use_namespace
}
#endif


#endif