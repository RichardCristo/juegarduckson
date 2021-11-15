#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"../include/Entity.hpp"
//#include"../include/player2.hpp"
#include"../include/platform.hpp"



class object : public Entity{
private:
    bool collision;
    bool playerCol;
    bool onGround;
    bool onTouch;
    float speed;
public:
    int id;
    bool isLock = false;
    object(float X,float Y,float W,float H, int getid, sf::Texture& t);
    void update(std::vector<Platform>& level);
    void collide(float xVel, float yVel, std::vector<Platform>& level);
    void unlock(sf::Texture& t);
};
