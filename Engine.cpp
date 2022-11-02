#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Engine.h"
#include "MapGenerator.h"
#include "Player.h"
#include "Bullet.h"
#include "Door.h"
#include "Room.h"

using namespace sf;
using namespace std;

Engine::Engine(){}

void Engine::play(){
    RenderWindow window(VideoMode(windowWidth, windowHeight), "TBoI");
    window.setFramerateLimit(60);
    roomBgT.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/LastProject/LastProject/room.png");
    roomBgS.setTexture(roomBgT);
    
    Generator mapGenerator;
    mapGenerator.generateFloor();
    mapGenerator.view();
    
    Player playerHero;
    tearBullet tear;
    Door roomDoor(mapGenerator, window);
    Room roomFloor(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        playerHero.playerMove();
        playerHero.playerShoot();
        
        //LEWA SCIANA
        if (playerHero.bodyS.getPosition().x<90) {
            playerHero.headS.setPosition(77, playerHero.headS.getPosition().y);
            playerHero.bodyS.setPosition(playerHero.bodyS.getPosition().x+6, playerHero.bodyS.getPosition().y);
        }
        
        //PRAWA SCIANA
        if (playerHero.bodyS.getPosition().x>windowWidth-155) {
            playerHero.headS.setPosition(windowWidth-171, playerHero.headS.getPosition().y);
            playerHero.bodyS.setPosition(playerHero.bodyS.getPosition().x-6, playerHero.bodyS.getPosition().y);
        }
        
        //GORNA SCIANA
        if (playerHero.bodyS.getPosition().y<90) {
            playerHero.headS.setPosition(playerHero.headS.getPosition().x, 23);
            playerHero.bodyS.setPosition(playerHero.bodyS.getPosition().x, playerHero.bodyS.getPosition().y+6);
        }
        
        //DOLNA SCIANA
        if (playerHero.bodyS.getPosition().y>windowHeight-147) {
            playerHero.headS.setPosition(playerHero.headS.getPosition().x, windowHeight-220);
            playerHero.bodyS.setPosition(playerHero.bodyS.getPosition().x, playerHero.bodyS.getPosition().y-6);
        }
        

        //PRZECHODZENIE DO POKOJU GORA
        if (playerHero.bodyS.getGlobalBounds().intersects(roomDoor.topDoor.getGlobalBounds()) && !mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
            
            playerHero.y--;
            playerHero.headS.setPosition(windowWidth/2-45, windowHeight-250);
            playerHero.bullets.clear();
        }
        //PRZECHODZENIE DO POKOJU PRAWO
        if (playerHero.bodyS.getGlobalBounds().intersects(roomDoor.rightDoor.getGlobalBounds()) && !mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
            playerHero.x++;
            playerHero.headS.setPosition(130, windowHeight/2-80);
            playerHero.bullets.clear();
        }
        //PRZECHODZENIE DO POKOJU DOL
        if (playerHero.bodyS.getGlobalBounds().intersects(roomDoor.bottomDoor.getGlobalBounds()) && !mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
            playerHero.y++;
            playerHero.headS.setPosition(windowWidth/2-45, 70);
            playerHero.bullets.clear();
        }
        //PRZECHODZENIE DO POKOJU LEWO
        if (playerHero.bodyS.getGlobalBounds().intersects(roomDoor.leftDoor.getGlobalBounds()) && !mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
            playerHero.x--;
            playerHero.headS.setPosition(windowWidth-230, windowHeight/2-80);
            playerHero.bullets.clear();
        }
        
        if (playerHero.bodyS.getGlobalBounds().intersects(roomFloor.stone.getGlobalBounds())) {
            cout<<"siema"<<endl;
        }
        
        
        for (int i = 0; i<playerHero.bullets.size(); i++) {
            if (playerHero.playerShootDirection.x + playerHero.playerShootDirection.y == 0 || playerHero.playerShootDirection.x + playerHero.playerShootDirection.y == 2 || playerHero.playerShootDirection.x + playerHero.playerShootDirection.y == -2) {
                playerHero.bullets[i].bullet.move(playerHero.bullets[i].currVelocity*tear.bulletSpeed/float(sqrt(2)));
            }
            else {
                playerHero.bullets[i].bullet.move(playerHero.bullets[i].currVelocity*tear.bulletSpeed);
            }
            
            if (playerHero.bullets[i].bullet.getPosition().x > (playerHero.headS.getPosition().x + playerHero.playerRange*200+50)){
                playerHero.bullets.erase(playerHero.bullets.begin()+i);
            }
            if (playerHero.bullets[i].bullet.getPosition().x < (playerHero.headS.getPosition().x - playerHero.playerRange*200)) {
                playerHero.bullets.erase(playerHero.bullets.begin()+i);
            }
            if (playerHero.bullets[i].bullet.getPosition().y > (playerHero.headS.getPosition().y + playerHero.playerRange*200+50)) {
                playerHero.bullets.erase(playerHero.bullets.begin()+i);
            }
            if (playerHero.bullets[i].bullet.getPosition().y < (playerHero.headS.getPosition().y - playerHero.playerRange*200)) {
                playerHero.bullets.erase(playerHero.bullets.begin()+i);
            }
                    
            if (playerHero.bullets[i].bullet.getPosition().x<90 || playerHero.bullets[i].bullet.getPosition().x>windowWidth-110 || playerHero.bullets[i].bullet.getPosition().y<90 || playerHero.bullets[i].bullet.getPosition().y>windowHeight-110) {
                playerHero.bullets.erase(playerHero.bullets.begin()+i);
            }
        }
        time = clock.getElapsedTime();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
                if (time.asMilliseconds()>=300) {
                    mapGenerator.room[playerHero.x][playerHero.y].hasEnemys = true;
                    clock.restart();
                }
            }
            else{
                if (time.asMilliseconds()>=300) {
                    mapGenerator.room[playerHero.x][playerHero.y].hasEnemys = false;
                    clock.restart();
                }
            }
        }
        
        
        
        window.clear(Color(219, 197, 148));
        window.draw(roomBgS);
        window.draw(roomDoor.topDoor);
        window.draw(roomDoor.rightDoor);
        window.draw(roomDoor.bottomDoor);
        window.draw(roomDoor.leftDoor);
        roomDoor.generateDoors(playerHero.x, playerHero.y);
        //window.draw(roomDoorS);
        //roomDoor.drawDoors(window);
        if (!mapGenerator.room[playerHero.x][playerHero.y].visited) {
            if (mapGenerator.room[playerHero.x][playerHero.y].hasEnemys) {
                //roomFloor.enemyGenerator();
            }
            if (mapGenerator.room[playerHero.x][playerHero.y].boss) {
                //roomFloor.bossGenerator();
            }
            
            //roomFloor.stoneGenerator();
        }
        //roomFloor.enemyGenerator();
        window.draw(playerHero.bodyS);
        for (int i=0; i<playerHero.bullets.size(); i++) {
            window.draw(playerHero.bullets[i].bullet);
            cout<<playerHero.bullets.size()<<endl;
        }
        window.draw(playerHero.headS);

        window.display();
    }
}
