#ifndef ARTILLERY_H
#define ARTILLERY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class artillery
{
    public:
        artillery();
        sf::RectangleShape coord;
        sf::RectangleShape artyx;
        sf::Clock art;
        sf::SoundBuffer boom;
        sf::Sound artyboom;
        sf::SoundBuffer impact;
        sf::Sound duar;
        void init();
        void draw(sf::RenderWindow &window);
        int artyg=0,artyb,artyav=4;
    private:
};

#endif // ARTILLERY_H

