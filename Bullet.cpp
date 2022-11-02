#include "Player.h"
#include <iostream>

Player playerHero_Bullet;

tearBullet::tearBullet(){
    bullet.setRadius(bulletSize);
    bullet.setPosition(playerHero_Bullet.bodyS.getPosition().x, playerHero_Bullet.bodyS.getPosition().y);
    bullet.setFillColor(sf::Color(105, 188, 252, 200));
    bullet.setOutlineThickness(bulletSize/3);
    bullet.setOutlineColor(sf::Color(3, 79, 138));
}

