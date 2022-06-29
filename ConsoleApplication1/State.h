#pragma once

#include<vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

class State
{

private:
	sf::RenderWindow* window;
	std::vector < sf::Texture> textures;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void endState() = 0;

	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

