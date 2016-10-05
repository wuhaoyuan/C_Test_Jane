//
//  c_test.c
//  Jane_c_test
//
//  Created by Johnny on 9/14/16.
//  Copyright © 2016 Johnny. All rights reserved.
//

#include "c_test.h"
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

#pragma mark -
#pragma mark Link List
Node* newNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

List* createList() {
    List *newList = malloc(sizeof(List));
    newList->length = 0;
    newList->root = NULL;
    return newList;
}

void pushBackTolist(List *list, int value) {
    Node *currentNode = list->root;
    bool nodeExisted = false;
    
    if (currentNode == NULL) {
         list->root= newNode(value);
        list->length++;
        return;
    }
    
    while (1) {
        if (currentNode->value == value) {
            nodeExisted = true;
            break;
        } else if (currentNode->next == NULL) {
            nodeExisted = false;
            break;
        } else {
            currentNode = currentNode->next;
        }
    }
    
    if (nodeExisted) {
        currentNode->count++;
    } else {
        currentNode->next = newNode(value);
    }
    list->length++;
    return;
}



int lengthOfList(List *list){
    return (list->length);
}


void removeFromList(List *list, int value){
    
    Node *currentNode = list->root;
    bool nodeExisted = false;
    
    if (currentNode == NULL) {
        printf("Error: List Does Not Exist!");
        return;
    }else if (currentNode->value == value){ //first Node of the list
        if (currentNode->count != 1) {
            currentNode->count--;
        }else{ //count=1
            if (currentNode->next==NULL) {
                free(list->root);
                list->root=NULL;
            }else{
            Node* storeNode = currentNode->next;
            free(currentNode);
            list->root=storeNode;
            }
        }
        (list->length)--;
        return;
    }
    
    while (1) {
        if ((currentNode->next)->value == value) { //exist
            nodeExisted = true;
            break;
        }else if ((currentNode->next)->next == NULL){ //not exist
            nodeExisted = false;
            break;
        }else{
            currentNode = currentNode->next; //continue finding
        }
    }
    
        if (nodeExisted == true) {
            if ((currentNode->next)->count!=1) { //more the one exist
                (currentNode->next)->count--;
            }else if((currentNode->next)->next==NULL){ //only one exist at the last node
                free(currentNode->next);
                currentNode->next=NULL;
            }else{ //Only one locate in the middle of the list
                Node *storeNode;
                storeNode=(currentNode->next)->next;
                free(currentNode->next);
                currentNode->next=storeNode;
            }
        }else{ //Node does not exit
            printf("the value does not exit in the list\n");
            return;
        }
    list->length--;
    return;
    
}


void removeAll(List *list){
    
    
    Node* currentNode =list->root;
    Node* nextNode=NULL;
    
    if (list->root==NULL) {
        printf("nothing to remove, the list is empty");
        return;
    }
    while (currentNode!=NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode=nextNode;
    }
    
    list->length=0;
    list->root=NULL;
    return;
}

bool findValue(List *list, int value){
    Node* currentNode =list->root;
    
    if (list->root==NULL) {
        printf("The list is empty, nothting to find");
        return false;
    }
    while (currentNode!=NULL) {
        if (currentNode->value==value) {
            printf("We can find %d\n", value);
            return true;
        }
        currentNode = currentNode->next;
    }
    printf("We cannot find %d\n", value);
    return false;
}


void printList(List *list) {
    Node *currentNode = list->root;
    int i;
    if (list->root==NULL) {
        printf("list is empty, nothing to print\n");
        return;
    }
    
    while (1) {
        if (currentNode == NULL) {
            break;
        } else {
            for (i = 0; i < currentNode->count; i++) {
                printf("%d ", currentNode->value);
            }
            currentNode = currentNode->next;
        }
    }
    
    printf("(length of the list is %d)\n", list->length);
    return;
}


