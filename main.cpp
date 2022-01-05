/*
 * Zuul, Brighton Defnet 2022
 * based on the text-based game Zuul
*/
#include <iostream>
#include <utility>
#include "Player.h"
#include "Room.h"
using namespace std;

//initialize the maze
void buildMaze(Room maze[5][7])
{
    //(x, y, description, starting item, north, south, east, west)
    maze[2][6].setRoom(2, 6, "another normal room", 0, true, false, true, false); //starting area
    maze[3][6].setRoom(3, 6, "another normal room", 1, false, false, false, true);
    maze[2][5].setRoom(2, 5, "another normal room", 0, true, true, false, false);
    maze[2][4].setRoom(2, 4, "another normal room", 0, true, true, false, true);
    maze[1][4].setRoom(1, 4, "another normal room", 0, false, false, true, true);
    maze[0][4].setRoom(0, 4, "another normal room", 2, false, false, true, false);
    maze[4][3].setRoom(4, 3, "another normal room", 4, false, false, false, true);
    maze[3][3].setRoom(3, 3, "another normal room", 0, false, false, true, true);
    maze[2][3].setRoom(2, 3, "another normal room", 0, true, true, true, false);
    maze[2][2].setRoom(2, 2, "another normal room", 0, true, true, false, false);
    maze[0][2].setRoom(0, 2, "another normal room", 3, true, false, false, false);
    maze[2][1].setRoom(2, 1, "another normal room", 0, true, true, false, true);
    maze[1][1].setRoom(1, 1, "another normal room", 0, false, false, true, true);
    maze[0][1].setRoom(0, 1, "another normal room", 0, false, true, true, false);
    maze[2][0].setRoom(2, 0, "another normal room", 5, false, true, false, false);
}

//move into another room
void move(Room maze[5][7], pair<int,int> currentRoom)
{
    maze[currentRoom.first][currentRoom.second].Info();
}

//take an item from the room
void take(Room maze[5][7], pair<int,int> currentRoom, Player *player)
{
    int itemNum;
    cout << "\npick up which item?" << endl;
    cin >> itemNum;
    switch (itemNum) {
        case 1:
            if (maze[currentRoom.first][currentRoom.second].inRoom.item1 == true) {
                maze[currentRoom.first][currentRoom.second].inRoom.item1 = false;
                player->get(1);
                cout << "\npicked up Item 1!" << endl;
            } else {
                cout << "that item isn't in the room!" << endl;
            }
            break;
        case 2:
            if (maze[currentRoom.first][currentRoom.second].inRoom.item2 == true) {
                maze[currentRoom.first][currentRoom.second].inRoom.item2 = false;
                player->get(2);
                cout << "\npicked up Item 2!" << endl;
            } else {
                cout << "that item isn't in the room!" << endl;
            }
            break;
        case 3:
            if (maze[currentRoom.first][currentRoom.second].inRoom.item3 == true) {
                maze[currentRoom.first][currentRoom.second].inRoom.item3 = false;
                player->get(3);
                cout << "\npicked up Item 3!" << endl;
            } else {
                cout << "that item isn't in the room!" << endl;
            }
            break;
        case 4:
            if (maze[currentRoom.first][currentRoom.second].inRoom.item4 == true) {
                maze[currentRoom.first][currentRoom.second].inRoom.item4 = false;
                player->get(4);
                cout << "\npicked up Item 4" << endl;
            } else {
                cout << "that item isn't in the room!" << endl;
            }
            break;
        case 5:
            if (maze[currentRoom.first][currentRoom.second].inRoom.item5 == true) {
                maze[currentRoom.first][currentRoom.second].inRoom.item5 = false;
                player->get(5);
                cout << "\npicked up Item 5!" << endl;
            } else {
                cout << "that item isn't in the room!" << endl;
            }
            break;
        default:
            cout << "switch block defaulted" << endl;
    }
}

//drop item
void drop(Room maze[5][7], pair<int,int> currentRoom, Player *player)
{
    int itemNum; 
    cout << "\ndrop which item?" << endl;
    cin >> itemNum;
    switch (itemNum) {
        case 1:
            if (player->inv.item1 == true) {
                player->drop(1);
                maze[currentRoom.first][currentRoom.second].inRoom.item1 = true;
            } else {
                cout << "that item isn't in your inventory!" << endl;
            }
            break;
        case 2:
            if (player->inv.item2 == true) {
                player->drop(2);
                maze[currentRoom.first][currentRoom.second].inRoom.item2 = true;
            } else {
                cout << "that item isn't in your inventory!" << endl;
            }
            break;
        case 3:
            if (player->inv.item3 == true) {
                player->drop(3);
                maze[currentRoom.first][currentRoom.second].inRoom.item3 = true;
            } else {
                cout << "that item isn't in your inventory!" << endl;
            }
            break;
        case 4:
            if (player->inv.item4 == true) {
                player->drop(4);
                maze[currentRoom.first][currentRoom.second].inRoom.item4 = true;
            } else {
                cout << "that item isn't in your inventory!" << endl;
            }
            break;
        case 5:
            if (player->inv.item5 == true) {
                player->drop(5);
                maze[currentRoom.first][currentRoom.second].inRoom.item5 = true;
            } else {
                cout << "that item isn't in your inventory!" << endl;
            }
            break;
        default:
            cout << "switch block defaulted" << endl;
    }
}

//check for a win condition
bool checkWin(Player *player) {
   if (
           player->inv.item1 == true
           && player->inv.item2 == true
           && player->inv.item3 == true
           && player->inv.item4 == true
           && player->inv.item5 == true
           ) {
       cout << "\nAll items collected. You win!" << endl;
       return false;
   } else {
       return true;
   }
}

//main function
int main()
{
    //build the maze and start in the starting room
    Room maze[5][7];
    Player player;
    buildMaze(maze);
    pair<int,int> currentRoom;
    currentRoom.first = 2;
    currentRoom.second = 6;
    move(maze, currentRoom);
    bool playing = true;
    printf("\033c");
    move(maze, currentRoom);

    //while playing
    while (playing == true)
    {
        string command;
        cout << "\nwhat would you like to do?\n(north, south, east, west, take, drop, inventory, check, quit)" << endl;
        cin >> command;
        if (command == "north" && maze[currentRoom.first][currentRoom.second].exits[1] == true) {
            --currentRoom.second;
            printf("\033c");
            move(maze, currentRoom);
        } else if (command == "south" && maze[currentRoom.first][currentRoom.second].exits[2] == true) {
            ++currentRoom.second;
            printf("\033c");
            move(maze, currentRoom);
        } else if (command == "east" && maze[currentRoom.first][currentRoom.second].exits[3] == true) {
            ++currentRoom.first;
            printf("\033c");
            move(maze, currentRoom);
        } else if (command == "west" && maze[currentRoom.first][currentRoom.second].exits[4] == true) {
            --currentRoom.first;
            printf("\033c");
            move(maze, currentRoom);
        } else if (command == "take") {
            take(maze, currentRoom, &player);
            playing = checkWin(&player);
        } else if (command == "drop") {
            drop(maze, currentRoom, &player);
        } else if (command == "inventory") {
            player.readInv();
        } else if (command == "check") {
            printf("\033c");
            move(maze, currentRoom);
        } else if (command == "quit") {
            playing = false;
        } else {
            printf("\033c");
            cout << "\nnot a valid command!" << endl;
            move(maze, currentRoom);
        }
    }
}
