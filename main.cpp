#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Menu.h"
#include "Airsupport.h"
#include "zclass.h"
#include "sight.h"
#include "artillery.h"

int main()

{
    start:
    srand(time(0));
    int i,zrand,j;
    int adraw;
    int xbar,ons;
    int ax=0;int ay=0;float aj=0;//aj untuk laju spawn bom, ax dan ay untuk animasi bom
    int menuavailable = 1;//untuk menu
    int on=0;//untuk laser
    int g=0;//untuk gerak pesawat bantuan
    int helpx=0;//untuk mendeteksi apa bila HP < 90000
    int b=0;//
    int p=0;
    int fly=0;
    int gameover=0;
    int Timercount =0;
    float rx=0;
    int zombspawn1=0;
    float spwnr=120;//spawn zombie
    int pos=0;
    int f=-30;//spawn peluru
    float ammo=0;
    int ammocount=30;
    int spwnrminus=1;
    int HP=100000;//HP
    sf::Vector2f MidP;
    xbar=1100;
    int play=0;
// main window---------------------------------------------------------------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(1200,800), "s");
    window.setMouseCursorVisible(false);
    window.setMouseCursorGrabbed(true);
    window.setFramerateLimit(100);
//FONT---
    sf::Font scoreFONT;
    scoreFONT.loadFromFile("ARCADECLASSIC.ttf");
    sf::Font LFONT;
    LFONT.loadFromFile("DoubleFeature.ttf");
    sf::Font font;
    font.loadFromFile("arial.ttf");
//MainMenuBg----------------------------------------------------------------------------------------------------------
    sf::Texture Menubg;
    sf::Sprite MainMenuBackground;
    MainMenuBackground.setPosition(0.0f,0.0f);
    Menubg.loadFromFile("gfx/Mbackground.png");
    MainMenuBackground.setTexture(Menubg);
//ReloadingStuff----
    sf::Text Reloading;
    Reloading.setFont(font);
    Reloading.setScale(0.5f,0.5f);
    Reloading.setString("Reloading...");
    sf::SoundBuffer RLOAD;
    RLOAD.loadFromFile("sfx/Reload.wav");
    sf::Sound Reload;
    Reload.setBuffer(RLOAD);
    sf::Text ammoleft;
    ammoleft.setFont(scoreFONT);
    ammoleft.setPosition(sf::Vector2f(350.f,765.f));
    ammoleft.setScale(sf::Vector2f(0.8f,0.8f));
    sf::RectangleShape RBAR;
    sf::SoundBuffer dryfire;
    dryfire.loadFromFile("sfx/dryfire_rifle.wav");
    sf::Sound ammoempty;
    ammoempty.setBuffer(dryfire);
    Reload.setVolume(40.f);
    ammoempty.setVolume(20.f);
//clock---------------------------------------------------------------------------------------------------------------
    sf::Time Time;
    sf::Clock Clock;
    sf::Clock plz;
    sf::Clock tlg;
    sf::Clock lsr;
    sf::Clock Bombing;
//sounds---------------------------------------------------------------------------------------------------------------
    sf::SoundBuffer AK47Sound;
    AK47Sound.loadFromFile("sfx/ak47.wav");
    sf::Sound ak47;
    ak47.setBuffer(AK47Sound);
    ak47.setVolume(50.f);
    sf::SoundBuffer Zombieded;
    Zombieded.loadFromFile("sfx/zm_die.wav");
    sf::Sound Zdied;
    Zdied.setBuffer(Zombieded);
    Zdied.setVolume(40.f);
    sf::SoundBuffer air;
    air.loadFromFile("sfx/AIRSUPPORT.wav");
    sf::Sound airsup;
    airsup.setBuffer(air);
    sf::SoundBuffer bomberav;
    bomberav.loadFromFile("sfx/standby.wav");
    sf::Sound standby;
    standby.setBuffer(bomberav);
    sf::SoundBuffer gunner1;
    gunner1.loadFromFile("sfx/GUNNER.wav");
    sf::Sound gunner;
    gunner.setBuffer(gunner1);
    sf::SoundBuffer bomberdeploy;
    bomberdeploy.loadFromFile("sfx/Bomber.wav");
    sf::Sound Bomber;
    Bomber.setBuffer(bomberdeploy);
    Bomber.setVolume(23.f);
    sf::SoundBuffer zhurt;
    zhurt.loadFromFile("sfx/z2_hurt.wav");
    sf::Sound z2hurt;
    z2hurt.setBuffer(zhurt);
    sf::SoundBuffer zdead;
    zdead.loadFromFile("sfx/z2_death.wav");
    sf::Sound z2dead;
    z2dead.setBuffer(zdead);
//UI-------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape UIBAR(sf::Vector2f(1200,40));
    UIBAR.setPosition(0,760);
    UIBAR.setFillColor(sf::Color::Blue);

//background---------------------------------------------------------------------------------------------------------
    sf::Texture Background;
    sf::RectangleShape HealthBar(sf::Vector2f(xbar,30));
    HealthBar.setPosition(60,10);
    Background.loadFromFile("gfx/background.png");
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(Background);
    spriteBackground.setPosition(0,0);
//Lose------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape LOSEBAR;
    LOSEBAR.setSize(sf::Vector2f(1200.f,800.f));
    LOSEBAR.setFillColor(sf::Color::Black);
    sf::Text LOSETEXT;
    sf::Text LOSESCORE;
    LOSESCORE.setFont(LFONT);
    LOSESCORE.setColor(sf::Color::Red);
    LOSESCORE.setCharacterSize(40.f);
    LOSESCORE.setPosition(300,320);
    LOSETEXT.setFont(LFONT);
    LOSETEXT.setColor(sf::Color::Red);
    LOSETEXT.setCharacterSize(40.f);
    LOSETEXT.setPosition(300,320);
//SCORE--------------------------------------------------------------------------------------------------
    sf::Text Score;
    Score.setFont(scoreFONT);
    Score.setColor(sf::Color::White);
    Score.setPosition(sf::Vector2f(10.f,765.f));
    Score.setScale(sf::Vector2f(0.8f,0.8f));
//Timer--------------------------------------------------------------------------------------------------------
    sf::Text Waktu;
    Waktu.setFont(scoreFONT);
    Waktu.setFillColor(sf::Color::White);
    Waktu.setStyle(sf::Text::Regular);
    Waktu.setCharacterSize(25);
    Waktu.setPosition(sf::Vector2f(180.f,765.f));
//ARTILLERYUI
    sf::Text artytext;
    artytext.setFont(scoreFONT);
    artytext.setFillColor(sf::Color::White);
    artytext.setCharacterSize(25);
    artytext.setPosition(sf::Vector2f(540.f,765.f));

//TEXT---------------------------------------------------------------------------------------------------------
    sf::Text text;
    text.setFont(font);
    text.setString("HP");
    text.setColor(sf::Color::Red);
    text.setCharacterSize(20.f);
    text.setPosition(10,10);
//box---------------------------------------------------------------------------------------------------------
    sf::Texture BoxTex;
    BoxTex.loadFromFile("gfx/box.png");
    sf::Sprite Box;
    Box.setTexture(BoxTex);
    Box.setPosition(90,60);
//Musuh-------------------------------------------------------------------------------------------------------
    sf::Texture ZombTex;
    ZombTex.loadFromFile("gfx/zombie.png");
    sf::Sprite Enemy;
    Enemy.setTexture(ZombTex);
    Enemy.setPosition(1270,315);
    Enemy.setScale(sf::Vector2f(2.f,2.f));
    sf::Texture ZombTex2;
    ZombTex2.loadFromFile("gfx/zombie2.png");
    sf::Sprite Enemy2;
    Enemy2.setTexture(ZombTex2);
    Enemy2.setScale(sf::Vector2f(2.f,2.f));
    std::vector<sf::Sprite> Zombies;
//bomb--------------------------------------
    sf::Texture boomtext;
    boomtext.loadFromFile("gfx/boom.png");
    sf::Sprite boom;
    boom.setTexture(boomtext);
    std::vector <sf::Sprite> bomb;
//player-----------------------------------------------------------------------------------------------------
    sf::Texture PlayerTex;
    PlayerTex.loadFromFile("gfx/Player.png");
    sf::Sprite Player;
    Player.setTexture(PlayerTex);
    Player.setOrigin(20.f,15.f);
    Player.setScale(2.f,2.f);
    int currentscore =0;
//peluru----------------------------------------------------------------------------------------------------
    sf::Texture PelTex;
    PelTex.loadFromFile("gfx/bullet.png");
    sf::Sprite peluru;
    peluru.setTexture(PelTex);
    peluru.setPosition(-100,-100);
    std::vector<sf::Sprite> pelurux;
    peluru.setScale(0.7f,0.7f);
    Player.setPosition(40,20);
    sf::Texture gunfirex;
    gunfirex.loadFromFile("gfx/gunfire.png");
    sf::Sprite gunfire;
    gunfire.setTexture(gunfirex);
//Music-----------------------
    sf::Music music;
    music.openFromFile("sfx/horde.ogg");
//ZSINIT------------------------------
    sf::Texture zstext;
    zstext.loadFromFile("gfx/z1.png");
    sf::Texture zstext2;
    zstext2.loadFromFile("gfx/citizenzombieboss.png");
    sf::Texture zstext3;
    zstext3.loadFromFile("gfx/army.png");
    zclass z2(&zstext2,1300,((rand()%600)+20));
    z2.settype(2);
    z2.zx.setTextureRect(sf::IntRect(0,0,231,156));
    zclass z1(&zstext, 2400,((rand()%600)+20));
    z1.settype(1);
    zclass z3(&zstext3, 2800,((rand()%600)+20));
    z3.settype(3);
//
    sight laser;
    artillery arti;
//----------------------------------------------------------------------------------------------------------
    Airsupport Airsupport(1000.f,0.0f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
//Main-Menu---------------------------------------------------------------------------------------------
        zrand= rand()%2;
        Menu Menu(175,580);
        int yx=Menu.getInt();
        Menu.atas();
        Menu.bawah();
        Menu.howtoplay();
    if (menuavailable == 1){
        if ( yx==1 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            play=1;
            menuavailable=0;
            music.play();
            music.setLoop(1);
            music.setVolume(5.f);
        }

         if ( yx==2 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            play=2;
        }
    }
//game update-------------------------------------------------------------------------------------------------------
if (play==1 && gameover==0){
        MidP= sf::Vector2f(Player.getPosition().x,Player.getPosition().y-5);
        arti.init();
        laser.init();
        laser.on(MidP);
        if(laser.b > 0)
        {
            ons=1;
        }
        if(ons==1)
        {
            on++;
        }
        if(on>0)
        {

        }
        else
        {
        laser.of();
        }
        if(on>=2000)
        {
            on=0;
            ons=0;
            laser.b=0;
        }
        std::cout << arti.artyav<< std::endl;
        HealthBar.setSize(sf::Vector2f(HP*0.01f,20.f));
        RBAR.setSize(sf::Vector2f(rx*0.42f,20.f));
//posisi Player--------------------------------------------------------------------------------------------
        Player.setPosition(40,sf::Mouse::getPosition(window).y);
        if (Player.getPosition().y > window.getSize().y-Player.getGlobalBounds().height)
        {
            Player.setPosition(Player.getPosition().x,window.getSize().y-Player.getGlobalBounds().height);
        }
        if (Player.getPosition().y < 80)
        {
            Player.setPosition(Player.getPosition().x,80);
        }
//enemy move/spawn/col------------------------------------------------------------------------------------------
        for ( j=0; j < Zombies.size(); j++)
        {
            Zombies[j].move(-2.f,0.0f);
            if (Zombies[j].getPosition().y < 50)
            {
            Zombies.erase(Zombies.begin()+j);
            }
            if (Zombies[j].getPosition().y > 780)
            {
            Zombies.erase(Zombies.begin()+j);
            }
             if(Box.getGlobalBounds().intersects(Zombies[j].getGlobalBounds())){
                Zombies[j].setTextureRect(sf::IntRect(0,pos*32, 32, 32));
                Zombies[j].move(2.f,0.f);
                HP=HP-10;
                if(plz.getElapsedTime().asSeconds()<0.5f){
                        pos=0;
                    }
                    if(plz.getElapsedTime().asSeconds()>0.5f){
                        pos=1;
                    }
                    if(plz.getElapsedTime().asSeconds()>1.f){
                        pos=2;
                    }
                    if(plz.getElapsedTime().asSeconds()>1.5f){
                        plz.restart();
                    }
            }
             if(laser.line.getGlobalBounds().intersects((Zombies[j].getGlobalBounds())))
                {
                laser.line.setSize(sf::Vector2f(Zombies[j].getPosition().x-Zombies[j].getGlobalBounds().width/2,2.f));
                }
        }
        if (zombspawn1>=spwnr)
        {
            Enemy.setPosition(window.getSize().x, rand()%int(window.getSize().y- Enemy.getGlobalBounds().height));
            Enemy.setTextureRect(sf::IntRect(0,0, 32, 32));
            Enemy2.setPosition(window.getSize().x, rand()%int(window.getSize().y- Enemy.getGlobalBounds().height));
            Enemy2.setTextureRect(sf::IntRect(0,0, 32, 32));
            if(zrand==1){
            Zombies.push_back(sf::Sprite(Enemy));
            }
            if(zrand==0){
            Zombies.push_back(sf::Sprite(Enemy2));
            }
            zombspawn1=0;
        }
        if (zombspawn1<spwnr)
        {
            zombspawn1++;
        }
//Zombie S type
//COLLISION DENGAN BOX
        if(Box.getGlobalBounds().intersects(z2.zx.getGlobalBounds()))
        {
            z2.gerak(-1.5f);
            HP=HP-20;
             if(tlg.getElapsedTime().asSeconds()<0.5f){
                         z2.zx.setTextureRect(sf::IntRect(0,0,231,156));
                    }
                    if(tlg.getElapsedTime().asSeconds()>0.5f){
                        z2.zx.setTextureRect(sf::IntRect(0,159,231,195));
                    }
                    if(tlg.getElapsedTime().asSeconds()>1.f){
                         z2.zx.setTextureRect(sf::IntRect(0,346,231,135));
                    }
                    if(tlg.getElapsedTime().asSeconds()>1.5f){
                        tlg.restart();
                    }
        }
        else
        {
             z2.zx.setTextureRect(sf::IntRect(0,0,231,156));;
        }
        if(Box.getGlobalBounds().intersects(z1.zx.getGlobalBounds()))
        {
            z1.gerak(-2.0f);
            HP=HP-8;
        }
        if(Box.getGlobalBounds().intersects(z3.zx.getGlobalBounds()))
        {
            z3.gerak(-2.0f);
            HP=HP-8;
        }
//WAKTU MUNCUL
        if(Timercount > 10)
        {
         z2.gerak(1.5f);
        }
        if(Timercount > 15)
        {
            z1.gerak(2.0f);
        }
        if(Timercount > 20)
        {
            z3.gerak(2.0f);
        }
//COLLISION DENGAN LASER
        if(laser.line.getGlobalBounds().intersects((z2.zx.getGlobalBounds())))
        {
            laser.line.setSize(sf::Vector2f(z2.zx.getPosition().x-z2.zx.getGlobalBounds().width/15,2.f));
        }
         if(laser.line.getGlobalBounds().intersects((z3.zx.getGlobalBounds())))
        {
            laser.line.setSize(sf::Vector2f(z3.zx.getPosition().x-z3.zx.getGlobalBounds().width/15,2.f));
        }
//EFEK HP SPECIAL ZOMBIE
            if(z2.HP<1)
        {
            z2.reset(2,(rand()%200)+2400,(rand()%700));
            z2dead.play();
            z2hurt.stop();
            currentscore=currentscore+50;
        }
         if(z1.HP<1)
        {
            laser.b++;
            z1.reset(1,(rand()%200)+10000,(rand()%700));
        }
        if(z3.HP<1)
        {
            z3.reset(3,(rand()%200)+13000,(rand()%700));
            ammocount=100;
        }
//bullet collision--------------------------------------------------------------------------------------------------
        for ( i=0; i < pelurux.size(); i++){
                if(pelurux[i].getGlobalBounds().intersects(z2.zx.getGlobalBounds()))
                    {
                    pelurux.erase(pelurux.begin()+i);
                    z2.HP--;
                    z2hurt.play();
                    break;
                    }
                 if(pelurux[i].getGlobalBounds().intersects(z1.zx.getGlobalBounds()))
                    {
                    pelurux.erase(pelurux.begin()+i);
                    z1.HP--;
                    break;
                    }
                 if(pelurux[i].getGlobalBounds().intersects(z3.zx.getGlobalBounds()))
                    {
                    pelurux.erase(pelurux.begin()+i);
                    z3.HP--;
                    break;
                    }

            for ( j=0; j < Zombies.size(); j++){
                if (pelurux[i].getGlobalBounds().intersects((Zombies[j].getGlobalBounds())) ){
                    currentscore=currentscore+5;
                    Zdied.play();
                    Zombies.erase(Zombies.begin()+j);
                    pelurux.erase(pelurux.begin()+i);
                    break;
                }
            }
        }
//Help plane,helpx,g,fly----------------------------------------------------------------------------------------------------

        if(HP<75000)
        {
            fly++;
        }
         if(fly==1)
        {
            standby.play();
        }
        if(HP<75000 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            helpx++;
            standby.stop();
            Bombing.restart();
        }
        if(helpx==1){
            g++;
            Bomber.play();
        }
            if(g>0){
            Airsupport.gerak(2.0f);
            }
         for(int adraw=0;adraw<bomb.size();adraw++){
            for ( j=0; j < Zombies.size(); j++){
                if(bomb[adraw].getGlobalBounds().intersects(Zombies[j].getGlobalBounds())&& aj<12){
                    currentscore=currentscore+3;
                    Zdied.play();
                    Zombies.erase(Zombies.begin()+j);
                }
            }
        }

//boom------------------------------------------------------------------------------------------------------

        if (aj>=1.2)
        {
            boom.setPosition((rand()%1200)+120, rand()%int(window.getSize().y));
            boom.setTextureRect(sf::IntRect(0,0,98,86));
            bomb.push_back(sf::Sprite(boom));
            aj=0;
        }
        if(aj<=1)
        {
            aj++;
        }
        ay++;
       if(ay %6 == 0 )
       {
           ax=ax+1;
       }
       if(ax>24)
       {
           ay=0;
           ax=0;
       }
       for(int adraw =0;adraw<bomb.size();adraw++){
            if(Airsupport.planex[0].getGlobalBounds().intersects(bomb[adraw].getGlobalBounds())
               || Airsupport.planex[1].getGlobalBounds().intersects(bomb[adraw].getGlobalBounds())
               || Airsupport.planex[2].getGlobalBounds().intersects(bomb[adraw].getGlobalBounds())
               || Airsupport.planex[3].getGlobalBounds().intersects(bomb[adraw].getGlobalBounds())
               || Airsupport.planex[4].getGlobalBounds().intersects(bomb[adraw].getGlobalBounds())
               || arti.artyx.getGlobalBounds().intersects(bomb[adraw].getGlobalBounds()))
               {
                   bomb[adraw].setTextureRect(sf::IntRect(ax*100,0,98,86));
               }

            else
            {
                bomb.erase(bomb.begin()+adraw);
            }
        }
        if(arti.artyb==1)
        {
            Player.setPosition(40.f,400.f);
        }
//Shootin, Reloadin----------------------------------------------------------------------------------------------

        Reloading.setPosition(Player.getPosition().x-40,Player.getPosition().y+30);
        RBAR.setPosition(Player.getPosition().x-40,Player.getPosition().y+50);
    if(ammocount>0){
        if(f<10)
        {
            f=f+1;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && f>= 10)
        {
          peluru.setPosition(MidP);
          peluru.setScale(0.5f,0.5f);
          pelurux.push_back(sf::Sprite(peluru));
          p=1;
          gunfire.setPosition(Player.getPosition().x+40,Player.getPosition().y-15);
          gunfire.setScale(0.2f,0.2f);
          ak47.play();
          f=0;
          ammocount--;
        }
        else
        {
            p=0;//int p untuk mendraw gunfire
        }
    }
    if(ammocount == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        p=0;//untk mendraw gunfire
        ammoempty.play();
    }
    if(ammocount<30 && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
       p=0;//untuk mendraw gunfire
        b++;
        ammocount=0;//jumlah peluru
    }
    if(b>0)
    {
        ammo=ammo+0.1;//suara dan waktu reload dan mendraw kotak dan text
        rx++;//lebar box reload
    }
    if(ammo==0.5)
    {
        Reload.play();
    }
        if(ammo>20)
        {
            ammocount=30;//jumlah peluru
            ammo=0;
            b=0;
            rx=0;
        }

        for ( i=0;i<pelurux.size();i++)
        {
            pelurux[i].move(10.0f,0.0f);
            if (pelurux[i].getPosition().x> 1200){
                pelurux.erase(pelurux.begin()+i);
            }
        }
//UI_UPDATE------------------------------------------------------------------------------------
        Score.setString("Score  " + std::to_string(currentscore));
        ammoleft.setString("Ammo " + std::to_string(ammocount));
        artytext.setString("Artillery x"+std::to_string(arti.artyav));
        if (Clock.getElapsedTime() >= sf::seconds(1))
        {
            Timercount=Timercount+1;
            Clock.restart();
        }
        std::stringstream s;
        s << Timercount;
        Waktu.setString("Timer  " + s.str());
        if (Timercount %10== 0 && spwnrminus==1)
        {
            spwnr=spwnr-0.1;

            if(spwnr<30)
            {
                spwnrminus=0;
            }
        }

        if(HP<0)
        {
            gameover=1;
            Bomber.stop();
        }
        LOSESCORE.setString("         YOUR SCORE  "+ std::to_string(currentscore));
        LOSETEXT.setString("\n\n      PRESS ESC TO EXIT \n\n   PRESS SPACE TO RETRY");
}
//DRAW-----------------------------------------------------------------------------------------
        window.clear();
        if (play == 1)
        {

        window.draw(spriteBackground);
        window.draw(Box);
        for ( i=0; i < pelurux.size(); i++)
        {
            window.draw(pelurux[i]);
        }

        window.draw(text);
        window.draw(laser.line);
        window.draw(Player);
        if(p>0){
        window.draw(gunfire);
        }
        for ( j=0; j < Zombies.size(); j++)
        {
            window.draw(Zombies[j]);
        }
        window.draw(z1.zx);
        window.draw(z2.zx);
        window.draw(z3.zx);
        for(adraw=0;adraw<bomb.size();adraw++)
        {
            window.draw(bomb[adraw]);
        }
       Airsupport.draw(window);
       if(ammo>0)
       {
           window.draw(Reloading);
           window.draw(RBAR);
       }
       arti.draw(window);
       if (gameover==1)
        {
            music.stop();
            window.draw(LOSEBAR);
            window.draw(LOSESCORE);
            window.draw(LOSETEXT);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                goto start;
                on=2001;
            }
        }
        if(((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && HP<0))
            {
                window.close();
            }
        window.draw(UIBAR);
        window.draw(Score);
        window.draw(Waktu);
        window.draw(ammoleft);
        window.draw(artytext);
        window.draw(HealthBar);
        }
        if (play == 2)
        {
            window.close();
        }
          if(play ==0 )
        {
           window.draw(MainMenuBackground);
           Menu.draw(window);
        }
        window.display();
    }

    return 0;
}
