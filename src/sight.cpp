#include "sight.h"

sight::sight()
{
    line.setFillColor(sf::Color::Red);
}

sight::~sight()
{
    //dtor
}

void sight::on(sf::Vector2f x)
{
    line.setPosition(x);
}

void sight::of()
{
    line.setPosition(-20.f,-20.f);
}

void sight::init()
{
     line.setSize(sf::Vector2f(1200.f,2.f));
}
