//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Album.h"
using std::string;
using std::cin;
using std::endl;


void Album::setName(std::string newTitle) {
    name = newTitle;
}

void Album::addSong(const Song &s) {
    songList.push_back(s);
}

bool Album::operator<(const Album &a) const {

    return getTotalTime() < a.getTotalTime();
}

int Album::getTotalTime() const {
    int total = 0;
    for(const auto &song : songList){
        total += song.getDuration().getTotalSeconds();
    }
    return total;
}


std::ostream &operator<<(std::ostream &os, const Album &a){
    os << a.getName() << endl;
    os << a.getSongList().size() << endl;
    for(auto &song : a.getSongList()){
        os << song;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Album &a){

    string newTitle;
    getline(is, newTitle);
    a.setName(newTitle);

    int numberOfSongs = 0;
    is >> numberOfSongs;
    is.get();

    //Add each song to the album
    Song newSong;
    for(int i = 0; i < numberOfSongs; i++){
        is >> newSong;
        a.addSong(newSong);
    }

    return is;

}