//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_SONG_H
#define KOD_SONG_H
#include <string>
#include <iostream>
#include "Time.h"
#include "constants.h"

class Song {
    std::string title;
    std::string artist;
    Time duration;
public:
    Song() = default;
    Song(std::string &newTitle, std::string &newArtist, Time &newDuration):
            title(newTitle), artist(newArtist), duration(newDuration) {};
    void setTitle(std::string &newTitle);
    void setArtist(std::string &newArtist);
    void setDuration(Time &newDuration);
    std::string getTitle() const { return title; };
    std::string getArtist() const { return artist; };
    Time getDuration() const { return duration; };
};

/**
    Överlagrar ostream-utmatning för klassen

     @param os : utmatningsströmmen
     @param s : låten
     @returns ostream : anpassad utmatningsström
    */
std::ostream &operator<<(std::ostream &os, const Song &s);

/**
    Överlagrar istream-utmatning för klassen

     @param os : inmatningsströmmen
     @param s : låten
     @returns istream : anpassad inmatningsström
    */
std::istream &operator>>(std::istream &is, Song &s);


#endif //KOD_SONG_H
