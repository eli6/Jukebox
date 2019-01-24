//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_MENUITEM_H
#define KOD_MENUITEM_H

#include <string>

class MenuItem {
private:
    std::string menuText;
    bool enabled;
public:
    MenuItem() = default;
    MenuItem(std::string newMenuText, bool newEnabled);
    void setMenuText(std::string newMenuText);
    std::string getMenuText() const { return menuText; };
    bool isEnabled() { return enabled; }; //!<Kontrollerar om ett menyval är aktiverat (getter för "enable")
    void enable(); //!<Aktiverar ett menyval (setter för "enable")
};


#endif //KOD_MENUITEM_H
