#include <iostream>
#include "Player.h"
using namespace std;

Player::Player()
{
    inventory inv;
}

void Player::readInv()
{
    cout << "\n--- Inventory ---" << endl;
    if(inv.item1 == true) cout << " - 1" << endl;
    if(inv.item2 == true) cout << " - 2" << endl;
    if(inv.item3 == true) cout << " - 3" << endl;
    if(inv.item4 == true) cout << " - 4" << endl;
    if(inv.item5 == true) cout << " - 5" << endl;
}

void Player::get(int i)
{
    switch (i) {
        case 1:
            inv.item1 = true;
            break;
        case 2:
            inv.item2= true;
            break;
        case 3:
            inv.item3 = true;
            break;
        case 4:
            inv.item4 = true;
            break;
        case 5:
            inv.item5 = true;
            break;
        default:
            cout << "\nswitch block defaulted" << endl;
    }
}

void Player::drop(int i)
{
    switch (i) {
        case 1:
            inv.item1 = false;
            break;
        case 2:
            inv.item2 = false;
            break;
        case 3:
            inv.item3 = false;
            break;
        case 4:
            inv.item4 = false;
            break;
        case 5:
            inv.item5 = false;
            break;
        default:
            cout << "\nswitch block defaulted" << endl;
            break;
    }
}
