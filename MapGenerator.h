#ifndef MapGenerator_h
#define MapGenerator_h

const int floorWidth = 9;
const int floorHeight = 9;

struct floorGenerator{
    bool exist = false;
    bool start = false;
    bool treasure = false;
    bool boss = false;
    bool player = false;
    bool visited = false;
    bool hasEnemys = false;
//    bool topDoor = false;
//    bool rightDoor = false;
//    bool bottomDoor = false;
//    bool leftDoor = false;
};

class Generator{
public:
    Generator();
    floorGenerator room[floorWidth+5][floorHeight+5];

    const int roomCount = 6;
    bool hasStart = true;
    bool hasBoss = false;
    void generateFloor();
    void roomGenerator();
    void bossGenerator();
    void treasureGenerator();
    void roomDescribe(int x, int y);
    bool hasTopDoor(int x, int y);
    bool hasRightDoor(int x, int y);
    bool hasBottomDoor(int x, int y);
    bool hasLeftDoor(int x, int y);
    void moveRoom();
    void view();
};

#endif
