#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player{
public:
    Player();
    float bodySize = 40.f;
    sf::CircleShape playerBody;
    void playerMove();
    void playerShoot();
    sf::Vector2f playerWalkDirection;
    float playerSpeed = 1.2f;
    float shootingSpeed = 1.f;
    float playerRange = 1.5f;
    sf::Vector2f playerAcceleration;
    sf::Vector2f playerShootDirection;
    int x = 4;
    int y = 4;
    std::vector<tearBullet> bullets;
    
    bool rightPress = false;
    bool leftPress = false;
    bool downPress = false;
    bool upPress = false;
    
    sf::Clock clockShoot, clockWalk;
    sf::Time timeShoot, timeWalk;
    
    sf::Texture headT, bodyT;
    sf::Sprite headS, bodyS;
    
    sf::IntRect headRect, bodyRect;
    
};

#endif
