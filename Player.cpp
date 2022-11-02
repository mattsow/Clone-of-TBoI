#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "Player.h"
#include "Engine.h"
#include "Bullet.h"

Engine game_Player;


Player::Player(){

    
    headS.setPosition( game_Player.windowWidth/2-50,  game_Player.windowHeight/2-80);
    
    headT.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/LastProject/LastProject/head.png");
    bodyT.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/LastProject/LastProject/body.png");
    
    headS.setTexture(headT);
    bodyS.setTexture(bodyT);
    
    sf::IntRect headRect(0, 0, 28, 25);
    sf::IntRect bodyRect(0, 0, 18, 14);
    
    headS.setTextureRect(headRect);
    headS.scale(3.5, 3.5);
    
    bodyS.setTextureRect(bodyRect);
    bodyS.setScale(3.5, 3.5);
}

void Player::playerMove(){
    timeShoot = clockShoot.getElapsedTime();
    timeWalk =clockWalk.getElapsedTime();
    
    playerWalkDirection.x = 0.f;
    playerWalkDirection.y = 0.f;
    

    
    //CHODZENIE W LEWO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        playerWalkDirection.x = -5.f;
//        headS.setTextureRect(sf::IntRect(28, 0, 28, 25));
        playerAcceleration.x -= 0.1;
    }
    
    
    //CHODZENIE W PRAWO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerWalkDirection.x = 5.f;
//        headS.setTextureRect(sf::IntRect(56, 0, 28, 25));
        playerAcceleration.x += 0.1;
    }
    
    //CHODZENIE W GORE
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        playerWalkDirection.y = -5.f;
//        headS.setTextureRect(sf::IntRect(84, 0, 28, 25));
        playerAcceleration.y -= 0.1;
    }
    
    //CHODZENIE W DOL
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerWalkDirection.y = 5.f;
//        headS.setTextureRect(sf::IntRect(0, 0, 28, 25));
        playerAcceleration.y += 0.1;
    }
    if (playerWalkDirection.x + playerWalkDirection.y == 0 || playerWalkDirection.x + playerWalkDirection.y == 10 || playerWalkDirection.x + playerWalkDirection.y == -10) {
        headS.move((playerWalkDirection*(playerSpeed/float(sqrt(2)))));
    }
    else {
    headS.move(playerWalkDirection*playerSpeed);
    }
    bodyS.setPosition(headS.getPosition().x+15, headS.getPosition().y+70);
}



void Player::playerShoot(){
    timeShoot = clockShoot.getElapsedTime();
    timeWalk = clockWalk.getElapsedTime();
    
    tearBullet bullet_Player;

    playerShootDirection.x = 0;
    playerShootDirection.y = 0;
    
    //STRZELANIE W LEWO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        playerShootDirection.x = -1;
        playerShootDirection.y = 0;
        if(timeWalk.asMilliseconds()>=150){
            headS.setTextureRect(sf::IntRect(28, 0, 28, 25));
            clockWalk.restart();
        }
        bullet_Player.currVelocity=playerShootDirection;
        bullet_Player.bullet.setPosition(headS.getPosition().x+45-bullet_Player.bulletSize, headS.getPosition().y+45-bullet_Player.bulletSize);
        if (timeShoot.asMilliseconds()>=500/shootingSpeed) {
            headS.setTextureRect(sf::IntRect(28, 25, 28, 25));
            bullets.push_back(bullet_Player);
            clockShoot.restart();
        }
    }
    
    //STRZELANIE W PRAWO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        playerShootDirection.x = 1;
        playerShootDirection.y = 0;
        if(timeWalk.asMilliseconds()>=150){
            headS.setTextureRect(sf::IntRect(56, 0, 28, 25));
            clockWalk.restart();
        }
        bullet_Player.currVelocity=playerShootDirection;
        bullet_Player.bullet.setPosition(headS.getPosition().x+45-bullet_Player.bulletSize, headS.getPosition().y+45-bullet_Player.bulletSize);

        if (timeShoot.asMilliseconds()>=500/shootingSpeed) {
            headS.setTextureRect(sf::IntRect(56, 25, 28, 25));
            bullets.push_back(bullet_Player);
            clockShoot.restart();

        }
    }
    
    //STRZELANIE W DOL
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        playerShootDirection.x = 0;
        playerShootDirection.y = 1;
        if(timeWalk.asMilliseconds()>=150){
            headS.setTextureRect(sf::IntRect(0, 0, 28, 25));
            clockWalk.restart();
        }
        bullet_Player.currVelocity=playerShootDirection;
        bullet_Player.bullet.setPosition(headS.getPosition().x+45-bullet_Player.bulletSize, headS.getPosition().y+45-bullet_Player.bulletSize);
        if (timeShoot.asMilliseconds()>=500/shootingSpeed) {
            headS.setTextureRect(sf::IntRect(0, 25, 28, 25));
            bullets.push_back(bullet_Player);
            clockShoot.restart();
        }
    }
    
    //STRZELANIE W GORE
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        playerShootDirection.x = 0;
        playerShootDirection.y = -1;
        if(timeWalk.asMilliseconds()>=150){
            headS.setTextureRect(sf::IntRect(84, 0, 28, 25));
            clockWalk.restart();
        }
        bullet_Player.currVelocity=playerShootDirection;
        bullet_Player.bullet.setPosition(headS.getPosition().x+45-bullet_Player.bulletSize, headS.getPosition().y+45-bullet_Player.bulletSize);
        if (timeShoot.asMilliseconds()>=500/shootingSpeed) {
            headS.setTextureRect(sf::IntRect(84, 25, 28, 25));
            bullets.push_back(bullet_Player);
            clockShoot.restart();
        }
    }
    
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !sf::Keyboard::isKeyPressed(sf::Keyboard::L) && !sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (timeShoot.asMilliseconds()>=100) {
            headS.setTextureRect(sf::IntRect(0, 0, 28, 25));
            clockShoot.restart();
        }
    }
    
}
