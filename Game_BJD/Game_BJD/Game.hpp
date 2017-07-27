//
//  Game.hpp
//  Game_BJD
//
//  Created by Jane Jane on 7/22/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Player.hpp"
#include "GameBoard.hpp"
#include "GameUtility.h"
#include "Weapon.hpp"
#include "KeyboardController.hpp"

#include <vector>
#include <tuple>

class Game {
public:
    Game();
    ~Game();
    
    void gameStart();
    
private:
    void printGameInfo();
    tuple<KeyCommand, int> parseKeyboarInput(char c) const;
    bool isDestinationValid(Location currentLoc, Direction moveDirection) const;
    Location getRandomAvailableLocation() const;
    bool isGameOver() const;
    
    int m_moveCount;
    int m_nextWeaponGenrationMoveCount;
    vector<Player*> m_players;
    vector<Weapon*> m_idleWeapons;
    vector<KeyboarController*> m_keyboardControllers;
    GameBoard m_arena;
};

#endif /* Game_hpp */
