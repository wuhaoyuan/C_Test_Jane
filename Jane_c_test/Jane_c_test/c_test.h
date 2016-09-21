//
//  c_test.h
//  Jane_c_test
//
//  Created by Johnny on 9/14/16.
//  Copyright © 2016 Johnny. All rights reserved.
//

#ifndef c_test_h
#define c_test_h

#include <stdio.h>

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

#endif /* c_test_h */
