#ifndef ZCLASS_H
#define ZCLASS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

class zclass
{
    public:
        sf::Sprite zx;
        sf::Texture *texture;
        zclass(sf::Texture *texture, float x,float y);
        void settype(int type);
        void gerak(float speed);
        int HP;
        void reset(int type,float x, float y);
    private:
};

#endif // ZCLASS_H
