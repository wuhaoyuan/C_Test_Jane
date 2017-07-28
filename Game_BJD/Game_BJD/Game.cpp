//
//  Game.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/22/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include "Game.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

Game::Game()
:m_arena(GameBoard(GAME_ARENA_SIZE_Y, GAME_ARENA_SIZE_X)) {
    
    // seed for rand()
    srand ((unsigned int) time(NULL));
    
    m_moveCount = 0;

    // init Players
    Player *player1 = new Player(PLAYER_1_CHARACTER, PLAYER_1_INTI_LOC_X, PLAYER_1_INTI_LOC_Y, getRandomWeaponType(), PLAYER_1_INTI_HP);
    Player *player2 = new Player(PLAYER_2_CHARACTER, PLAYER_2_INTI_LOC_X, PLAYER_2_INTI_LOC_Y, getRandomWeaponType(), PLAYER_2_INTI_HP);
    m_players.push_back(player1);
    m_players.push_back(player2);

    // init Keyboard Controller
    KeyboarController *keyCtrl1 = new KeyboarController(PLAYER_1_KEY_UP, PLAYER_1_KEY_DOWN, PLAYER_1_KEY_LEFT, PLAYER_1_KEY_RIGHT, PLAYER_1_KEY_ESCAPE);
    KeyboarController *keyCtrl2 = new KeyboarController(PLAYER_2_KEY_UP, PLAYER_2_KEY_DOWN, PLAYER_2_KEY_LEFT, PLAYER_2_KEY_RIGHT, PLAYER_2_KEY_ESCAPE);
    m_keyboardControllers.push_back(keyCtrl1);
    m_keyboardControllers.push_back(keyCtrl2);
    
}

Game::~Game() {
    for (int i = 0; i < m_players.size(); i++) {
        delete m_players[i];
    }
    
    for (int i = 0; i < m_idleWeapons.size(); i++) {
        delete m_idleWeapons[i];
    }
    
    for (int i = 0; i < m_keyboardControllers.size(); i++) {
        delete m_keyboardControllers[i];
    }
}

#pragma mark -
#pragma mark Game Rules
enum BattleResult {
    BattleResultWon,
    BattleResultLost,
    BattleResultDraw
};

BattleResult playerBattle(Player *player1, Player *player2) {
    WeaponType weaponTypePlayer1 = player1->getWeapon()->getWeaponType();
    WeaponType weaponTypePlayer2 = player2->getWeapon()->getWeaponType();

    if (weaponTypePlayer1 == weaponTypePlayer2) {
        return BattleResultDraw;
    }
    
    if (weaponTypePlayer1 == WeaponRock) {
        if (weaponTypePlayer1 == WeaponScissors) {
            return BattleResultWon;
        } else {
            // WeaponPaper
            return BattleResultLost;
        }
        
    } else if (weaponTypePlayer1 == WeaponScissors) {
        if (weaponTypePlayer2 == WeaponRock) {
            return BattleResultLost;
        } else {
            // WeaponPaper
            return BattleResultWon;
        }
        
    } else {
        if (weaponTypePlayer2 == WeaponRock) {
            return BattleResultWon;
        } else {
            // WeaponScissors
            return BattleResultLost;
        }
    }
}

#pragma mark -
#pragma mark Game Core
void ClearScreen() {
    cout << string(50, '\n');
}

void Game::printGameInfo() {
    cout << "----------------------------------------------" << endl;
    cout << "Player: " << m_players[0]->getCharactor() << "\t|\t Player: " << m_players[1]->getCharactor() << endl;
    cout << "Weapon: " << (char)m_players[0]->getWeapon()->getCharactor() << "\t|\t Weapon: " << (char)m_players[1]->getWeapon()->getCharactor() << endl;
    cout << "HP: " << m_players[0]->getHealth() << "\t\t|\t HP: " << m_players[1]->getHealth() << endl;
    cout << "Next Weapon:" << m_nextWeaponGenrationMoveCount - m_moveCount << endl;
    cout << "----------------------------------------------" << endl;
}

tuple<KeyCommand, int> Game::parseKeyboarInput(char c) const {
    KeyCommand keyCmd = KeyCommandUnkown;
    int playerCmdIndex = 0;
    
    for (; playerCmdIndex < m_keyboardControllers.size(); playerCmdIndex++) {
        keyCmd = m_keyboardControllers[playerCmdIndex]->getCommand(c);
        if (keyCmd != KeyCommandUnkown) {
            break;
        }
    }
    
    return make_tuple(keyCmd, playerCmdIndex);
}

bool Game::isDestinationValid(Location currentLoc, Direction moveDirection) const {
    bool isDestinationWall = false;
    
    switch (moveDirection) {
        case MoveUp:
            isDestinationWall = m_arena.isLoacationWall(Location(currentLoc.x, currentLoc.y - 1));
            break;
        case MoveDown:
            isDestinationWall = m_arena.isLoacationWall(Location(currentLoc.x, currentLoc.y + 1));
            break;
        case MoveLeft:
            isDestinationWall = m_arena.isLoacationWall(Location(currentLoc.x - 1, currentLoc.y));
            break;
        case MoveRight:
            isDestinationWall = m_arena.isLoacationWall(Location(currentLoc.x + 1, currentLoc.y));
            break;
    }

    return !isDestinationWall;
}

