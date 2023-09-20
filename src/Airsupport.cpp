#include "Airsupport.h"
#include <iostream>

Airsupport::Airsupport(float x, float y)
{
    AirText.loadFromFile("gfx/pesawatx.png");
    planex[0].setTexture(AirText);
    planex[0].setPosition(sf::Vector2f(-x,40.f));
    planex[1].setTexture(AirText);
    planex[1].setPosition(sf::Vector2f(-x,320.f));
    planex[2].setTexture(AirText);
    planex[2].setPosition(sf::Vector2f(-x,600.f));
    planex[3].setTexture(AirText);
    planex[3].setPosition(sf::Vector2f(-x-130,180.f));
    planex[4].setTexture(AirText);
    planex[4].setPosition(sf::Vector2f(-x-130,460.f));
    for(int i=0;i<5;i++){
        planex[i].setScale(0.25f,0.25f);
    }

}

Airsupport::~Airsupport()
{
}

void Airsupport::draw(sf::RenderWindow &window)
{
    for(int i=0;i<5;i++){
        window.draw(planex[i]);
    }

}
void Airsupport::gerak(float speed)
{
    for(int i=0;i<5;i++){
    planex[i].move(speed,0.0f);
    }
}
