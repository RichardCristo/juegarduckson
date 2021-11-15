#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<math.h>
#include"include/Entity.hpp"
//#include"include/player2.hpp"
#include"include/hitbox.hpp"
#include"include/platform.hpp"
#include"include/object.hpp"
extern float accelGravity;
extern float maxGravity;


object::object(float X, float Y, float W, float H, int getid, sf::Texture& t){

     siZe.x = W;
    siZe.y = H;
    id = getid;
    if (id == 11||id == 21) isLock = true;
    setTexture(t);

    setPosition(X, Y);

}

void object::unlock(sf::Texture& t){
    setTexture(t);
}

void object::update(std::vector<Platform>& level){

    if(onTouch){
    velocity.x = 1.f;
    }

 if(onGround == false){
    velocity.y += accelGravity;
    if(velocity.y> maxGravity) velocity.y = maxGravity;
 }else{
  onGround = true;
 }
velocity.y;
velocity.x = 0.f;

 move(velocity.x * speed, 0);
 collide(velocity.x, 0, level);

 move(0, velocity.y);
 collide(0, velocity.y, level);





 }

 void object::collide(float xVel, float yVel, std::vector<Platform>& level){
    for(Platform& p : level){
        if(getPosition().x + 2.f < p.hitbox.right &&
           getPosition().x + siZe.x - 1.f > p.hitbox.left &&
           getPosition().y + 1.f< p.hitbox.bottom &&
           getPosition().y + siZe.y > p.hitbox.top){
            collision = true;
           }else{
           collision=false;
           }
           if(collision){
            if(xVel > 0){
                setPosition(p.hitbox.left - siZe.x + 1.f, getPosition().y);
                velocity.x = 0;
            }
            if(xVel < 0){
                setPosition(p.hitbox.right -2.f, getPosition().y);
                 velocity.x = 0;
            }
             if(yVel > 0){
                setPosition(getPosition().x, p.hitbox.top - siZe.y + 0.f );
                 velocity.y = 0;
                 onGround=true;
            }
            if(yVel < 0){
                setPosition(getPosition().x, p.hitbox.bottom - 1.f);
                 velocity.y = 0;
            }
           }
    }

}




