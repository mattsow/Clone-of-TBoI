#ifndef Engine_h
#define Engine_h

class Engine{
public:
    Engine();
    const int windowWidth = 1200;
    const int windowHeight = 800;
    void play();
    
    sf::Texture roomBgT;
    sf::Sprite roomBgS;
    
    sf::Clock clock;
    sf::Time time;
};
#endif
