//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Menu.h"
using std::cout;
using std::endl;


void Menu::setTitle(std::string newTitle) {
    menuTitle = newTitle;
}

void Menu::addItem(std::string menuText, bool enabled) {
    MenuItem item(menuText, enabled);
    menuItems.push_back(item);
}

void Menu::printMenuItems() {
    cout << endl;
    printStarLine();
    cout << menuTitle << endl;
    printStarLine();
    cout << endl;

    //Print menu choices on screen.
    int counter = 0;
    for (auto &item: menuItems) {
            cout << ++counter << ". " << item.getMenuText() << endl;

    }

    printLine();
}

void Menu::activateItem(const int &index) {
    menuItems[index].enable();

}

int Menu::getMenuChoice() {

    bool validChoice = false;
    int choice;
    cout << endl;
    cout << "Your choice: " << endl;
    do {
        inputAndCheckIfInt(choice);
        if(choice > menuItems.size() || !menuItems[choice-1].isEnabled()){
            cout << "Choose one of the available menu items... " << endl;
        }
        if(menuItems[choice-1].isEnabled()){
            validChoice = true;
        }
    } while(choice > menuItems.size() || !validChoice);

    return choice;
}