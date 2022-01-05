/*
 * Room
 * stores room data
 */
#ifndef ROOM_h
#define ROOM_h
#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Room
{
    public:
        int _x;
        int _y;
        string _dsc; //room description
        struct items { //items
            bool hasItems;
            bool item1;
            bool item2;
            bool item3;
            bool item4;
            bool item5;
        };
        items inRoom; //item struct
        map<int, bool> exits; //exits
        map<int, bool>::iterator itr; //iterator
        Room();
        void setRoom(int, int, string, int, bool, bool, bool, bool); //create a room
        void Info(); //print info about the room

    private:
};
#endif
