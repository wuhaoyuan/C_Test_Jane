//
//  GameBoard.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/20/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include "GameBoard.hpp"
#include <iostream>

GameBoard::GameBoard(int height, int width) :m_height(height), m_width(width) {}

void GameBoard::printGameBoard(const vector<Player*> &players, const vector<Weapon*> &idleWeapons) const {
    
    // Arena Array
    char arena[m_height][m_width];
    
    // Initialization
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            if (isLoacationWall(Location(j, i))) {
                // Wall
                arena[i][j] = '*';
            } else {
                // Arena
                arena[i][j] = ' ';
            }
        }
    }
    
    // Add Weapons
    for (int i = 0; i < idleWeapons.size(); i++) {
        Location weaponLoc = idleWeapons[i]->getLocation();
        arena[weaponLoc.y][weaponLoc.x] = idleWeapons[i]->getCharactor();
    }
    
    // Add Players
    for (int i = 0; i < players.size(); i++) {
        Location playerLoc = players[i]->getLocation();
        arena[playerLoc.y][playerLoc.x] = players[i]->getCharactor();
    }
    
    // Print Arena
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            cout << arena[i][j];
        }
        cout << endl;
    }
        
}

bool GameBoard::isLoacationWall(Location loc) const {
    if (loc.y == 0 || loc.y == (m_height-1) ||
        loc.x == 0 || loc.x == (m_width-1)) {
        // Wall
        return true;
    } else {
        // Arena
        return false;
    }
}
