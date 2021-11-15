#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<vector>
#include"include/Entity.hpp"
#include"include/player.hpp"
#include"include/2player.hpp"
#include"include/platform.hpp"
#include"include/object.hpp"

struct ppos {
        int x = 0;
        int y = 0;
};

struct startValues {

    int levelArray[23][20];
    ppos ppos1;
    ppos ppos2;

};


int windowWidth = 1000;
int windowHeigth = 800;

float accelGravity = 0.2f;
float maxGravity = 5.f;


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

    /*

    l


    */

    platformTexPart1.loadFromFile("assets/images/Plataforma-01.png");
    platformTexPart2.loadFromFile("assets/images/Plataforma-02.png");
    platformTexPart3.loadFromFile("assets/images/Plataforma-03.png");

    int currentLevel = 1;

    //Player player1(100, 300, 32, 32, player1Tex);
   // Player2 player2(100, 300, 32, 32, player2Tex);

    bool keyUp, keyDown, keyLeft, keyRight, keyW, keyS, keyA, keyD, key0, keyE =false;
    sf::Clock gameClock;

    sf::Music music;
    if (!music.openFromFile("assets/music.wav"))
    return -1; // error
    music.play();
    music.setLoop(true);


   // currentLevel++;

    while (window.isOpen()){

        bool locked1 = true;
        bool locked2 = true;

        ppos plock1;
        ppos pkey1;

        ppos plock2;
        ppos pkey2;

        ppos pdoor;
        ppos pboton;

        ppos pp1;
        ppos pp2;


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




            // LEVEL 2-----------------------------------------------------------------------

                if (currentLevel==2){
                int levelArray1[23][20]={{10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,10},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                          {1,3,4,4,4,4,4,4,4,5,1,0,0,0,0,0,0,10,2,1},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,3,5,0,0,0,0,0,1},
                                          {1,2,2,2,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                          {1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,3,5,0,0,1},
                                          {1,0,0,0,0,0,3,4,5,0,1,0,0,0,0,0,0,0,0,1},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,10,2,1},
                                          {1,2,2,2,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,3,4,5,0,10,2,2,1},
                                          {1,0,0,0,0,0,0,3,5,0,1,0,0,0,0,0,1,0,0,1},
                                          {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1},
                                          {10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,10},
                                        };


                    for(int i = 0; i<23; i++) for(int j = 0; j<20; j++) levelArray[i][j]=levelArray1[i][j];
                    plock1.x = -290;
                    plock2.x = 290;
                    pp2.x = 730;
                    pp2.y = 200;
                    pdoor.x = -760;
                    pdoor.y = -502;
                    plock1.y=20;
                    plock2.y=1;
                    pkey2.x=50;
                    pkey2.y=10;
                    pkey1.y=5;

            }




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

                            if (levelArray[i][j]==11) std::cout<<level.size();
                        }
                    }

                    std::vector<object> allObjects1;
                    std::vector<object> allObjects2;
                    object key1 (907+pkey1.x, 125+pkey1.y, 36, 15, 10, key1tex);
                    object lock1 (760+plock1.x, 600+plock1.y, 30, 30, 11, lock1tex);
                    allObjects1.push_back(lock1);
                    object key2 (600+pkey2.x, 470+pkey2.y, 36, 15, 20, key2tex);
                    object lock2 (270+plock2.x, 620+plock2.y, 30, 30, 21, lock2tex);
                    allObjects2.push_back(lock2);
                    object boton (100+pboton.x,643+pboton.y, 10, 5, 30, botontex);
                    allObjects2.push_back(boton);
                    object door (880+pdoor.x,603+pdoor.y, 50, 49, 40, doortex);
                    allObjects1.push_back(door);
                    allObjects2.push_back(door);

                    key1.update(level);
                    key2.update(level);
                    lock1.update(level);
                    lock2.update(level);

                    Player2 player2(100+pp2.x, 300+pp2.y, 32, 32, player2Tex);
                    Player player1(100+pp1.x, 300+pp1.y, 32, 32, player1Tex);

        sf::Event event;
        bool changeLevel = false;

     while (!changeLevel){
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


        key1.update(level);
        key2.update(level);
        lock1.update(level);
        lock2.update(level);


        player1.update(keyW, keyS, keyA, keyD, keyE,  level, key1, player1);
        player2.update(keyUp, keyDown, keyLeft, keyRight, key0, level, key1, player2);


        gameClock.restart().asSeconds();

        window.clear();
        window.draw(spriteBackground);
        window.draw(player1);

        window.draw(player2);

       if (!player1.collected[0]) window.draw(key1);
       if (!player2.collected[1]) window.draw(key2);

      if (keyE){

            int currentObj = 0;

            if (!key1.getGlobalBounds().intersects(player1.getGlobalBounds())){
                currentObj = player1.withinReach(allObjects1, player1);
            }

            else currentObj = key1.id;
            if (currentObj == 11) {
                    locked1 = player1.interact(currentObj, player1);

                    if (!locked1){
                        lock1.unlock(openlock2tex);
                        Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                        if (currentLevel==2) level[92] = p;
                        else level[81] = p;
                    }
            }
            else if (currentObj == 40) changeLevel = true;

            else player1.interact(currentObj, player1);


        }


            window.draw(lock1);




        if (key0){

            int currentObj = 0;

            if (!key2.getGlobalBounds().intersects(player2.getGlobalBounds())){
                currentObj = player2.withinReach(allObjects2, player2);
            }

            else currentObj = key2.id;
            if (currentObj == 21) {
                    locked2 = player2.interact(currentObj, player2);

                    if (!locked2){
                        lock2.unlock(openlock2tex);
                        Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                        if (currentLevel == 2) level[65] = p;
                        else level[72] = p;
                    }
            }

            else if (currentObj == 30) {

                if (!player2.interact(currentObj, player2)){

                    Platform p( 0.f, 0.f, 0.f, 0.f, verText);
                    level[21] = p;
                    level[24] = p;

                };

            }
            else if (currentObj == 40) changeLevel = true;

            else player2.interact(currentObj, player2);


        }


            window.draw(lock2);



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

        window.draw(boton);
        boton.update(level);

        window.display();
        std::cout<<currentLevel;
    }

    currentLevel++;
    if (currentLevel==3) return 0;

}
return 0;
}
