#include <SDL.h>
#include <SDL_image.h>
#include "Macs.h"
#include "Player.h"
#include <map>

#pragma once
class SpaceInvaders
{
public:
	bool shouldQuit = false;
	Player* player;
	std::map<int, int> keys;
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public: 
	SpaceInvaders();
	~SpaceInvaders();

	int startGame();
	void gameLoop();
	void update(double delta);
	void render();
	void endGame();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
};

