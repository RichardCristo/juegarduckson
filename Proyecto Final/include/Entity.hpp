#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"../include/hitbox.hpp"
class Entity : public sf::Sprite{
    public:
        sf::Vector2f velocity;
        sf::Vector2f siZe;
        sf::Vector2f frameSize;
        sf::Vector2f framesAmount;
        std::vector<sf::IntRect> frames;
        hitBox hitbox;


};
