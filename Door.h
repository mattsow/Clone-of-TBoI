#ifndef Door_h
#define Door_h
#include <SFML/Graphics.hpp>
#include "MapGenerator.h"


class Door{
    Generator &mapGenerator_Door;
private:
    sf::RenderWindow &m_window;
public:
    Door(Generator &mapGenerator_Door, sf::RenderWindow &window);
    void generateDoors(int x, int y);
    sf::RectangleShape topDoor;
    sf::RectangleShape rightDoor;
    sf::RectangleShape bottomDoor;
    sf::RectangleShape leftDoor;
    void drawDoors(sf::RenderWindow &window);
    int doorWidth = 183;
    int doorHeight = 117;
    
    sf::Texture roomDoor;
    sf::Sprite doorT, doorR, doorB, doorL;
};

#endif
