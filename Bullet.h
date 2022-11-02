#ifndef Bullet_h
#define Bullet_h
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"



class tearBullet{
public:
    tearBullet();
    sf::CircleShape bullet;
    sf::Vector2f currVelocity;
    float bulletSize = 10.f;
    float bulletSpeed = 15.f;
    void move();
};

#endif
