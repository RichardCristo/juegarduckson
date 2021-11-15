#include<SFML/Graphics.hpp>
#include"include/Entity.hpp"
#include"include/platform.hpp"


Platform::Platform(float X, float Y, float W, float H, sf::Texture& t){

    siZe.x = W;
    siZe.y = H;

    hitbox.left = X + 0.f;
    hitbox.right = X + siZe.x - 0.f;
    hitbox.top = Y + 0.f;
    hitbox.bottom = Y + siZe.y - 0.f;

    setTexture(t);
    setPosition(X, Y);
}
