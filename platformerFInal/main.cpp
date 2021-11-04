#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<vector>
#include"include/Entity.hpp"
#include"include/player.hpp"
#include"include/2player.hpp"
#include"include/platform.hpp"
#include"include/object.hpp"


int windowWidth = 1000;
int windowHeigth = 800;

float accelGravity = 0.2f;
float maxGravity = 5.f;

bool locked1 = true;
bool locked2 = true;
bool doorBool = true;

int main(){
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeigth), "pikopark2");
    window.setFramerateLimit(60);



    sf::Texture player1Tex;
    sf::Texture player2Tex;

    sf::Texture verText;
    sf::Texture horText;
    sf::Texture izqSup;
    sf::Texture izqInf;
    sf::Texture derSup;
    sf::Texture derInf;
    sf::Texture solid;

    sf::Texture doortex;
    sf::Texture botontex;

    sf::Texture platformTexPart1;
    sf::Texture platformTexPart2;
    sf::Texture platformTexPart3;

    sf::Texture key1tex;
    sf::Texture key2tex;

    sf::Texture lock1tex;
    sf::Texture lock2tex;
    sf::Texture openlock1tex;
    sf::Texture openlock2tex;

    sf::Texture textureBackground;

    textureBackground.loadFromFile("assets/images/wallpaper.png");
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(-300,0);


    key1tex.loadFromFile("assets/images/Llave-Oro.png");
    key2tex.loadFromFile("assets/images/Llave-Plata.png");


    lock1tex.loadFromFile("assets/images/Lock-Oro-Cerrado.png");
    lock2tex.loadFromFile("assets/images/Lock-Plata-Cerrado.png");

    doortex.loadFromFile("assets/images/Puerta-01.png");

    botontex.loadFromFile("assets/images/Boton-01.png");

    openlock1tex.loadFromFile("assets/images/Lock-Oro-Abierto.png");
    openlock2tex.loadFromFile("assets/images/Lock-Plata-Abierto.png");

    player1Tex.loadFromFile("assets/images/diana.png");
    player2Tex.loadFromFile("assets/images/willy.png");

    verText.loadFromFile("assets/images/Castillo-ver.png");
    horText.loadFromFile("assets/images/Castillo-hor.png");
    izqSup.loadFromFile("assets/images/Castillo-izqSup.png");
    izqInf.loadFromFile("assets/images/Castillo-izqInf.png");
    derSup.loadFromFile("assets/images/Castillo-derSup.png");
    derInf.loadFromFile("assets/images/Castillo-derInf.png");
    solid.loadFromFile("assets/images/Castillo-01.png");



    platformTexPart1.loadFromFile("assets/images/Plataforma-01.png");
    platformTexPart2.loadFromFile("assets/images/Plataforma-02.png");
    platformTexPart3.loadFromFile("assets/images/Plataforma-03.png");
    int levelArray[23][20]={{10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,10},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                            {1,0,0,3,5,0,0,3,5,0,0,0,3,5,0,0,0,10,2,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {1,2,2,2,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {1,0,0,0,0,0,3,4,5,0,0,0,0,0,0,0,0,0,0,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {1,2,2,2,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {1,0,0,0,1,0,0,0,0,0,3,4,4,4,5,0,10,2,2,1},
                            {1,0,0,0,1,0,0,3,5,0,0,0,0,0,0,0,1,0,0,1},
                            {1,0,0,0,1,0,10,0,0,10,0,0,0,0,0,0,1,0,0,1},
                            {10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9},
                            };
        std::vector<Platform> level;


        for(int i = 0; i<23; i++){
            for(int j=0; j<20; j++){
                if(levelArray[i][j]==1){
                    Platform p( j*50.f, i*50.f, 50.f, 50.f, verText);
                    level.push_back(p);
                }

                if(levelArray[i][j]==2){
                    Platform p( j*50.f, i*50.f, 50.f, 50.f, horText);
                    level.push_back(p);
                }
                if(levelArray[i][j]==3){
                    Platform platformPart1( j*50.f, i*50.f, 50.f, 50.f, platformTexPart1);
                    level.push_back(platformPart1);
                }
                if(levelArray[i][j]==4){
                    Platform platformPart2( j*50.f, i*50.f, 50.f, 50.f, platformTexPart2);
                    level.push_back(platformPart2);
                }
                if(levelArray[i][j]==5){
                    Platform platformPart3( j*50.f, i*50.f, 50.f, 50.f, platformTexPart3);
                    level.push_back(platformPart3);
                }

                if(levelArray[i][j]==6){
                    Platform izqS( j*50.f, i*50.f, 50.f, 50.f, izqSup);
                    level.push_back(izqS);
                }

                if(levelArray[i][j]==8){
                    Platform izqI( j*50.f, i*50.f, 50.f, 50.f, izqInf);
                    level.push_back(izqI);
                }

                if(levelArray[i][j]==7){
                    Platform derS( j*50.f, i*50.f, 50.f, 50.f, derSup);
                    level.push_back(derS);
                }

                if(levelArray[i][j]==9){
                    Platform derI( j*50.f, i*50.f, 50.f, 50.f, derInf);
                    level.push_back(derI);
                }

                if(levelArray[i][j]==10){
                    Platform platformPart3( j*50.f, i*50.f, 50.f, 50.f, solid);
                    level.push_back(platformPart3);
                }
            }
        }
    object key1 (900, 150, 36, 15, 10, key1tex);
    object lock1 (760, 600, 30, 30, 11, lock1tex);

    object key2 (600, 400, 36, 15, 20, key2tex);
    object lock2 (270, 620, 30, 30, 21, lock2tex);

    object boton (100,643, 10, 5, 30, botontex);

    object door (880,603, 50, 49, 40, doortex);

    Player player1(100, 300, 32, 32, player1Tex);

    Player2 player2(100, 300, 32, 32, player2Tex);

    bool keyUp, keyDown, keyLeft, keyRight, keyW, keyS, keyA, keyD, key0, keyE =false;
    sf::Clock gameClock;

    sf::Music music;
    if (!music.openFromFile("assets/music.wav"))
    return -1; // error
    music.play();
    music.setLoop(true);



    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }

        //player1

        keyA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        keyD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        keyW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        keyS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        keyE = sf::Keyboard::isKeyPressed(sf::Keyboard::E);
        //player2
        keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        key0 = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);




        player1.update(keyW, keyS, keyA, keyD, keyE,  level, key1, player1);
        player2.update(keyUp, keyDown, keyLeft, keyRight, key0, level, key1, player2);
        key1.update(level);
        key2.update(level);
        lock1.update(level);
        lock2.update(level);


        gameClock.restart().asSeconds();

        window.clear();
        window.draw(spriteBackground);
        window.draw(player1);

        window.draw(player2);

       if (!player1.collected[0]) window.draw(key1);
       if (!player2.collected[1]) window.draw(key2);


        if (keyE && player1.collected[0]) locked1=player1.interact(lock1, player1);
        else if (keyE) player1.interact(key1, player1);

        if (locked1) {
                window.draw(lock1);
        }
        else {
                lock1.unlock(openlock2tex);
                window.draw(lock1);
                Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                level[81] = p;
        }

        if (key0 && player2.collected[1]) locked2=player2.interact(lock2, player2);
        else if (key0) player2.interact(key2, player2);

        if (locked2) {
                window.draw(lock2);
        }
        else {
                lock2.unlock(openlock2tex);
                window.draw(lock2);
                Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                level[72] = p;

        }

        for(Platform& p : level){
            window.draw(p);
        }
          for(Platform& platformPart1 : level){
            window.draw(platformPart1);
        }
          for(Platform& platformPart2 : level){
            window.draw(platformPart2);
        }
          for(Platform& platformPart3 : level){
            window.draw(platformPart3);
        }

        for(Platform& izqS : level){
            window.draw(izqS);
        }

        for(Platform& izqI : level){
            window.draw(izqI);
        }


        for(Platform& derS : level){
            window.draw(derS);
        }


        for(Platform& derI : level){
            window.draw(derI);
        }


        door.update(level);
        window.draw(door);

        if (!player2.interact(boton, player2)){

                Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                level[21] = p;
                level[24] = p;

        };


        if (key0 && !locked2) doorBool=player2.interact(door, player2);
        window.draw(boton);
        boton.update(level);

        window.display();

}
return 0;
}
