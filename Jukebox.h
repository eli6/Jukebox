//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_JUKEBOX_H
#define KOD_JUKEBOX_H

#include <fstream>
#include "Album.h"
#include <algorithm>
#include "Queue.h"
#include <iomanip>
#include <chrono>
#include <thread>
#include "Menu.h"
#include "FunctionLibrary/functionLib.h"


class Jukebox {
private:
    std::vector<Album> albumList;
    Menu basicMenu;
    Menu fileMenu;
    Menu printMenu;
    Menu playMenu;
    Queue playlist;
    void addAlbum(); //!< adds album and checks that it's name is unique
    void removeAlbum(); //!< removes album identified by name

    //file menu with associated functions
    void file(); //!< "file" menu
    void open(); //!< open file with the name defined in "constants.h"
    void save(); //!< save jukebox content to file with the name in "constants.h"

    //print menu with associated functions
    void print(); //!< "print" menu
    std::vector<Album>::const_iterator findAlbumWithName(); //!< Finds an album for the user
    void printOne(); //!< Prints one album
    void sortAlbumsAlphabetically();
    void sortAlbumsByLength();
    void showNamesAlphabetically(); //!< "Simple" print. Only album names. Sorted alphabetically
    void showNamesByTotalLength(); //!< "Simple" print. Sorted by length

    //play menu with associated functions
    void play(); //!< "play" menu
    void createPlaylist();
    void createRandomPlaylist();
    void playPlaylist();

public:
    Jukebox();
    void run();
};

/**
    Visar information om ett album

     @param a : albumet
     @param placement : albumets nummer i ordningsföljden på utskriften
    */
void showAlbumInfo(Album const &a, int placement);

/**
    Formaterar tiden korrekt för utskrift på skärm (tar bort onödiga nollor)

     @param hours, minutes, seconds : tidens värden för timme, minut, sekund
     @returns string : en utskriftsklar tidssträng...
    */
std::string formatTimeForPrinting(int hours, int minutes, int seconds);

/**
    Visar information om en låt

     @param song : låten vars information ska visas
     @param songNumber : låtens nummer i ordningsföljden på skärmen.
    */
void showSongInfo(const Song &song, int songNumber);

/**
    Visar information om ett album

     @param a : albumet vars information ska visas
     @param placement : albumets nummer i ordningsföljden på skärmen.
    */
void showAlbumInfo(Album const &a, int placement);

#endif //KOD_JUKEBOX_H
