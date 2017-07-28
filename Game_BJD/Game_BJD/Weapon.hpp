//
//  Weapon.hpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "GameUtility.h"

typedef void (*void_f_int)(int);


enum WeaponType {
    WeaponRock,
    WeaponScissors,
    WeaponPaper,
    
    TotalTypesOfWeapon
};
static char WeaponChar[TotalTypesOfWeapon] = {'3', '2', '1'};

WeaponType getRandomWeaponType();

class Weapon {
public:
    Weapon(Location loc, WeaponType type);
    char getCharactor() const;
    Location getLocation() const;
    WeaponType getWeaponType() const;
    void_f_int getPrintAttackEffectFunction();
    void changeDummy_fail();
    void changeDummy_succeed(int v);

private:
    
    void_f_int m_printAttackEffect;
    //void (*m_printAttackEffect)(int);
    Location m_loc;
    WeaponType m_type;
};


#endif /* Weapon_hpp */
