#ifndef AIRSUPPORT_H
#define AIRSUPPORT_H
#include <SFML/Graphics.hpp>


class Airsupport
{
    public:
        Airsupport(float x , float y);
       ~Airsupport();

       void draw(sf::RenderWindow &window);
       void gerak(float speed);

       sf::Sprite planex[5];

    private:
        sf::Texture AirText;
};

#endif // AIRSUPPORT_H
