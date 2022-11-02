#ifndef Enemy_h
#define Enemy_h
#include <SFML/Graphics.hpp>

class Enemy{
private:
    sf::RenderWindow &m_window;
public:
    Enemy(sf::RenderWindow &window);
    void move();
    void shoot();
};

#endif
