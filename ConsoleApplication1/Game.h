#pragma once

#include "GameState.h"

class Game
{

private: 

	sf::Event event;
	sf::RenderWindow *window;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	void initWindow();
	void initStates();

public:

	Game();
	virtual ~Game();

	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

