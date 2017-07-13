//
//  GeneralAlg.h
//  Jane_c_test
//
//  Created by Jane Jane on 7/12/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#ifndef GeneralAlg_h
#define GeneralAlg_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma mark -
#pragma mark General Algorithm
int numberOfPairs(int* array, const unsigned int size); // Not Done
//9/17/2016
/*
 char* str = "AABBBBCC";
 char outStr[10000];
 unsigned int outSize;
 
 compressString(str, 10, outStr, &outSize);
 */
void compressString(char* inputString, const unsigned int inputSize, char* outputString, unsigned int* outputSize);

//9/20/2016
/*
 char* str = "A3BC12";
 char outStr[10000];
 unsigned int outSize;
 
 decompressString(str, 6, outStr, &outSize);
 */
void decompressString(char* inputString, const unsigned int inputSize, char* outputString, unsigned int* outputSize); // Not Done

void noThree(unsigned int num);
void printTriangle(int level_in, char c);
void printRectangle(int height, int width);
void printTopAndButton(int width);
void printMiddle (int width);
// 09/14/2016
void printCross(int level_in, char c);

void printOddHeart(int level_in, char c);
void OddPrintTwoPoint ( int EmptyOnSide, int EmptyInMiddle, int chatIn);
void PrintAddUpFunction();
int ReturnSum(int k,int Neg1,int Neg2);

void result();
#endif /* GeneralAlg_h */
