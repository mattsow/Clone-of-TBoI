#include "MapGenerator.h"
#include "Door.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Generator::view(){
    for (int y = 0; y<floorHeight; y++) {
        for (int x = 0; x<floorWidth; x++) {
            if (room[x][y].start) {
                cout<<"[S]";
            }
            else if (room[x][y].boss) {
               cout<<"[O]";
            }
            else if (room[x][y].treasure){
               cout<<"[T]";
            }
            else if (room[x][y].exist) {
               cout<<"[ ]";
            }
            else{
               cout<<"   ";
            }
        }
        cout<<endl;
    }
}

Generator::Generator(){}

void Generator::generateFloor(){
    roomGenerator();
    bossGenerator();
    treasureGenerator();
}

void Generator::roomGenerator(){
    srand(unsigned(time(NULL)));
    room[4][4].exist = true;
    room[4][4].start = true;
    int i = 0;
    while (i < roomCount) {
        int x = rand() % (floorWidth-1) + 1;
        int y = rand() % (floorHeight-1) + 1;
        
        if (room[x-1][y].exist) {
            room[x][y].exist = true;
            if (!room[x][y].start) {
                int true_false = rand() % 2;
                room[x][y].hasEnemys = true_false;
            }
            i++;
        }
        else if(room[x+1][y].exist) {
            room[x][y].exist = true;
            if (!room[x][y].start) {
                int true_false = rand() % 2;
                room[x][y].hasEnemys = true_false;
            }
            i++;
        }
        else if(room[x][y-1].exist) {
            room[x][y].exist = true;
            if (!room[x][y].start) {
                int true_false = rand() % 2;
                room[x][y].hasEnemys = true_false;
            }
            i++;
        }
        else if(room[x][y+1].exist) {
           room[x][y].exist = true;
            if (!room[x][y].start) {
                int true_false = rand() % 2;
                room[x][y].hasEnemys = true_false;
            }
           i++;
        }
    }
}

void Generator::bossGenerator(){
    while (!hasBoss) {
        int x = rand() % (floorWidth-1) + 1;
        int y = rand() % (floorHeight-1) + 1;
        
        if (!room[x][y].start && !room[x][y-1].start && !room[x+1][y].start && !room[x][y+1].start && !room[x-1][y].start) {
            if (room[x][y-1].exist && !room[x+1][y].exist && !room[x][y+1].exist && !room[x-1][y].exist ) {
                room[x][y].boss = true;
                room[x][y].exist = true;
                hasBoss = true;
            }
            else if(!room[x][y-1].exist && room[x+1][y].exist && !room[x][y+1].exist && !room[x-1][y].exist) {
                room[x][y].boss = true;
                room[x][y].exist = true;
                hasBoss = true;
            }
            else if(!room[x][y-1].exist && !room[x+1][y].exist && room[x][y+1].exist && !room[x-1][y].exist) {
                room[x][y].boss = true;
                room[x][y].exist = true;
                hasBoss = true;
            }
            else if(!room[x][y-1].exist && !room[x+1][y].exist && !room[x][y+1].exist && room[x-1][y].exist) {
                room[x][y].boss = true;
                room[x][y].exist = true;
                hasBoss = true;
            }
        }
    }
}

void Generator::treasureGenerator(){
    int i = 0;
    while (i < 1) {
        int x = rand() % (floorWidth-1) + 1;
        int y = rand() % (floorHeight-1) + 1;
        
        if (!room[x][y].start && !room[x][y].boss && !room[x][y-1].boss && !room[x+1][y].boss && !room[x][y+1].boss && !room[x-1][y].boss) {
            if (!room[x][y].treasure && !room[x][y-1].treasure && !room[x+1][y].treasure && !room[x][y+1].treasure && !room[x-1][y].treasure) {
                if (room[x][y-1].exist && !room[x+1][y].exist && !room[x][y+1].exist && !room[x-1][y].exist) {
                    room[x][y].treasure = true;
                    room[x][y].exist = true;
                    i++;
                }
                else if(!room[x][y-1].exist && room[x+1][y].exist && !room[x][y+1].exist && !room[x-1][y].exist) {
                    room[x][y].treasure = true;
                    room[x][y].exist = true;
                    i++;
                }
                else if(!room[x][y-1].exist && !room[x+1][y].exist && room[x][y+1].exist && !room[x-1][y].exist) {
                    room[x][y].treasure = true;
                    room[x][y].exist = true;
                    i++;
                }
                else if(!room[x][y-1].exist && !room[x+1][y].exist && !room[x][y+1].exist && room[x-1][y].exist) {
                    room[x][y].treasure = true;
                    room[x][y].exist = true;
                    i++;
                }
            }

        }
    }
}

void Generator::roomDescribe(int x, int y){
    string T,R,B,L;
    if (room[x][y].exist) {
        if (room[x][y-1].exist) {
            T = "T";
        }
        if (room[x+1][y].exist) {
            R = "R";
        }
        if (room[x][y+1].exist) {
            B = "B";
        }
        if (room[x-1][y].exist) {
            L = "L";
        }
        cout<<"["<<T<<R<<B<<L<<"]";
    }
}

bool Generator::hasTopDoor(int x, int y){
    if (room[x][y].exist) {
        if (room[x][y-1].exist) {
            return true;
        }
    }
    return false;
}

bool Generator::hasRightDoor(int x, int y){
    if (room[x][y].exist) {
        if (room[x+1][y].exist) {
            return true;
        }
    }
    return false;
}

bool Generator::hasBottomDoor(int x, int y){
    if (room[x][y].exist) {
        if (room[x][y+1].exist) {
            return true;
        }
    }
    return false;
}

bool Generator::hasLeftDoor(int x, int y){
    if (room[x][y].exist) {
        if (room[x-1][y].exist) {
            return true;
        }
    }
    return false;
}

void Generator::moveRoom(){
    
}