Direction getDirectionFromCommand(KeyCommand cmd) {
    Direction direction;
    switch (cmd) {
        case KeyCommandMoveUp:
            direction = MoveUp;
            break;
        case KeyCommandMoveDown:
            direction = MoveDown;
            break;
        case KeyCommandMoveLeft:
            direction = MoveLeft;
            break;
        case KeyCommandMoveRight:
            direction = MoveRight;
            break;
            
        default:
            // KeyCommandUnkown
            // keyCommandEscape
            // This function shoud never get here!
            cout << "***Error invalid use of getDirectionFromCommand()" << endl;
            abort();
            break;
    }
    
    return direction;
}

bool isLocationEqual(Location loc1, Location loc2) {
    return (loc1.x == loc2.x) && (loc1.y == loc2.y);
}

int getNextWeaponGenrationMoveCount() {
    return (rand() % (WEAPON_GENERATION_STEPS_MAX - WEAPON_GENERATION_STEPS_MIN)) + WEAPON_GENERATION_STEPS_MIN;
}

Location Game::getRandomAvailableLocation() const {
    
    bool isWallLocation = false;
    bool isPlayersLocation = false;
    bool isIdleWeaponLocation = false;
    
    int randomX;
    int randomY;
    Location randomLoc;
    
    do {
        randomX = (rand() % GAME_ARENA_SIZE_X);
        randomY = (rand() % GAME_ARENA_SIZE_Y);
        randomLoc = Location(randomX, randomY);
        
        // Check is not wall
        isWallLocation = m_arena.isLoacationWall(randomLoc);
        
        // Check is not Player location
        for (int i = 0; i < m_players.size(); i++) {
            if (isLocationEqual(m_players[i]->getLocation(), randomLoc)) {
                isPlayersLocation = true;
                break;
            }
        }
        
        // Check is not Idel weapon location
        for (int i = 0; i < m_idleWeapons.size(); i++) {
            if (isLocationEqual(m_idleWeapons[i]->getLocation(), randomLoc)) {
                isIdleWeaponLocation = true;
                break;
            }
        }
    } while(isWallLocation || isPlayersLocation || isIdleWeaponLocation);
    
    return randomLoc;
}

bool Game::isGameOver() const {
    unsigned long numberOfSurviers = m_players.size();
    for (int i = 0; i < m_players.size(); i++) {
        if (m_players[i]->getHealth() < 0) {
            numberOfSurviers--;
        }
    }
    
    if (numberOfSurviers <= 1) {
        return true;
    } else {
        return false;
    }
}

void Game::gameStart() {
    
    tuple<KeyCommand, int> userInput;

    KeyCommand keyCmd = KeyCommandUnkown;
    int playerCmdIndex = 0;
    void_f_int printEffect = NULL;
    
    // init random weapon generation
    m_nextWeaponGenrationMoveCount = m_moveCount + getNextWeaponGenrationMoveCount();

    do {
        // print game board
        ClearScreen();
        if (printEffect != NULL) {
            printEffect(WEAPON_EFFECT_SIZE);
        }
        printGameInfo();
        m_arena.printGameBoard(m_players, m_idleWeapons);

        // get user input
        char inputChar = getchar();
        
        // parse user input
        userInput = parseKeyboarInput(inputChar);
        keyCmd = get<0>(userInput);
        playerCmdIndex = get<1>(userInput);
        
        // perform user command
        if (keyCmd != KeyCommandUnkown && keyCmd != keyCommandEscape && m_players[playerCmdIndex]->isAlive()) {
            m_moveCount++;
            
            // check whether destination valid
            Direction moveDirection = getDirectionFromCommand(keyCmd);
            if (isDestinationValid(m_players[playerCmdIndex]->getLocation(), moveDirection)) {
                // perform movement
                m_players[playerCmdIndex]->move(moveDirection);
                
                // check weapon pick up
                for (int i = 0; i < m_idleWeapons.size(); i++) {
                    if (isLocationEqual(m_players[playerCmdIndex]->getLocation(), m_idleWeapons[i]->getLocation())) {
                        m_players[playerCmdIndex]->changeWeapon(m_idleWeapons[i]);
                        m_idleWeapons.erase(m_idleWeapons.begin() + i);
                    }
                }
                
                // Generate ramdom idle weapons
                if (m_moveCount >= m_nextWeaponGenrationMoveCount) {
                    Location newIdleWeaponLocation = getRandomAvailableLocation();
                    Weapon *newWeapon = new Weapon(newIdleWeaponLocation, getRandomWeaponType());
                    m_idleWeapons.push_back(newWeapon);
                    m_nextWeaponGenrationMoveCount = m_moveCount + getNextWeaponGenrationMoveCount();
                }
                
                // check attack
                if (isLocationEqual(m_players[0]->getLocation(), m_players[1]->getLocation())) {
                    // always Player0 attack Player1
                    BattleResult attackResult = playerBattle(m_players[0], m_players[1]);
                    switch (attackResult) {
                        case BattleResultWon:
                            m_players[1]->loseHealth(LOSE_HP_DEFEATED);
                            printEffect = m_players[0]->getWeapon()->getPrintAttackEffectFunction();
                            break;
                        case BattleResultLost:
                            m_players[0]->loseHealth(LOSE_HP_DEFEATED);
                            printEffect = m_players[1]->getWeapon()->getPrintAttackEffectFunction();
                            break;
                        case BattleResultDraw:
                            m_players[0]->loseHealth(LOSE_HP_DRAW);
                            m_players[1]->loseHealth(LOSE_HP_DRAW);
                            break;
                        default:
                            // never reach here!
                            break;
                    }
                }
            }
            if (isGameOver()) {
                cout << "Game Over!" << endl;
            }
        }
        
    }while(keyCmd != keyCommandEscape);
}





