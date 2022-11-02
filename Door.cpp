#include "Door.h"
#include "Player.h"
#include "Engine.h"
#include "MapGenerator.h"
#include <SFML/Graphics.hpp>

Player playerHero_Door;
Engine game_Door;

Door::Door(Generator &mapGenerator_Door, sf::RenderWindow &window):mapGenerator_Door(mapGenerator_Door), m_window(window){
    
    roomDoor.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/LastProject/LastProject/doors.png");
    
    doorT.setTexture(roomDoor);
    doorR.setTexture(roomDoor);
    doorB.setTexture(roomDoor);
    doorL.setTexture(roomDoor);
    
    //STANDARDOWE DRZWI
    doorT.setTextureRect(sf::IntRect(0, 0, doorWidth, doorHeight));
    doorR.setTextureRect(sf::IntRect(0, 0, doorWidth, doorHeight));
    doorB.setTextureRect(sf::IntRect(0, 0, doorWidth, doorHeight));
    doorL.setTextureRect(sf::IntRect(0, 0, doorWidth, doorHeight));

    doorT.setTextureRect(sf::IntRect(0, 0, 183, 117));
    doorR.setTextureRect(sf::IntRect(0, 0, 183, 117));
    doorB.setTextureRect(sf::IntRect(0, 0, 183, 117));
    doorL.setTextureRect(sf::IntRect(0, 0, 183, 117));
    
    //ROZMIESZCZENIE DRZWI GORNYCH
    doorT.setPosition(game_Door.windowWidth/2-doorWidth/2, doorHeight/10);
    //ROZMIESZCZENIE DRZWI PRAWYCH
    doorL.setPosition(doorHeight/10, game_Door.windowHeight/2+doorWidth/2);
    doorL.setRotation(-90);
    //ROZMIESZCZENIE DRZWI DOLNYCH
    doorB.setPosition(game_Door.windowWidth/2+doorWidth/2, game_Door.windowHeight-doorHeight/10);
    doorB.setRotation(180);
    //ROZMIESZCZENIE DRZWI LEWYCH
    doorR.setPosition(game_Door.windowWidth-doorHeight/10, game_Door.windowHeight/2-doorWidth/2);
    doorR.setRotation(90);
    
    //TELEPORTY DO INNYCH POKOI
    topDoor.setSize(sf::Vector2f(2,2));
    rightDoor.setSize(sf::Vector2f(2,2));
    bottomDoor.setSize(sf::Vector2f(2,2));
    leftDoor.setSize(sf::Vector2f(2,2));
    
    topDoor.setFillColor(sf::Color(0,0,0,0));
    rightDoor.setFillColor(sf::Color(0,0,0,0));
    bottomDoor.setFillColor(sf::Color(0,0,0,0));
    leftDoor.setFillColor(sf::Color(0,0,0,0));
}

