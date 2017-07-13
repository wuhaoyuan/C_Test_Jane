//
//  GeneralAlg.c
//  Jane_c_test
//
//  Created by Jane Jane on 7/12/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#include "GeneralAlg.h"
#include "math.h"
#include "stdbool.h"

#pragma mark -
#pragma mark General Algorithm
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
                        currentOutIdex+=getIntDigits(countingSum); //becasue the countingSum may >9;
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


//9/20/2016
/*
 char* str = "A3BC12";
 char outStr[10000]="AAABCCCCCCCCCCCC";
 unsigned int outSize=16;
 
 decompressString(str, 6, outStr, &outSize);
 */

//1.a function to check if a char is a character or number
//2. a funciton that input char and number, it will print then out
//3. if there is not number following right after a character, means number ==1
//4. a function to convert char to digit
//5. a funtion to combine the digits into integer, so it will depends on how many digit it has

bool isNumber(char inputAnimal){
    if (inputAnimal=='0' |inputAnimal=='1' |inputAnimal=='2'|inputAnimal=='3'|inputAnimal=='4'|inputAnimal=='5'|inputAnimal=='6'|inputAnimal=='7'|inputAnimal=='8'|inputAnimal=='9') {
        //  printf("is number\n");
        return true;
    }
    else{
        //printf("is char\n");
        return false;
    }
}

int convertToDigit(char inputChar){
    int outputNum;
    outputNum= (int)(inputChar)-48;
    //printf("outputNum is %d", outputNum);
    return outputNum;
}

void printOutPerviousContent(char currentChar, int integerDigitCount, int* digitBuffer){
    
    int finalInteger=0;
    
    for (int i=0; i<integerDigitCount; i++) {
        finalInteger+= digitBuffer[i]*pow(10, integerDigitCount-i-1);
    }
    //printf("final intger %d\n", finalInteger);
    
    for (int k=0; k<finalInteger; k++) {
        printf("%c",currentChar);
    }
    // printf("\n");
    return;
}

void decompressString(char* inputString, const unsigned int inputSize, char* outputString, unsigned int* outputSize){
    
    char currentChar = inputString[0];
    char toPrintChar = inputString[0];
    bool bufferPrintTag = false;
    int integerDigitCount = 1;
    int digitBuffer[3]; // assume the number will not be greater than 999
    
    
    for (int i=0; i<inputSize; i++) {
        toPrintChar = currentChar;    //save the perious char
        
        if (!isNumber(inputString[i])) {
            // start the new iteration
            currentChar = inputString[i];
            if (i!=0) {
                // if flag==true, means it is on the next interation, so we can print the privous contents
                bufferPrintTag = true;
            }
        } else {
            digitBuffer[integerDigitCount] = convertToDigit(inputString[i]);
            integerDigitCount++;
        }
        
        if (bufferPrintTag == true) {
            if (integerDigitCount == 1) {
                // if there is only one char
                printf("%c",toPrintChar);
            }
            printOutPerviousContent(toPrintChar, integerDigitCount, digitBuffer);
            bufferPrintTag = false;
            integerDigitCount = 1;
        }
        
        if (i==inputSize-1) {
            // last one
            printOutPerviousContent(toPrintChar, integerDigitCount, digitBuffer);
            if (integerDigitCount == 1) {
                // if last one only has one count
                printf("%c", inputString[inputSize-1]);
            }
        }
    }
    printf("\n");
    return;
}
