#include "zclass.h"

zclass::zclass(sf::Texture *texture,float x,float y)
{
    srand(time(0));
    zx.setTexture(*texture);
    zx.setPosition(x,y);
}
void zclass::settype(int type)
{
    if (type==2 )
    {
        zx.setScale(0.8f,0.8f);
        HP=10;
    }
    if (type==1 )
    {
        zx.setScale(2.f,2.f);
        HP=5;
    }
     if(type==3)
    {
        zx.setScale(0.4f,0.4f);
        HP=6;
    }
}

void zclass::gerak(float speed)
{
    zx.move(-speed,0.0f);
}

void zclass::reset(int type,float x, float y)
{
    if (type==2 )
    {
        zx.setPosition(x,y);
        HP=10;
    }
    if (type==1 )
    {
        zx.setPosition(x,y);
        HP=5;
    }
     if(type==3)
    {
        zx.setPosition(x,y);
        HP=6;
    }
}
