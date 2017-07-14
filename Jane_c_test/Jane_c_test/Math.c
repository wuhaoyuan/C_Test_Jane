//
//  Math.c
//  Jane_c_test
//
//  Created by Jane Jane on 7/13/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#include "Math.h"
#include <stdbool.h>

//A prime number is a whole number greater than 1, whose only two whole-number factors are 1 and itself. The first few prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23, and 29.
#pragma mark -
#pragma mark By Jane
void printPrimeNumbersBetweenInterval_Jane(int leftInt, int rightInt) {
    int startingInt;
    
    if (rightInt < 1) {
        printf("There is no prime number in the interval");
        return;
    }
    
    if (leftInt <= 2) {
        startingInt = 2;
    } else {
        startingInt = leftInt;
    }
    
    for (int i = startingInt; i <= rightInt; i++) {
        //start from 2 and mod to decide if it is a prime
        for (int j = 2; j <= i; j++) {
            if (i == j) {
                printf("%d ",i);
            } else if (i%j == 0) {
                break;
            }
        }
    }
    printf("\n");
    return;
}

#pragma mark -
#pragma mark By Johnny
bool isPrimeNumber(int src) {
    if (src <= 1) {
        return false;
    }
    
    for (int i = 2; i <= src/2; i++) {
        if (src % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeNumbersBetweenInterval_Johnny(int leftInt, int rightInt) {
    // Protect inputs
    bool foundPrime = false;
    int smallIdx, largeIdx;
    if (leftInt < rightInt) {
        smallIdx = leftInt;
        largeIdx = rightInt;
    } else {
        smallIdx = rightInt;
        largeIdx = leftInt;
        
    }
    
    // Check prime
    for (int i = smallIdx; i <= largeIdx; i++) {
        // print if prime
        if (isPrimeNumber(i)) {
            printf("%d ", i);
            foundPrime = true;
        }
    }
    
    if (foundPrime == false) {
        printf("There is no prime number in the interval");
    }
    printf("\n");
}
