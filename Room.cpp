#include "Room.h"
#include <SFML/Graphics.hpp>

Room::Room(sf::RenderWindow &window): m_window(window){
    enemy.setRadius(30.f);
    enemy.setFillColor(sf::Color::Red);
    
    stone.setSize(sf::Vector2f(60, 60));
    stone.setFillColor(sf::Color(74, 88, 101));
    
    boss.setRadius(50.f);
    boss.setFillColor(sf::Color(168, 3, 29));
}

void Room::enemyGenerator(){
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 19; x++) {
            if (enemyRoom[0][y][x]==5) {
                enemy.setPosition(x*50+90+enemy.getRadius(), y*50+90+enemy.getRadius());
                m_window.draw(enemy);
            }
        }
    }
}
    
void Room::stoneGenerator(){
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 19; x++) {
            if (normalRoom[0][y][x]==1) {
                stone.setPosition(x*50+60+stone.getSize().x, y*50+35+stone.getSize().x);
                m_window.draw(stone);
            }
        }
    }
}

void Room::bossGenerator(){
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 19; x++) {
            if (bossRoom[y][x]==9) {
                boss.setPosition(x*50+60+boss.getRadius(), y*50+35+boss.getRadius());
                m_window.draw(stone);
            }
        }
    }
}
                        
