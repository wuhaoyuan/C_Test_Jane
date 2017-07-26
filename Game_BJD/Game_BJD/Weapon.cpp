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


WeaponType getRandomWeaponType() {
    
    int randomInt = rand();
    WeaponType randomWeapon = (WeaponType) (randomInt % TotalTypesOfWeapon);
    
    return randomWeapon;
}

Weapon::Weapon(Location loc, WeaponType type=getRandomWeaponType()) {
    m_loc = Location(loc.x, loc.y);
    m_type = type;
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
