//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Jukebox.h"
using std::cout;
using std::endl;


Jukebox::Jukebox() {

    //initialization of menus and blocking of access to certain menu options.

    basicMenu.setTitle("JUKEBOX");
    basicMenu.addItem("File...", true);
    basicMenu.addItem("Add album...", false);
    basicMenu.addItem("Delete album...", false);
    basicMenu.addItem("Print...", false);
    basicMenu.addItem("Play...", false);
    basicMenu.addItem("Exit", true);

    fileMenu.setTitle("FILE");
    fileMenu.addItem("Open...", true);
    fileMenu.addItem("Save...", false);
    fileMenu.addItem("Back to main menu", true);

    printMenu.setTitle("PRINT");
    printMenu.addItem("Print one album", true);
    printMenu.addItem("Print all albums sorted by name", true);
    printMenu.addItem("Print all albums sorted by album total time", true);
    printMenu.addItem("Print simple sorted by album name", true);
    printMenu.addItem("Print simple sorted by album total time", true);
    printMenu.addItem("Back to main menu", true);

    playMenu.setTitle("PLAYLIST");
    playMenu.addItem("Create playlist from songs", true);
    playMenu.addItem("Create random list", true);
    playMenu.addItem("Play list", true);
    playMenu.addItem("Back to main menu", true);
}

void Jukebox::run() {

    bool again = true;
    //prints menu items and prompts the user for a choice
    do {

        basicMenu.printMenuItems();

        switch(basicMenu.getMenuChoice()){
            case 1: file();
                break;
            case 2: addAlbum();
                break;
            case 3: removeAlbum();
                break;
            case 4: print();
                break;
            case 5: play();
                break;
            case 6: again = false;
                break;

            default:break;
        }
    } while(again);
}


void Jukebox::file() {

    bool again = true;
    //prints menu items and prompts the user for a choice
    do {
        fileMenu.printMenuItems();

        switch (fileMenu.getMenuChoice()) {
            case 1: open();
                break;
            case 2: save();
                break;
            case 3: again = false;

            default:break;
        }
    }while(again);

}


void Jukebox::print() {

    bool again = true;
    //prints menu items and prompts the user for a choice
    do {
        printMenu.printMenuItems();


        switch (printMenu.getMenuChoice()) {
            case 1: printOne();
                break;
            case 2: sortAlbumsAlphabetically();
                break;
            case 3: sortAlbumsByLength();
                break;
            case 4: showNamesAlphabetically();
                break;
            case 5: showNamesByTotalLength();
                break;
            case 6:
                again = false;


            default:break;
        }
    }while(again);
}

void Jukebox::play() {

    bool again = true;
    //prints menu items and prompts the user for a choice
    do {
        playMenu.printMenuItems();


        switch (playMenu.getMenuChoice()) {
            case 1: createPlaylist();
                break;
            case 2: createRandomPlaylist();
                break;
            case 3: playPlaylist();
                break;
            case 4: again = false;

            default:break;
        }
    }while(again);
}


