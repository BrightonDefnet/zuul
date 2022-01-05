/*
 * Player
 * stores player variables
 */
#ifndef PLAYER_h
#define PLAYER_h
#include <iostream>
using namespace std;

class Player
{
    public:
        Player();
        struct inventory { //player inventory
            bool item1;
            bool item2;
            bool item3;
            bool item4;
            bool item5;
        };
        inventory inv;
        void readInv(); //display contents of the player's inventory
        void get(int); //pick up an item
        void drop(int); //drop an item
    private:
};
#endif
