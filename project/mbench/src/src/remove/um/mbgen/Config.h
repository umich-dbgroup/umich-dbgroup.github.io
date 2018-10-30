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
 // Configuration of the schema of the documents in the data set
 //@}
 * Filename:   Config.h
 ****************************************************************************/


 
 
// number of levels in the document
const int MAX_NUM_LEVELS = 16;

// fanouts at each level 
//@{
// For the data set with scale factor =1(10,100), 
// each level in the tree has  a fanout of 2, except for levels 5,6,7, and 8
// The levels 5,6,and 7 have a fanout of 4(13,38), where as level 8 has a 
// fanout of 1/4(1/13,1/38).  This choice of fanout implies that the number of 
// nodes at levels 7 and 9 is 256.
//@}
const int NUM_SCALE_FACTORS = 3;
const double fanout[NUM_SCALE_FACTORS][MAX_NUM_LEVELS+1] =  
{{0, 2, 2, 2, 2,   4,  4,  4, 0.25, 2, 2, 2, 2, 2, 2, 2, 0},
{0, 2, 2, 2, 2, 13, 13, 13, (double) 1/13, 2, 2, 2, 2, 2, 2, 2, 0},
{0, 2, 2, 2, 2, 38, 38, 38, (double) 1/38, 2, 2, 2, 2, 2, 2, 2, 0}}; 

enum ScaleFactor {one, ten, oneHundred};
const int mapScales[] = {1,10,100};
