//
//  c_test.c
//  Jane_c_test
//
//  Created by Johnny on 9/14/16.
//  Copyright © 2016 Johnny. All rights reserved.
//

#include "c_test.h"
#include "math.h"
/*
 4x4
 *****
 *   *
 *   *
 *****
 */
void printTopAndButton(int width)
{
    for (int i=0; i<width; i++) {
        printf("*");
    }
    return;
}
void printMiddle (int width)
{
    for (int i=0; i<width; i++) {
        if (i==0 || i==width-1)
            printf("*");
        else
            printf(" ");
    }
    return;
}

void printRectangle(int height, int width) {
    for (int i=0; i<height; i++) {
        if(i==0 || i==height-1)
            printTopAndButton(width);
        else
            printMiddle(width);
        printf("\n");
    }
}

void printChar(int num, char c) {
    for (int i=0; i<num; i++) {
        printf("%c", c);
    }
}

void printTriangle(int level_in, char c) {
    int numberOfSpace = 0;
    int numberOfChar = 0;
    
    for (int i = 0; i < level_in; i++) {
        numberOfSpace = level_in - i - 1;
        numberOfChar = (i + 1) * 2 - 1;
        
        printChar(numberOfSpace, ' ');
        printChar(numberOfChar, c);
        printf("\n");
    }
    
}

void noThree(unsigned int num) {
    for (int i = 0; i <= num; i++) {
        if (i != 0 && (i%3 == 0 || i%10 == 3)) {
            printf("! ");
        } else {
            printf("%d ", i);
        }
    }
}

/*
 4:
 *  *
  **
  **
 *  *
 5:
 *   *
  * *
   *
  * *
 *   *

 */

void printCross(int level_in, char c){
    
    int theMiddlePoint=level_in/2;
    
    for (int i=0; i<theMiddlePoint; i++) {
        int EmptyInMiddle = level_in-i*2-2;
        OddPrintTwoPoint(i,EmptyInMiddle,c);
    }
    
    if (level_in%2==1) {
       printOddHeart(level_in, c);
    }
    
    
    for (int i=0; i<theMiddlePoint; i++) {
        int EmptyInMiddle = level_in-(level_in/2-i-1)*2-2;
        OddPrintTwoPoint(level_in/2-i-1,EmptyInMiddle,c);
    }
    
}

void printOddHeart(int level_in, char c)
{
    int sideEmpty=level_in/2;
    for (int j=0; j<sideEmpty; j++) {
        printf(" ");
    }
    printf("%c",c);
    for (int j=0; j<sideEmpty; j++) {
        printf(" ");
    }
    printf("\n");
    
}


void OddPrintTwoPoint ( int EmptyOnSide, int EmptyInMiddle, int chatIn){
    
    
        for (int j=0; j<EmptyOnSide; j++) {
            printf(" ");
        }
        printf("%c", chatIn);
        for (int k=0; k<EmptyInMiddle; k++) {
            printf(" ");
        }
        printf("%c", chatIn);
        for (int j=0; j<EmptyOnSide; j++) {
            printf(" ");
        }
        printf("\n");
    
    
}

void PrintAddUpFunction(){
   
    
    double ArrayNeg2ToTen[13];  //[Johnny 0: 13 is hard codeed here, better not to hard code]
    ArrayNeg2ToTen[0]=1; //-2
    ArrayNeg2ToTen[1]=1; //-1
    ArrayNeg2ToTen[2]=1; //0
    
    double sumLevel = 0.0;
    double sumK = 0.0;
    double singleResult = 0.0;
    
    for (int k=1; k<101; k++) {
        sumLevel = 1.0 / k;  ////[Johnny 1:] int/int is always int
        sumK += sumLevel;  //[Johnny 2:] remember to initial the result
        
    }
    printf("sumK is %f \n", sumK);
    
    for (int i=3; i<13; i++) {  //[Johnny 3: i better to start form 0]
        
    
        double Neg1 = ArrayNeg2ToTen[i-1];
        double Neg2 = ArrayNeg2ToTen[i-2];
     //   printf("current Neg1 %f \n",Neg1);
       // printf("current Neg2 %f \n", Neg2);
        
        singleResult = sumK * Neg1 + 100 *  Neg2;
        
        ArrayNeg2ToTen[i] = singleResult;
        printf("the %d is %f", i-2, ArrayNeg2ToTen[i]);
        printf("\n");
    }
    
}

double sumForK() {
    
    // initialize result
    
    double result = 0;
    
    int i = 1;
    
    for (; i <= 100; i++) {
        
        result += 1.0/i;
        
    }
    
    return result;
    
}



void result() {
    
    double sumK = sumForK();
    
    double buf[3];
    
    int i=0, j=0;
    
    for (; i < 3; i++) {
        
        buf[i] = 1;
        
    }
    
    
    
    for (; j < 10; j++) {
        
        buf[0] = buf[1]*sumK + 100*buf[2];
        
        printf("%f \n", buf[0]);
        
        buf[2] = buf[1];

        buf[1] = buf[0];
        
        
    }
    
}

//9/17/2016
/*
 char* str = "AABBBBCC";
 char outStr[10000];
 unsigned int outSize;
 
 compressString(str, 10, outStr, &outSize);
 */

int getIntDigits(int inputInt) {
    int inputLog10 = (int) log10((double)inputInt);
    return (inputLog10 + 1);
}

void storeToOutArray(char* outputString, char currentChar, int countingSum, int currentOutIdex) {
    
    int countingSumDigits = getIntDigits(countingSum);
    outputString[currentOutIdex]=currentChar;

    if (countingSum != 1) {
        int residule = countingSum;
        for (int i=0; i<countingSumDigits; i++) {
            if (i == countingSumDigits-1) {
                outputString[currentOutIdex+1+i] = residule+48;
            } else {
                outputString[currentOutIdex+1+i]=countingSum/(10*(countingSumDigits-1))+48;
                residule = residule % (10*(countingSumDigits-1));
            }
        }
    }
    
    return;
}

void compressString(char* inputString, const unsigned int inputSize, char* outputString, unsigned int* outputSize){
    
    char currentChar;
    int countingSum=0;
    int currentOutIdex=0;
    *outputSize=0;
    
    
    for (int i=0; i<inputSize; i++) {
        
        if (i==0) { //first char
            currentChar= inputString[i];
            countingSum++;
        }
        else{
            //if not finding differnt, increment countingSum.
            if (inputString[i]==inputString[i-1]) {
                countingSum++;
                currentChar=inputString[i];
                if (i==(inputSize-1)) { //if last number repeat itself
                    storeToOutArray(outputString, currentChar, countingSum, currentOutIdex);
                    currentOutIdex++;
                    if (countingSum != 1) {
                        currentOutIdex+=getIntDigits(countingSum);
                    }
                }
            }
            else{
                
                //if found something differnt, store the privous to the output array
                currentChar=inputString[i-1];
                storeToOutArray(outputString, currentChar, countingSum, currentOutIdex);
                
                //update then start the next check
                currentOutIdex++;
                if (countingSum != 1) {
                    currentOutIdex+=getIntDigits(countingSum);
                    countingSum=1;
                }
                currentChar=inputString[i];
                
                if (i==(inputSize-1)) { //if last number does not repeat itself
                    storeToOutArray(outputString, currentChar, countingSum, currentOutIdex);
                }
            }
        }
    }
    *outputSize = currentOutIdex + 1;
    
}