void Jukebox::addAlbum() {

    do {
        Album a;
        std::string newName;
        bool again = false;

        do {
            again = false;
            cout << "Enter album name:" << endl;
            getline(std::cin, newName);

            //checks uniqueness of album name
            for (auto &alb : albumList) {
                if (stringToLowercase(newName) == stringToLowercase(alb.getName())) {
                    cout << "The album already exists!" << endl;
                    again = true;
                }
            }
        } while (again);


        a.setName(newName);

        //prompts user for data for a song of the album as long as the user wants to add new songs
        do {
            Song s;
            cout << "Enter song name:" << endl;
            std::string input;
            getline(std::cin, input);
            s.setTitle(input);

            cout << "Enter artist name:" << endl;
            getline(std::cin, input);
            s.setArtist(input);

            int hour, minute, second;
            Time t;

            //keeps track of time validity for the "while" condition
            bool timeOK;

            //prompts for song duration until user enters valid time values
            do{
                timeOK = true;

                //holds number of delimiters (:) in input of time (2) xx:xx:xx or (1) xx:xx
                long delimiterCount;

                do {
                    cout << "Enter song length (hh):(m)m:ss:" << endl;
                    getline(std::cin, input);
                    delimiterCount = std::count(input.begin(), input.end(), TIME_DELIM);
                } while (delimiterCount != 2 && delimiterCount != 1);

                std::string hourString = "0";
                std::string minuteString = "0";
                std::string secondString = "0";

                //if input has three parts: xx:xx:xx
                if (delimiterCount == 2) {

                    //remove first xx from input and use as hours:
                    hourString = input.substr(0, input.find(TIME_DELIM));
                    //erase that part
                    input.erase(0, input.find(TIME_DELIM) + 1);
                    //remove preceeding 0 if needed
                    removeFirstZero(hourString);
                }

                //same with minutes (we start here if input is xx:xx)
                minuteString = input.substr(0, input.find(TIME_DELIM));
                input.erase(0, input.find(TIME_DELIM) + 1);
                removeFirstZero(minuteString);

                //use last part of input as value for seconds
                secondString = input;
                removeFirstZero(secondString);


                try {
                    //try to convert the strings to int
                    hour = stoi(hourString);
                    minute = stoi(minuteString);
                    second = stoi(secondString);
                } catch (std::exception &e) {
                    cout << "Wrong time format. You will have to enter the song data again" << endl;
                    timeOK = false;
                }

                //check that the time units have reasonable value
                if(hour < 0 || (minute > 60 || minute < 0) || (second > 60 || second < 0)){
                    cout << "Time must be a positive number, and minutes and seconds below 60!" << endl;
                    timeOK = false;
                }

            } while (!timeOK);


            t.setHours(hour);
            t.setMinutes(minute);
            t.setSeconds(second);

            s.setDuration(t);

            a.addSong(s);


        } while (userWantsToRepeat("Do you want to add another song?") != 'N');

        //add the album to the album list
        albumList.push_back(a);

    } while (userWantsToRepeat("Do you want to add another album?")!='N');
}

void Jukebox::removeAlbum() {

    do{
        auto it = findAlbumWithName();

        //erases album pointed to by it (if the iterator actually points to an album in the list)
        if(it!=albumList.end()){
            Album a = *it;
            albumList.erase(it);
            cout << "Album " << a.getName() << " was erased." << endl;
        }

    } while(userWantsToRepeat("Do you want to remove another album?")!='N');


}

//-----------------------------------------
//
// Functions for menu File()
//-----------------------------------------
void Jukebox::open(){
    //Import album list from file if the file can be found.
    std::fstream inFile(FILENAME,std::ios::in);
    if(inFile.is_open()){
        if(!albumList.empty()){
            albumList.clear();
        }
        bool again = true;
        while(again) {
            Album newAlbum;
            inFile >> newAlbum;
            //if input fails, stop entering data.
            if(inFile.fail()){
                again = false;
            }
            //or, if album name is empty, stop entering data.
            if(newAlbum.getName() != ""){
                albumList.push_back(newAlbum);
            }

        }
        inFile.close();
        cout << "Import finished." << endl;

        //now, activate everything in the basic menu that is disabled
        for(int i = 0; i < basicMenu.getMenuItems().size(); ++i){
            if(!basicMenu.getMenuItems()[i].isEnabled()){
                basicMenu.activateItem(i);
            }
        }

        //activate every menu choice in file Menu as well
        for(int i = 0; i < fileMenu.getMenuItems().size(); ++i){
            if(!fileMenu.getMenuItems()[i].isEnabled()){
                fileMenu.activateItem(i);
            }
        }

    } else {
        cout << "Couldn't find file. Will use file name for export later." << endl;
    }
    returnToMenu();
}

void Jukebox::save(){
    std::ofstream outFile(FILENAME);
    if(outFile.is_open()){
        //write each album to file.
        std::for_each(albumList.begin(), albumList.end(), [&outFile](const Album &a1){
            outFile << a1;
        });
        cout << "Wrote album list to file: " << FILENAME << endl;
    }
}



//-----------------------------------------
//
// Functions for menu Print()
//-----------------------------------------


