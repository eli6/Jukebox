//
// Created by Elin Fritiofsson on 2018-03-02.
//

#ifndef KOD_QUEUE_H
#define KOD_QUEUE_H

#include <algorithm>
#include <iterator>
#include "Song.h"

class Queue {
private:
    Song *pArr;
    int arraySize;
    int first;
    int last;

public:

    Queue();
    Queue(int size); //!< Konstruktor som initierar kö med viss storlek
    Queue(const Queue &other);
    ~Queue();
    void enqueue(const Song &data);
    bool dequeue(Song &data);

    Queue& operator+=(const Song &s); //!<Lägger till en sång i kön
    Song operator++(int);
    Queue& operator=(Queue &q);

    bool isEmpty(); //!< Kontrollerar om kön är tom

    void clearQueue(); //!<Tömmer kön och nollställer variablerna

};


#endif //KOD_QUEUE_H*/
