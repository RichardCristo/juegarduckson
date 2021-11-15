#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"../include/Entity.hpp"
#include"../include/platform.hpp"
#include"../include/object.hpp"

class Player: public Entity{
private:
    bool collision;
    bool onGround;
    bool doubleJump;
    bool interacting;
    float jumpHeigt;
    float speed;

    int jumpCount;
    int walkCounter, walkFrameFinal, idleFrames, walkSpeed, idleSpeed;
    int walkFrameStart;

public:

    std::vector<bool> collected{0,0,0};
    Player( float X,float Y,float W,float H, sf::Texture& t);
    void update(bool &keyW, bool &keyS, bool &keyA, bool &keyD, bool &keyE, std::vector<Platform>& level, object p, Player player);
    void collide(float xVel, float yVel, std::vector<Platform>& level);
    withinReach(std::vector<object> allObjects, Player player);
    bool interact(int id, Player player);
    void animate();
    void walk();

};
