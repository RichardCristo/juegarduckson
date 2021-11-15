
#include<SFML/Graphics.hpp>
#include "include/mainMenu.hpp"
MainMenu::MainMenu(int windowWidth = 1000, int windowHeigth = 800){

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Jugar")
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);
    //Options;
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Salir")
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);

    MainMenuSelected = -1;

}

MainMenu::~MainMenu(){
}

void MainMenu::draw(RenderWindow& window){

    for (int i = 0; i <  Max_main_menu; i++){

        window.draw(mainMenu[i]);

    }

}

void MainMenu::MoveUp(){

    if (MainMenuSelected-1 >= 0){

        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;

        if (MainMenuSelected == -1){

            MainMenuSelected = 2;

        }

      mainMenu[MainMenuSelected].setFillColor(Color::Yellow);

    }

}

void MainMenu::MoveUp(){

    if (MainMenuSelected+1 <= Max_main_menu){

        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;

        if (MainMenuSelected == 4){

            MainMenuSelected = 0;

        }

      mainMenu[MainMenuSelected].setFillColor(Color::Yellow);

    }

}
