//
//  Player.hpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Weapon.hpp"
#include "GameUtility.h"

enum Direction {
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight
};

class Player {
public:
    Player(char c, unsigned x, unsigned y, WeaponType weaponType, int hp);
    ~Player();
    char getCharactor() const;
    Location getLocation() const;
    int getHealth() const;
    Weapon* getWeapon() const;
    
    void move(Direction dir);
    void loseHealth(int loseHP);
    void changeWeapon(Weapon *newWeapon);
    bool isAlive() const;
    
private:
    int m_hp;
    char m_playerChar;
    Location m_loc;
    Weapon *m_weapon;
};

#endif /* Player_hpp */
