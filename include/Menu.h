#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#define MAX 4

class Menu
{
    public:
        Menu(float x, float y);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void atas();
        void bawah();
        void howtoplay();
        int yx;
        int getInt();


    private:
        sf::Font MFont;
        sf::Text MText[MAX];
        sf::Texture cursorText;
        sf::Sprite cursor;
};

#endif // MENU_H

