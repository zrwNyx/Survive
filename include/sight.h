#ifndef SIGHT_H
#define SIGHT_H
#include <SFML/Graphics.hpp>


class sight
{
    public:
        sight();
        virtual ~sight();
        void on(sf::Vector2f x);
        void of();
        void init();
        int b=0;
        sf::RectangleShape line;
    private:
};

#endif // SIGHT_H
