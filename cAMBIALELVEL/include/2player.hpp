
#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"../include/Entity.hpp"
#include"../include/platform.hpp"
#include"../include/object.hpp"


class Player2: public Entity{
private:
    bool collision;
    bool interacting;
    bool onGround;
    float jumpHeigt;
    float speed;

    int walkCounter, walkFrameFinal, idleFrames, walkSpeed, idleSpeed;
    int walkFrameStart;

public:

    std::vector<bool> collected{0,0,0};
    Player2(float X,float Y,float W,float H, sf::Texture& t);
    void update(bool &keyW, bool &keyS, bool &keyA, bool &keyD, bool& key0, std::vector<Platform>& level, object key, Player2 player2);
    int withinReach(std::vector<object> allObjects, Player2 player2);
    void collide(float xVel, float yVel, std::vector<Platform>& level);
    bool interact(int id, Player2 player2);
    void animate();
    void walk();

};
