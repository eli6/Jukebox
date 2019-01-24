//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_ALBUM_H
#define KOD_ALBUM_H
#include <string>
#include <vector>
#include "Song.h"

class Album {
private:
    std::string name;
    std::vector<Song> songList;
public:
    Album() = default;
    void setName(std::string newTitle);
    std::string getName() const {return name;};
    void addSong(const Song &s);
    std::vector<Song> getSongList() const { return songList; };
    bool operator<(const Album &a) const;
    int getTotalTime() const; //!< Returns total time for the album

};

/**
    Överlagrar ostream-utmatning för klassen

     @param os : utmatningsströmmen
     @param a : albumet
     @returns ostream : anpassad utmatningsström
    */
std::ostream &operator<<(std::ostream &os, const Album &a);

/**
    Överlagrar istream-utmatning för klassen

     @param os : inmatningsströmmen
     @param a : albumet
     @returns istream : anpassad inmatningsström
    */
std::istream &operator>>(std::istream &is, Album &a);


#endif //KOD_ALBUM_H
