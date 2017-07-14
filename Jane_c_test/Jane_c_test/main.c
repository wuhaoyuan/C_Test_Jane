//
//  main.c
//  Jane_c_test
//
//  Created by Johnny on 8/1/16.
//  Copyright © 2016 Johnny. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"
#include "Math.h"
#include "NumberGuessingGame.h"

int main(int argc, const char * argv[]) {

//    7/12/2017
//    Run from the terminal
//    printf("Print all ArgumentKs:\n");
//    for (int i = 0; i < argc; i++) {
//        printf("%s\n", argv[i]);
//    }

//-----------------------------------General Algorithm-----------------------------------//
    
//9/17/2016
/*
    char* str = "AAAAAAAAAAEDDDDDDDDDDDDBBBBC";
    int inputTotal=28;
    char outStr[10000];
    unsigned int outSize;
    compressString(str, inputTotal, outStr, &outSize);
    
    for (int i=0; i<outSize; i++) {
        printf("%c",outStr[i]);
        
    }
    printf("\n");
*/
    
//9/17/2016
//    char* str = "A09BCD";
//    int inputTotal=7;
//    char outStr[10000];
//    unsigned int outSize;
//    decompressString(str, inputTotal, outStr, &outSize);
    /*
     for (int i=0; i<outSize; i++) {
     printf("%c",outStr[i]);
     
     }
     printf("\n");
    */
    
    
//    noThree(50);
//    printf("\n");
    
// expect: 0 1 2 ! 4 5 ! 7 8 ! 10 11 ! 12 ! 14 15
//    printRectangle (4,7);
//    printTriangle(9, '*');
//    printCross(15, 'J');

//    PrintAddUpFunction();
//    result();
    
//---------------------------------Link List------------------------------//
    
//9-28-2016
//    List *list = createList();
//    pushBackTolist(list, 4);
//    pushBackTolist(list, 2);
//    pushBackTolist(list, 1);
//    pushBackTolist(list, 5);
//    pushBackTolist(list, 9);
//    pushBackTolist(list, 8);
//
//    printList(list);
    
//2016-10-12
//    List *list1 = createList();
//    List *list2 = createList();
//    alternativeSplit(list, list1, list2);
//    printList(list1);
//    printList(list2);


    
//    removeFromList(list, 6);
//    printList(list);
//    
//    findValue(list, 3);
//    
//    removeAll(list);
//    printList(list);

//9-29-2016 reverse list
//    reverseList(list);
//    printList(list);
    
// combine list
//    List *listB = createList();
//    pushBackTolist(listB, 11);
//    pushBackTolist(listB, 12);
//    pushBackTolist(listB, 13);
//
//    
//    printList(listB);
//    
//    List *combinedList = createList();
//
//    combinedList = interleaveList(list, listB);
//    printList(combinedList);
    
//2016-10-10 sort list
//    sortList(list);
//    printList(list);
    
//2017-07-12

//        List *list = createList();
//        pushBackTolist(list, 4);
//        pushBackTolist(list, 2);
//        pushBackTolist(list, 1);
//        pushBackTolist(list, 5);
//        pushBackTolist(list, 9);
//        pushBackTolist(list, 8);
//    
//        printList(list);
//    
//        List *list2 = createList();
//        list2 = copyList(list);
//        printList(list2);
    
//-------------Remember to free the list---------------//
//    free(list);

    
/*----------------Print the Prime Number between the Interval---------*/
//    printPrimeNumbersBetweenInterval_Jane(0, 100);
//    printPrimeNumbersBetweenInterval_Johnny(100, -50);

    
    numberGuessingGame();
    return 0;
}


