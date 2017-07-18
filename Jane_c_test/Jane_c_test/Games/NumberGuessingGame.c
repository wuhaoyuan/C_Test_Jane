//
//  NumberGuessingGame.c
//  Jane_c_test
//
//  Created by Jane Jane on 7/13/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#include "NumberGuessingGame.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void numberGuessingGame() {
    int leftInt;
    int rightInt;
    int changes;
    int randomNumber_old;
    int randomNumber;
    int guessNumber;
    int times = 0;
    
    // ask for the left interval, right interval and number of changes
    printf("Input left interger, right interger and changes. (left right chances)\n");
    scanf("%d %d %d", &leftInt, &rightInt, &changes);
    
    // generate a random number (secret number) from the user key in interval
    // rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX-32767.
    srand((unsigned int)time(NULL));
    randomNumber_old = rand();
    randomNumber = randomNumber_old % (rightInt + 1 - leftInt) + leftInt;
    
    while (times < changes) {
        
        printf("Key in a interger: \n");
        // ask user to key in a interger
        scanf("%d", &guessNumber);
        
        if (guessNumber > randomNumber) {
            printf("Too large!\n");
        } else if (guessNumber < randomNumber) {
            printf("Too small!\n");
        } else {
            printf("Bingo!!\n");
            return;
        }
        printf("Changes: %d\n\n", changes-times-1);
        
        times++;
    }
    
    //guess time is greater than changes
    printf("You failed, sucker!\n");
    printf("Secret number: %d\n", randomNumber);
    
    return;
}
