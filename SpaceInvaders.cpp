#include "SpaceInvaders.h"
#include <iostream>

SpaceInvaders::SpaceInvaders(){

}

SpaceInvaders::~SpaceInvaders() {

}


int SpaceInvaders::startGame() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL Video could not be initialized." << std::endl;
		return -1;
	}

	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

	if (window == nullptr || renderer == nullptr) {
		std::cerr << "Error creating the window and renderer" << std::endl;
		return -1;
	}

	SDL_SetWindowTitle(window, TITLE);

	player = new Player(renderer);

	gameLoop();

	return 0;
}

void SpaceInvaders::gameLoop() {

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	while (!shouldQuit) {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: shouldQuit = true; break;
				case SDL_KEYDOWN:
					keys[event.key.keysym.sym] = 1;
					switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							shouldQuit = true;
							break;
						case SDLK_SPACE:
							player->spawnBullet();
					}
					break;
				case SDL_KEYUP:
					keys[event.key.keysym.sym] = 0;
					break;

			}
		}
		
		update(deltaTime);
		render();
	}

	endGame();
}

void SpaceInvaders::update(double delta) {
	player->update(delta, keys);
	for (size_t i = 0; i < player->bullets.size(); i++) {
		player->bullets.at(i)->update(delta);
	}

	// print size of the bullets vector
	std::cout << player->bullets.size() << std::endl;
}

void SpaceInvaders::render() {
	SDL_RenderClear(renderer);
	player->render(renderer);
	for (size_t i = 0; i < player->bullets.size(); i++) {
		player->bullets.at(i)->render(renderer);
		int bId = player->bullets.at(i)->id;
		if (bId != i)
			bId = i;
	}
	SDL_RenderPresent(renderer);
}

void SpaceInvaders::endGame() {
	delete player;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Window* SpaceInvaders::getWindow() {
	return window;
}

SDL_Renderer* SpaceInvaders::getRenderer() {
	return renderer;
}

int main(int argc, char* argv[]) {
	SpaceInvaders game;
	game.startGame();

	return 0;
}