//9-29-2016 spent 30mins to wirte the reverseList function
void reverseList(List *list){
    
    Node* currentNode = list->root;
    Node* lastNode = NULL;
    Node* tempNode = NULL;
    Node* processedNode = NULL;
    
    if (list->root == NULL) {
        printf("The list is empty. Nothing to reverse");
        return;
    }
    if ((list->root)->next == NULL){
        printf("There is only one Node on the list, nothing to reverse");
        return;
    }
    
    while (currentNode->next != NULL) { //find the last Node
        if (currentNode == list->root) {
            //make root Node the last Node
            currentNode = currentNode->next;
            lastNode = list->root;
            lastNode->next = NULL;
            processedNode = lastNode;
        }else{
            tempNode = currentNode;
            currentNode = currentNode->next;
            tempNode->next = processedNode;
            processedNode = tempNode;
        }
    }
    //now currentNode is the last Node which is the root Node
    list->root = currentNode;
    (list->root)->next = processedNode;
    
    return;
}

List* interleaveList(List *listA, List *listB){
    //1. if B is empty, output A onlu. if A is empty, output B only
    //2. the first element is always the first Node of list A
    //3. there is only one Node in both list
    
    //initialize combinedList
    List* combinedList = malloc(sizeof(List));
    combinedList->length = 0;
    combinedList->root = NULL;
    
    //variable used in the function
    Node* currentNodeA = listA->root;
    Node* currentNodeB = listB->root;
    Node* previousNode = NULL;

    
    //1. if B is empty, output A only. if A is empty, output B only
    if (listA->root == NULL && listB->root == NULL) {
        return combinedList;
    }
    if (listA->root == NULL && listB->root != NULL) {
        return listB;
    }
    if (listA->root != NULL && listB->root == NULL) {
        return listA;
    }
    
    
    //there is only one Node in both list
    if (listA->root->next == NULL && listB->root->next == NULL) {
        combinedList->root = listA->root;
        combinedList->root->next = listB->root;
        return combinedList;
    }
    
    //////////// All the special cases have been considered above./////////////
    
    // the first element is always the first Node of list A
    combinedList->root = listA->root;
    currentNodeA = currentNodeA->next; //save the next starting NodeA
    currentNodeB = currentNodeB->next; //save the next starting NodeB
    listA->root->next = listB->root; //cancade the Node;
    previousNode = listB->root; //save the last processed Node in the combinedList
        
    //special case for 2 Node on listA, 1 Node on listB
    if(currentNodeB == NULL){ 
        previousNode->next=currentNodeA;
        return combinedList;
    }
    
    //special case for 2 Node on listB, 1 Node on listA
    if(currentNodeA==NULL){
        previousNode->next=currentNodeB;
        return combinedList;
    }
    
    //if we get here, means there are more than 1 node in both list;
    while (currentNodeA->next != NULL && currentNodeB->next != NULL) {
            previousNode->next = currentNodeA;
            currentNodeA = currentNodeA->next;
            previousNode->next->next = currentNodeB;
            previousNode = currentNodeB;
            currentNodeB = currentNodeB->next;
    }
    
    
    //if we get here, means one of the list is at the last Node
    
    // if listB's Node is more than listA
        if(currentNodeB->next != NULL && currentNodeA->next == NULL){
            previousNode->next = currentNodeA;
            previousNode->next->next =currentNodeB;
            return combinedList;
        }
    
    
    // if listA's Node is more than listB
    if(currentNodeA->next != NULL && currentNodeB->next == NULL){
        previousNode->next = currentNodeA;
        currentNodeA=currentNodeA->next;
        previousNode->next->next = currentNodeB;
        previousNode->next->next->next = currentNodeA;
        return combinedList;
    }
    
    //if listA has the same node number with listB
    if (currentNodeB->next == NULL && currentNodeA->next == NULL){
            previousNode->next = currentNodeA;
            previousNode->next->next = currentNodeB;
            return combinedList;
        }
    
    
    return combinedList;
}


