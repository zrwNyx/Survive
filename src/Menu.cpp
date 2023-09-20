#include "Menu.h"

Menu::Menu(float x,float y)
{


    MFont.loadFromFile("SaucerBB.ttf");
    MText[0].setFont(MFont);
    MText[0].setString("Play");
    MText[0].setPosition(sf::Vector2f(x ,y-110));

    MText[1].setFont(MFont);
    MText[1].setString("Exit");
    MText[1].setPosition(sf::Vector2f(x , y));

    MText[2].setFont(MFont);
    MText[2].setString("HOW TO PLAY");
    MText[2].setPosition(sf::Vector2f(x, y-220));

    MText[3].setFont(MFont);
    MText[3].setString(" 1. Left Click to shoot \n 2.Press s and right click to call artillery support \n 3.Press A to call airsupport (if available) \n 4.Some type of zombie will give u power up \n 5. goodluck ^-^");
    MText[3].setPosition(sf::Vector2f(-1000,-1000));
    MText[3].setColor(sf::Color::Cyan);


    cursorText.loadFromFile("gfx/cursor.png");
    cursor.setTexture(cursorText);
    cursor.setOrigin(0,0);
    cursor.setPosition(sf::Mouse::getPosition().x-375,sf::Mouse::getPosition().y-170);
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
   for (int MDRAW = 0; MDRAW < MAX ; MDRAW++)
   {
       window.draw(MText[MDRAW]);
   }
    window.draw(cursor);
}

void Menu::atas()
{
    if (cursor.getGlobalBounds().intersects(MText[0].getGlobalBounds()))
    {
        MText[0].setColor(sf::Color::Red);
        yx=1;
    }
    else
    {
         MText[0].setColor(sf::Color::Blue);
         yx=0;
    }
}

void Menu::bawah()
{
     if (cursor.getGlobalBounds().intersects(MText[1].getGlobalBounds()))
    {
        MText[1].setColor(sf::Color::Red);
        yx=2;
    }
    else
    {
         MText[1].setColor(sf::Color::Blue);
    }
}

void Menu::howtoplay()
{
        if(cursor.getGlobalBounds().intersects(MText[2].getGlobalBounds()))
        {
            MText[2].setColor(sf::Color::Red);
            yx=3;
        }
        else
        {
            MText[2].setColor(sf::Color::Blue);
        }
        if(yx==3)
        {
            MText[3].setPosition(172,150);
        }
}

int Menu::getInt()
{
    return  yx;
}
