//
//  Weapon.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include "Weapon.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

extern "C" {
    #include "GeneralAlg.h"
}

WeaponType getRandomWeaponType() {
    
    int randomInt = rand();
    WeaponType randomWeapon = (WeaponType) (randomInt % TotalTypesOfWeapon);
    
    return randomWeapon;
}

Weapon::Weapon(Location loc, WeaponType type=getRandomWeaponType()) {
    m_loc = Location(loc.x, loc.y);
    m_type = type;
    
    switch (m_type) {
        case WeaponRock:
            m_printAttackEffect = &printSquare;
            break;
        case WeaponPaper:
            break;
        case WeaponScissors:
            m_printAttackEffect = &printTriangle;
            break;
        default:
            break;
    }
}

char Weapon::getCharactor() const {
    return WeaponChar[m_type];
}

Location Weapon::getLocation() const {
    return m_loc;
}

WeaponType Weapon::getWeaponType() const {
    return m_type;
}

void_f_int Weapon::getPrintAttackEffectFunction() {
    return m_printAttackEffect;
}
