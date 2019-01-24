//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "MenuItem.h"

void MenuItem::enable() {
    //ta bort ordet "disabled" från menytexten..
    menuText.erase(menuText.length()-11, 11);
    enabled = true;
}

MenuItem::MenuItem(std::string newMenuText, bool newEnabled) {
    menuText = newMenuText;
    enabled = newEnabled;
    if(!enabled){
        menuText += " (disabled)";
    }
}

void MenuItem::setMenuText(std::string newMenuText) {
    menuText = newMenuText;
}
