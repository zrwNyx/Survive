#include "artillery.h"

artillery::artillery()
{
    coord.setPosition(-220,-220);
    coord.setSize(sf::Vector2f(240.f,240.f));;
    coord.setOrigin(coord.getSize().x/2,coord.getSize().y/2);
    boom.loadFromFile("sfx/artyboom.wav");
    artyboom.setBuffer(boom);
    impact.loadFromFile("sfx/duar.wav");
    duar.setBuffer(impact);
}

void artillery::init()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && artyg==0 && artyav > 0)
    {
        artyb=1;
        coord.setFillColor(sf::Color(255,0,0,100));
    }
    if(artyb==1)
    {
        coord.setPosition(sf::Mouse::getPosition().x-375,sf::Mouse::getPosition().y-170);
    }
    if(artyb==1 && sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        coord.setFillColor(sf::Color::White);
        artyg++;
         artyboom.play();
    }
    if(artyg==2){
        artyav--;
        art.restart();
    }
    if(artyg>2)
    {
        artyb=0;
        coord.setFillColor(sf::Color::Transparent);
        if(art.getElapsedTime().asSeconds()>3.5f)
        {
            artyx.setPosition(coord.getPosition().x,coord.getPosition().y);
            artyx.setSize(sf::Vector2f(240.f,240.f));
            artyx.setOrigin(artyx.getSize().x/2,artyx.getSize().y/2);
            artyx.setFillColor(sf::Color::Transparent);
        }
        if(art.getElapsedTime().asSeconds()>9.2f){
            art.restart();
            artyg=0;
            artyx.setPosition(-220,220);
        }
    }
}


void artillery::draw(sf::RenderWindow &window)
{
    window.draw(coord);
    window.draw(artyx);
}