void Door::generateDoors(int x, int y){
    
    for (int i = 0; i < 4; i++) {
        if (mapGenerator_Door.hasTopDoor(x, y)) {
            topDoor.setPosition(game_Door.windowWidth/2-topDoor.getSize().x, 110);
            if (mapGenerator_Door.room[x][y-1].boss || mapGenerator_Door.room[x][y].boss) {
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorT.setTextureRect(sf::IntRect(366, 0, 183, 117));
                }
                else{
                    doorT.setTextureRect(sf::IntRect(366, 117, 183, 117));
                }
            }
            else if (mapGenerator_Door.room[x][y-1].treasure || mapGenerator_Door.room[x][y].treasure){
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorT.setTextureRect(sf::IntRect(184, 0, 183, 117));
                }
                else{
                    doorT.setTextureRect(sf::IntRect(184, 117, 183, 117));
                }
            }
            else{
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorT.setTextureRect(sf::IntRect(0, 0, 183, 117));
                }
                else{
                    doorT.setTextureRect(sf::IntRect(0, 117, 183, 117));
                }
            }
            m_window.draw(doorT);
        }
        else{
            topDoor.setPosition(-200, -200);
        }
        if (mapGenerator_Door.hasRightDoor(x, y)) {
            rightDoor.setPosition(game_Door.windowWidth-(110+rightDoor.getSize().x), game_Door.windowHeight/2-rightDoor.getSize().x/2);
            if (mapGenerator_Door.room[x+1][y].boss || mapGenerator_Door.room[x][y].boss) {
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorR.setTextureRect(sf::IntRect(366, 0, 183, 117));
                }
                else{
                    doorR.setTextureRect(sf::IntRect(366, 117, 183, 117));
                }
            }
            else if (mapGenerator_Door.room[x+1][y].treasure || mapGenerator_Door.room[x][y].treasure){
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorR.setTextureRect(sf::IntRect(184, 0, 183, 117));
                }
                else{
                    doorR.setTextureRect(sf::IntRect(184, 117, 183, 117));
                }
            }
            else{
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorR.setTextureRect(sf::IntRect(0, 0, 183, 117));
                }
                else{
                    doorR.setTextureRect(sf::IntRect(0, 117, 183, 117));
                }
            }
            m_window.draw(doorR);
        }
        else{
            rightDoor.setPosition(-200, -200);
        }
        if (mapGenerator_Door.hasBottomDoor(x, y)) {
            bottomDoor.setPosition(game_Door.windowWidth/2-bottomDoor.getSize().x, game_Door.windowHeight-(110+bottomDoor.getSize().x));
            if (mapGenerator_Door.room[x][y+1].boss || mapGenerator_Door.room[x][y].boss) {
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorB.setTextureRect(sf::IntRect(366, 0, 183, 117));
                }
                else{
                    doorB.setTextureRect(sf::IntRect(366, 117, 183, 117));
                }
            }
            else if (mapGenerator_Door.room[x][y+1].treasure || mapGenerator_Door.room[x][y].treasure){
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorB.setTextureRect(sf::IntRect(184, 0, 183, 117));
                }
                else{
                    doorB.setTextureRect(sf::IntRect(184, 117, 183, 117));
                }
            }
            else{
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorB.setTextureRect(sf::IntRect(0, 0, 183, 117));
                }
                else{
                    doorB.setTextureRect(sf::IntRect(0, 117, 183, 117));
                }
            }
            m_window.draw(doorB);
        }
        else{
            bottomDoor.setPosition(-200, -200);
        }
        if (mapGenerator_Door.hasLeftDoor(x, y)) {
            leftDoor.setPosition(110, game_Door.windowHeight/2-leftDoor.getSize().x);
            if (mapGenerator_Door.room[x-1][y].boss || mapGenerator_Door.room[x][y].boss) {
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorL.setTextureRect(sf::IntRect(366, 0, 183, 117));
                }
                else{
                    doorL.setTextureRect(sf::IntRect(366, 117, 183, 117));
                }
            }
            else if (mapGenerator_Door.room[x-1][y].treasure || mapGenerator_Door.room[x][y].treasure){
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorL.setTextureRect(sf::IntRect(184, 0, 183, 117));
                }
                else{
                    doorL.setTextureRect(sf::IntRect(184, 117, 183, 117));
                }
            }
            else{
                if (!mapGenerator_Door.room[x][y].hasEnemys) {
                    doorL.setTextureRect(sf::IntRect(0, 0, 183, 117));
                }
                else{
                    doorL.setTextureRect(sf::IntRect(0, 117, 183, 117));
                }
            }
            m_window.draw(doorL);
        }
        else{
            leftDoor.setPosition(-200, -200);
        }
    }
}

void Door::drawDoors(sf::RenderWindow &window){
    
    
    
//    doorStandard.setTexture(roomDoor);
    //STANDARDOWE DRZWI
//    doorT.setTextureRect(sf::IntRect(0, 0, 183, 117));
//    doorR.setTextureRect(sf::IntRect(0, 0, 183, 117));
//    doorB.setTextureRect(sf::IntRect(0, 0, 183, 117));
//    doorL.setTextureRect(sf::IntRect(0, 0, 183, 117));
//    doorTreasure.setTexture(roomDoor);
//    doorTreasure.setTextureRect(sf::IntRect(183, 0, 183, 117));
//    doorBoss.setTexture(roomDoor);
//    doorT.setTextureRect(sf::IntRect(366, 0, 183, 117));
//
//    m_window.draw(doorT);
    //doorStandard.setPosition(300, 300);
//    doorT.setPosition(game_Door.windowWidth/2-93, 13);
//
//    doorR.setPosition(13, game_Door.windowHeight/2+93);
//    doorR.setRotation(-90);
//
//    doorB.setPosition(game_Door.windowWidth/2+93, game_Door.windowHeight-13);
//    doorB.setRotation(180);
//
//    doorL.setPosition(game_Door.windowWidth-13, game_Door.windowHeight/2-93);
//    doorL.setRotation(90);
    
    //doorB.setTextureRect(sf::IntRect(117, 0, 183, 117));
    
    doorT.setTextureRect(sf::IntRect(0, 117, 183, 117));
    
    m_window.draw(doorT);
    
    
    //m_window.draw(doorR);
    //m_window.draw(doorB);
    //m_window.draw(doorL);
}