std::vector<Album>::const_iterator Jukebox::findAlbumWithName(){

    std::string name;
    cout << "Enter the album name: " << endl;
    getline(std::cin, name);
    //Make a copy of name lowercase for comparison
    std::string lowercaseName = stringToLowercase(name);
    printLine();

    auto it = std::find_if(albumList.begin(), albumList.end(), [&lowercaseName](Album a) {
                //Make a copy of the compared album name lowercase.
                std::string lowercaseAlbumName = stringToLowercase(a.getName());
                //Try to find an album with that name
                return lowercaseAlbumName == lowercaseName;

            });
    //If album found, return iterator to it
    if(it != albumList.end()){
        return it;
    }
    cout << "The album was not found" << endl;
    return it;
}

void Jukebox::printOne(){
    //temporary solution

    do {
        auto it = findAlbumWithName();

        //If we have an iterator to a found album, print that album's data
        if(it!=albumList.end()) {
            Album a = *it;
            cout << "Resultat: " << endl;
            printLine();
            showAlbumInfo(a, 1);
        }
    } while(userWantsToRepeat("Search again?") != 'N');

    returnToMenu();
}



void Jukebox::sortAlbumsAlphabetically() {
    printLine();
    cout << "ALBUMS SORTED ALPHABETICALLY (ASCENDING)" << endl;
    printLine();
    //sort whole album list alphabetically.
    std::sort(albumList.begin(), albumList.end(), [](const Album &a1, const Album &a2) {
        //create lowercase versions
        std::string a1Lowercase = stringToLowercase(a1.getName());
        std::string a2Lowercase = stringToLowercase(a2.getName());
        return a1Lowercase < a2Lowercase;
    });
    int counter = 1;
    //print data for each album on screen.
    for(const auto &album : albumList){
        showAlbumInfo(album, counter);
        counter++;
    }
    printLine();
    returnToMenu();
}

void Jukebox::sortAlbumsByLength(){
    printLine();
    cout << "ALBUMS SORTED BY DURATION (DESCENDING)" << endl;
    printLine();
    //Sort album list according to longest duration (operator < is overloaded for album)
    std::sort(albumList.begin(), albumList.end(), [](const Album &a1, const Album &a2) {
        return a2 < a1;
    });
    int counter = 1;
    for(const auto &album : albumList){
        showAlbumInfo(album, counter);
        ++counter;
    }
    printLine();
    returnToMenu();
}

void Jukebox::showNamesAlphabetically() {
    printLine();
    cout << "ALBUM NAMES SORTED ALPHABETICALLY (ASCENDING)" << endl;
    printLine();
    //sort album list according to names
    std::sort(albumList.begin(), albumList.end(), [](const Album &a1, const Album &a2) {
        //create lowercase versions
        std::string a1Lowercase = stringToLowercase(a1.getName());
        std::string a2Lowercase = stringToLowercase(a2.getName());
        return a1Lowercase < a2Lowercase;
    });
    //print names on screen
    std::for_each(albumList.begin(), albumList.end(), [](const Album &a1){
        std::cout << a1.getName() << endl;
    });
    printLine();
    returnToMenu();
}

void Jukebox::showNamesByTotalLength() {
    printLine();
    cout << "ALBUM NAMES SORTED BY DURATION (DESCENDING)" << endl;
    printLine();
    //sort by duration
    std::sort(albumList.begin(), albumList.end(), [](const Album &a1, const Album &a2) {
        return a2 < a1;
    });
    //print name and duration on screen

    std::for_each(albumList.begin(), albumList.end(), [](const Album &a1){
        //split up the total time into hours, minutes, seconds
        int hours, minutes, seconds;
        splitTotalSeconds(a1.getTotalTime(), hours, minutes, seconds);
        std::string printTime = formatTimeForPrinting(hours, minutes,seconds);
        std::cout << a1.getName() << " - " << printTime << endl;
    });
    printLine();
    returnToMenu();
}


//helper function for printing time on screen
std::string formatTimeForPrinting(int hours, int minutes, int seconds){

    std::string hourString = std::to_string(hours);
    std::string minuteString = std::to_string(minutes);
    std::string secondString = std::to_string(seconds);

    //add a zero to seconds if needed
    if(seconds < 10){
        secondString = "0" + secondString;
    }
    if(hours > 0){
        //add a zero to minutes if needed
        if(minutes < 10){
            minuteString = "0" + minuteString;
        }
        return hourString + TIME_DELIM + minuteString + TIME_DELIM + secondString;
    }

    return minuteString + TIME_DELIM + secondString;
}

