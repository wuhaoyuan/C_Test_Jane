//
//  KeyboardController.hpp
//  Game_BJD
//
//  Created by Jane Jane on 7/24/17.
//  Copyright © 2017 Jane Jane. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include <stdio.h>

enum KeyCommand {
    KeyCommandUnkown,
    
    KeyCommandMoveUp,
    KeyCommandMoveDown,
    KeyCommandMoveLeft,
    KeyCommandMoveRight,
    keyCommandEscape
};

class KeyboarController {
public:
    KeyboarController(char keyUp, char keyDown, char keyLeft, char keyRight, char keyEscape);
    KeyCommand getCommand(char c) const;
    
private:
    char m_keyUp;
    char m_keyDown;
    char m_keyLeft;
    char m_keyRight;
    char m_keyEscape;
};

#endif /* KeyboardController_hpp */
