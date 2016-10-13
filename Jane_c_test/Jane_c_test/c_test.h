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

#pragma mark -
#pragma mark Link List
struct Node {
    int value;
    int count;
    struct Node *next;
};
typedef struct Node Node;

struct List {
    int length;
    Node *root;
};
typedef struct List List;

List* createList();
void pushBackTolist(List *list, int value);

int lengthOfList(List *list);
void removeFromList(List *list, int value);
void removeAll(List *list);
bool findValue(List *list, int value);
void printList(List *list);
List* interleaveList(List *listA, List *listB);
void reverseList(List *list);

//2016-10-10 sort list
void sortList(List *inputList);


//2016-10-12
void alternativeSplit(const List* inputList, List* outputList1, List* outputList2);


#endif /* c_test_h */