void showSongInfo(const Song &song, int songNumber){
    std::string printTime = formatTimeForPrinting(song.getDuration().getHours(), song.getDuration().getMinutes(), song.getDuration().getSeconds());
    cout << songNumber << ". " << song.getArtist() << SONG_DELIM << song.getTitle() << SONG_DELIM << printTime << endl;
}

void showAlbumInfo(Album const &a, int placement){
    int hours, minutes, seconds;
    splitTotalSeconds(a.getTotalTime(), hours, minutes, seconds);
    std::string totalTime = formatTimeForPrinting(hours, minutes,seconds);

    printStarLine();
    cout << placement << SONG_DELIM << a.getName() << SONG_DELIM << totalTime << endl;
    printStarLine();

    int songNumber = 1;
    for(const auto &song : a.getSongList()){
        showSongInfo(song, songNumber);
        ++songNumber;
    }
}

//-----------------------------------------
//
// Functions for menu Play()
//-----------------------------------------
void Jukebox::createPlaylist(){

    //clear the playlist so that it is empty before new creation
    playlist.clearQueue();

    std::vector<Song> songList;
    int songNumber = 1;
    //show song info and add song to new vector
    for(const auto &a: albumList){
        for(const auto &s: a.getSongList()){
            showSongInfo(s, songNumber);
            songList.push_back(s);
            ++songNumber;
        }
    }

    cout << "Write a list of songs you want to add to the playlist (ex: 3,14,11)" << endl;
    std::string wishList;
    getline(std::cin, wishList);

    //count number of "," in input
    int delimiterCount = static_cast<int>(std::count(wishList.begin(), wishList.end(), ','));
    for(int i = 0; i < delimiterCount; i++){
        std::string wish = wishList.substr(0, wishList.find(','));
        wishList.erase(0, wishList.find(',') + 1);

        try {
            int wishIndex = stoi(wish);
            if(wishIndex <= songList.size()){
                playlist.enqueue(songList[wishIndex-1]);
                cout << "Adding song: " << songList[wishIndex-1].getTitle() << " to playlist." << endl;
            }
        } catch (std::exception &e) {
            cout << "Recognized input that is not a number. Cannot add to playlist." << endl;
        }

    }

    std::string wish = wishList.substr(0, wishList.find(','));
    wishList.erase(0, wishList.find(',') + 1);

    try {
        int wishIndex = stoi(wish);
        if(wishIndex <= songList.size()){
            playlist.enqueue(songList[wishIndex-1]);
            cout << "Adding song: " << songList[wishIndex-1].getTitle() << " to playlist." << endl;
        }
    } catch (std::exception &e) {
        cout << "Recognized input that is not a number. Cannot add to playlist." << endl;
    }


    returnToMenu();

}

void Jukebox::createRandomPlaylist() {

    playlist.clearQueue();

    //create vector with all available songs.
    std::vector<Song> songList;
    int songNumber = 1;
    for(const auto &a: albumList){
        for(const auto &s: a.getSongList()){
            showSongInfo(s, songNumber);
            songList.push_back(s);
            ++songNumber;
        }
    }

    int numberOfSongs;
    cout << "How many songs do you want in your playlist?" << endl;
    inputAndCheckIfInt(numberOfSongs);

    //randomize vector and enqueue the necessary number of songs to the playlist.
    std::random_shuffle(songList.begin(), songList.end());
    for(int i=0; i<numberOfSongs; i++){
        playlist.enqueue(songList[i]);
        cout << "Adding song: " << songList[i].getTitle() << " to playlist." << endl;
    }

}

void Jukebox::playPlaylist(){

    //create copy of playlist for playing.
    Queue playlistCopy(playlist);

    Song s;

    //dequeue on song at a time and output its title on screen.
    while(playlistCopy.dequeue(s)){
        cout << "Now playing: " << s.getTitle() << endl;
        //wait 1 second before resuming loop.
        std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    }

    cout << "END OF PLAYLIST" << endl;
    returnToMenu();

}