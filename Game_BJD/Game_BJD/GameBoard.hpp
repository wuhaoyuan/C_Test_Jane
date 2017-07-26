//
//  GameBoard.hpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include "Player.hpp"
#include "GameUtility.h"
#include <vector>

using namespace std;

class GameBoard {
public:
    GameBoard(int height, int width);
    void printGameBoard(const vector<Player*> &players, const vector<Weapon*> &idleWeapons) const;
    bool isLoacationWall(Location loc) const;
private:
    int m_height;
    int m_width;
};

#endif /* GameBoard_hpp */
