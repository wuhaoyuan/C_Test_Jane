//
//  GameUtility.h
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef GameUtility_h
#define GameUtility_h

// Game Utilities
#define GAME_ARENA_SIZE_X           (30)
#define GAME_ARENA_SIZE_Y           (20)
#define LOSE_HP_DRAW                (1)
#define LOSE_HP_DEFEATED            (3)
#define WEAPON_GENERATION_STEPS_MIN (50)
#define WEAPON_GENERATION_STEPS_MAX (100)
#define PLAYER_CHARACTER_DEAD       'X'



// Player 1 Configuration
#define PLAYER_1_CHARACTER      'L'
#define PLAYER_1_INTI_LOC_X     (1)
#define PLAYER_1_INTI_LOC_Y     (1)
#define PLAYER_1_INTI_HP        (10)

#define PLAYER_1_KEY_UP         'w'
#define PLAYER_1_KEY_DOWN       's'
#define PLAYER_1_KEY_LEFT       'a'
#define PLAYER_1_KEY_RIGHT      'd'
#define PLAYER_1_KEY_ESCAPE     '0'

// Player 2 Configuration
#define PLAYER_2_CHARACTER      '@'
#define PLAYER_2_INTI_LOC_X     (GAME_ARENA_SIZE_X-2)
#define PLAYER_2_INTI_LOC_Y     (GAME_ARENA_SIZE_Y-2)
#define PLAYER_2_INTI_HP        (10)

#define PLAYER_2_KEY_UP         'i'
#define PLAYER_2_KEY_DOWN       'k'
#define PLAYER_2_KEY_LEFT       'j'
#define PLAYER_2_KEY_RIGHT      'l'
#define PLAYER_2_KEY_ESCAPE     '0'


struct Location {
    Location(unsigned int a=0, unsigned int b=0) :x(a), y(b) {};
    unsigned int x;
    unsigned int y;
};


#endif /* GameUtility_h */
