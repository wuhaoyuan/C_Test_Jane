//
//  main.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#include "Game.hpp"
using namespace std;




int main(int argc, const char * argv[]) {
    struct termios old_tio, new_tio;
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);
    
    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    
    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    
    // init Game
    Game game;
    game.gameStart();
    
    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    
    return 0;
}
