//
//  main.c
//  Jane_c_test
//
//  Created by Johnny on 8/1/16.
//  Copyright © 2016 Johnny. All rights reserved.
//

#include <stdio.h>
#include "c_test.h"



int main(int argc, const char * argv[]) {

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
    
     char* str = "A09BCD";
     int inputTotal=7;
    char outStr[10000];
     unsigned int outSize;
     decompressString(str, inputTotal, outStr, &outSize);
    /*
     for (int i=0; i<outSize; i++) {
     printf("%c",outStr[i]);
     
     }
     printf("\n");
    */
    
    
  // noThree(50);
//    printf("\n");
    // expect: 0 1 2 ! 4 5 ! 7 8 ! 10 11 ! 12 ! 14 15
  //  printRectangle (4,7);
    
    //printTriangle(9, '*');
    
   // printCross(15, 'J');
    

//PrintAddUpFunction();
  //  result();
    return 0;
}


