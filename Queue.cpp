//
// Created by Elin Fritiofsson on 2018-03-02.
//

#include "Queue.h"

Queue::Queue(){
    first = 0;
    last = 0;
    arraySize = 5;
    pArr = new Song[arraySize];
}

Queue::Queue(int size){
    first = 0;
    last = 0;
    arraySize = size;
    pArr = new Song[size];
}

Queue::~Queue() {

    delete []pArr;

}

Queue::Queue(const Queue &other){
    //allokerar plats för en ny array
    auto newArray = new Song[other.arraySize];
    //kopierar över innehållet i other till den nya arrayen
    std::copy(other.pArr, other.pArr+other.last, newArray);
    //sätter pArr att peka på den nya arrayen
    pArr = newArray;
    arraySize = other.arraySize;
    last = other.last;
    first = other.first;
}


Queue& Queue::operator+=(const Song &s) {

    //pArr2 ska peka på en song som ligger i slutet av den befintliga arrayen
    Song *pArr2 = pArr+last;
    *pArr2 = s;

    last += 1;

    return *this;
}


Song Queue::operator++(int) {
    //s pekar på den första låten i arrayen
    Song *s = &pArr[first];
    //first-pekaren flyttas fram ett steg
    first = first+1;
    return *s;
}

//for copying when number of songs > 5
Queue& Queue::operator=(Queue &q){

    auto newArray = new Song[q.arraySize];
    std::copy(q.pArr, q.pArr+q.last, newArray);
    //raderar den gamla arrayen
    delete []pArr;
    //ersätter med den nya
    pArr = newArray;
    arraySize = q.arraySize;
    last = q.last;
    first = q.first;
    return *this;

}


void Queue::enqueue(const Song &data){

    //om kön är full
    if(last == arraySize) {

        //skapa ny array som är 5 element större
        Queue q2(last + 5);
        //kopiera över låtarna dit
        std::copy(pArr, pArr+last, q2.pArr);
        q2.last = last;
        //tilldela den nya kön till denna kö.
        *this = q2;
    }

    *this+=data;

}

bool Queue::dequeue(Song &data){
    if(isEmpty()){
        //pArr ska återigen peka på arrayens början och first+last nollställs
        pArr = &pArr[0];
        first = 0;
        last = 0;
        return false;
    }
    //plocka ut låten som är först i kön
    data = (*this)++;

    return true;
}


bool Queue::isEmpty(){
    return first == last;
}

void Queue::clearQueue() {
    //radera arrayen
    delete []pArr;
    first = 0;
    last = 0;
    arraySize = 5;
    //allokera ny tom array.
    pArr = new Song[arraySize];
}