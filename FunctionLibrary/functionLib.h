//
// Created by Elin Fritiofsson on 2018-01-30.
//

#ifndef LABBEN_FUNCTIONLIB_H
#define LABBEN_FUNCTIONLIB_H

#include<iostream>
#include<string>
#include<vector>
#include<limits>

    /**
    Gör om en sträng till lowercase utan att påverka originalsträngen

     @param originalString : strängen som ska bli lowercase
     @returns std::string : lowercase-kopia av strängen
    */
    std::string stringToLowercase(std::string originalString);

    /**
    Frågar om användaren vill upprepa proceduren

     @param question : frågan användaren ska få
     @returns char : Y eller N (stora bokstäver) beroende på användarens svar
    */
    char userWantsToRepeat(std::string question);

    /**
    Layoutfunktion. Skriver ut en rad med stjärnor (***...)
    */
    void printStarLine();

    /**
    Layoutfunktion. Skriver ut en streckad rad (---...)
    */
    void printLine();

    /**
    Tilldelar ett värde till en int-variabel och kontrollerar att inmatningen lyckas.

     @param variable : variabeln som ska få ett värde
    */
    void inputAndCheckIfInt(int &variable);

    /**
    Skriver ut en meny med menyval.

    @param menuChoices : menyvalen i menyn.
    @returns int : användarens menyval
    */
    int printMenu(std::vector<std::string> menuChoices);

    /**
    Ber användaren trycka på enter för att återgå till menyn
    */
    void returnToMenu();

    void removeFirstZero(std::string &timeUnit);

#endif //LABBEN_FUNCTIONLIB_H
