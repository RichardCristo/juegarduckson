#include "Game.h"

void Game::initWindow()
{

	std::ifstream ifs("Config/window.ini");
	sf::VideoMode window_bounds(800, 600);
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()){
	
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;

	}

	ifs.close();

	this->window = new sf::RenderWindow(sf::VideoMode(window_bounds),  title);
	this->window->setFramerateLimit(framerate_limit );
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateDt()
{

	this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{

	while (this->window->pollEvent(event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}


}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
		this->states.top()->update(this->dt);
}


void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();

}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}


}
