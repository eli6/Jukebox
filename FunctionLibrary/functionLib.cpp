//
// Created by Elin Fritiofsson on 2018-01-30.
//

#include "functionLib.h"
using namespace std;

std::string stringToLowercase(std::string originalString){
    for(auto &c: originalString){
        c = static_cast<char>(tolower(c));
    }
    return originalString;
}

char userWantsToRepeat(string question){
    char again;
    printLine();
    cout << question << " (y/n)" << endl;
    do {
        cin >> again;
        printLine();
        cin.get();
        again = static_cast<char>(toupper(again));
    } while( !(again == 'Y' || again == 'N'));
    return again;
}

void printStarLine(){
    cout << "*********************************************************************************************************************************" << endl;
}

void printLine(){
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void inputAndCheckIfInt(int &variable){
    bool correctInput = false;
    do {
        cin >> variable;
        cin.get();

        //Kontrollera om inmatningen lyckas
        if(!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a number" << endl;
            correctInput = false;
        } else {
            correctInput = true;
        }
    } while(!correctInput);
}



void returnToMenu(){
    cout << "Press enter to return to the previous menu." << endl;
    cin.get();
}

void removeFirstZero(std::string &timeUnit){
    if(timeUnit[0] == '0' && timeUnit.length() > 1){
        timeUnit = timeUnit[1];
    }
}