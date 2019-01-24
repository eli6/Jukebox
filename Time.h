//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_TIME_H
#define KOD_TIME_H
#include <iostream>
#include "constants.h"

class Time {
private:
    int hours, minutes, seconds;
public:
    Time() = default;
    Time(int newHour, int newMinute, int newSecond):
            hours(newHour), minutes(newMinute), seconds(newSecond) {};
    void setHours(const int &newHour);
    void setMinutes(const int &newMinute);
    void setSeconds(const int &newSecond);
    int getHours() const {return hours;};
    int getMinutes() const {return minutes;};
    int getSeconds() const {return seconds;};
    int getTotalSeconds () const; //!< Computes total song duration in seconds


    Time operator+(const Time &t2) const; //!<Adderar två tider och returnerar nytt tidsobjekt
    bool operator<(const Time &t) const;
    bool operator==(const Time &t) const;
};

/**
    Överlagrar ostream-utmatning för klassen

     @param os : utmatningsströmmen
     @param t : tiden
     @returns ostream : anpassad utmatningsström
    */
std::ostream &operator<<(std::ostream &os, const Time &t);

/**
    Överlagrar istream-utmatning för klassen

     @param os : inmatningsströmmen
     @param t : tiden
     @returns istream : anpassad inmatningsström
    */
std::istream &operator>>(std::istream &is, Time &t);

/**
    Delar upp en total tid (s) i timme, minut och sekunder

     @param total : den totala tiden i sekunder
     @param hour, minute, second : variabler skickade som referenser som tiden ska lagras i
    */
void splitTotalSeconds(int total, int &hour, int &minute, int &second);

#endif //KOD_TIME_H
