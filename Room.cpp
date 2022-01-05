#include <iostream>
#include "Room.h"
#include <string>
#include <map>
#include <iterator>
using namespace std;

Room::Room(){}

//on initialization
void Room::setRoom(int x, int y, string dsc, int item, bool n, bool s, bool e, bool w)
{
    //room address and description
    _x = x;
    _y = y;
    _dsc = dsc;
    //set items
    switch (item) {
        case 1:
            inRoom.item1 = true;
            inRoom.hasItems = true;
            break;
        case 2:
            inRoom.item2 = true;
            inRoom.hasItems = true;
            break;
        case 3:
            inRoom.item3 = true;
            inRoom.hasItems = true;
            break;
        case 4:
            inRoom.item4 = true;
            inRoom.hasItems = true;
            break;
        case 5:
            inRoom.item5 = true;
            inRoom.hasItems = true;
            break;
        default:
            break;
    }
    //set exits
    exits.insert(pair<int, bool>(1, n));
    exits.insert(pair<int, bool>(2, s));
    exits.insert(pair<int, bool>(3, e));
    exits.insert(pair<int, bool>(4, w));
}

//print info about the room
void Room::Info()
{
    //room number
    cout << "\nRoom Coordinates: " << _x << ", " << _y << endl;
    //description
    cout << "\nDescription:\n" << _dsc << endl;
    //items
    cout << "\n--- Items in Room ---" << endl;
    if (inRoom.item1 == true) cout << "- 1" << endl;
    if (inRoom.item2 == true) cout << "- 2" << endl;
    if (inRoom.item3 == true) cout << "- 3" << endl;
    if (inRoom.item4 == true) cout << "- 4" << endl;
    if (inRoom.item5 == true) cout << "- 5" << endl;

    //exits
    cout << "\n--- Exits ---" << endl;
    for (itr = exits.begin(); itr != exits.end(); ++itr) {
        if (itr->second == true) {
            switch (itr->first) {
                case 1:
                    cout << "- North" << endl;
                    break;
                case 2:
                    cout << "- South" << endl;
                    break;
                case 3:
                    cout << "- East" << endl;
                    break;
                case 4:
                    cout << "- West" << endl;
                    break;
                default:
                    break;
            }
        }
    }
}
