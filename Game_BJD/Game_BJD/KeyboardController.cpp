//
//  KeyboardController.cpp
//  Game_BJD
//
//  Created by Jane Jane on 7/24/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#include "KeyboardController.hpp"

KeyboarController::KeyboarController(char keyUp, char keyDown, char keyLeft, char keyRight, char keyEscape)
:m_keyUp(keyUp), m_keyDown(keyDown), m_keyLeft(keyLeft), m_keyRight(keyRight), m_keyEscape(keyEscape) {}

KeyCommand KeyboarController::getCommand(char c) const {
    if (c == m_keyUp) {
        return KeyCommandMoveUp;
    } else if (c == m_keyDown) {
        return KeyCommandMoveDown;
    } else if (c == m_keyLeft) {
        return KeyCommandMoveLeft;
    } else if (c == m_keyRight) {
        return KeyCommandMoveRight;
    } else if (c == m_keyEscape) {
        return keyCommandEscape;
    } else {
        return KeyCommandUnkown;
    }
}
