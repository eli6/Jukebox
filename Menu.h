//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_MENU_H
#define KOD_MENU_H
#include <string>
#include <vector>
#include <iostream>
#include "MenuItem.h"
#include "FunctionLibrary/functionLib.h"

class Menu {
private:
    std::vector<MenuItem> menuItems;
    std::string menuTitle;
public:
    Menu() = default;
    Menu(std::string &newMenuTitle, std::vector<MenuItem> &newItemsVector):
            menuTitle(newMenuTitle), menuItems(newItemsVector) {};
    void setTitle(std::string newTitle);
    std::string getMenuTitle() const { return menuTitle; };
    void addItem(std::string menuText, bool enabled);
    void printMenuItems();
    int getMenuChoice();

    std::vector<MenuItem> getMenuItems(){ return menuItems; };
    void activateItem(const int &index);


};


#endif //KOD_MENU_H
