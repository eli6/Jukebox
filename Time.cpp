//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Time.h"
using std::istream;
using std::string;


void Time::setHours(const int &newHour) {
    hours = newHour;
}

void Time::setMinutes(const int &newMinute) {
    minutes = newMinute;
}

void Time::setSeconds(const int &newSecond) {
    seconds = newSecond;
}

int Time::getTotalSeconds() const {
    int totalSeconds = hours*3600+minutes*60+seconds;
    return totalSeconds;
}

Time Time::operator+(const Time &t2) const {

    Time sum = *this;
    int t1sec = getTotalSeconds();
    int t2sec = t2.getTotalSeconds();
    int sumSec = t1sec + t2sec;
    int newHr, newMin, newSec;
    splitTotalSeconds(sumSec, newHr, newMin, newSec);
    sum.setHours(newHr);
    sum.setMinutes(newMin);
    sum.setSeconds(newSec);

    return sum;

}

bool Time::operator<(const Time &t) const {
    return (getTotalSeconds() < t.getTotalSeconds());
}

bool Time::operator==(const Time &t) const {
    return (getTotalSeconds() == t.getTotalSeconds());
}

std::ostream &operator<<(std::ostream &os, const Time &t){

    int totalSeconds = t.getTotalSeconds();
    os << totalSeconds;
    return os;
}

istream &operator>>(istream &is, Time &t){

    int input;

    is >> input;
    is.get();

    int newHour, newMinute, newSecond;
    splitTotalSeconds(input, newHour, newMinute, newSecond);

    t.setHours(newHour);
    t.setMinutes(newMinute);
    t.setSeconds(newSecond);

    return is;

}

void splitTotalSeconds(int total, int &hour, int &minute, int &second){
    hour = total/3600;
    int remainder = total%3600;
    minute = remainder/60;
    second = remainder%60;
}
