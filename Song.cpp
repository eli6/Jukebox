//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Song.h"
using std::string;

/*Song::Song() {
    title = "";
    artist = "";
    duration = Time();
}*/

void Song::setTitle(string &newTitle) {
    title = newTitle;
}

void Song::setArtist(std::string &newArtist) {
    artist = newArtist;
}

void Song::setDuration(Time &newDuration) {
    duration = newDuration;
}

std::ostream &operator<<(std::ostream &os, const Song &s){
    os << s.getTitle() << DELIM;
    os << s.getArtist() << DELIM;
    os << s.getDuration() << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Song &s){

    string input;
    getline(is, input, DELIM);
    s.setTitle(input);

    getline(is, input, DELIM);
    s.setArtist(input);

    Time newDuration;
    is >> newDuration;

    s.setDuration(newDuration);

    return is;
}