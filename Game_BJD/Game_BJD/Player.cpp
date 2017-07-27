//
//  Player.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include "Player.hpp"

Player::Player(char c, unsigned x, unsigned y, WeaponType weaponType, int hp) {
    m_hp = hp;
    m_playerChar = c;
    m_loc = Location(x, y);
    m_weapon = new Weapon(Location(0, 0), weaponType);
}

Player::~Player() {
    delete m_weapon;
}

char Player::getCharactor() const {
    return m_playerChar;
}

int Player::getHealth() const {
    return m_hp;
}

Location Player::getLocation() const {
    return m_loc;
}

Weapon* Player::getWeapon() const {
    return m_weapon;
}

void Player::move(Direction dir) {
    switch (dir) {
        case MoveUp:
            m_loc.y += -1;
            break;
        case MoveDown:
            m_loc.y += 1;
            break;
        case MoveLeft:
            m_loc.x += -1;
            break;
        case MoveRight:
            m_loc.x += 1;
            break;
            
        default:
            break;
    }
}

void Player::loseHealth(int loseHP) {
    if (loseHP > 0) {
        m_hp -= loseHP;
        if (!isAlive()) {
            m_playerChar = PLAYER_CHARACTER_DEAD;
        }
    }
}

void Player::changeWeapon(Weapon *newWeapon) {
    delete m_weapon;
    m_weapon = newWeapon;
}

bool Player::isAlive() const {
    if (m_hp > 0) {
        return true;
    } else {
        return false;
    }
}
