#include "PlayerProjectile.h"
#include <SDL_image.h>
#include <iostream>

PlayerProjectile::PlayerProjectile(SDL_Renderer* renderer, Vector2<double> position, std::vector<PlayerProjectile*>* bullets) {
	scale.x = 5;
	scale.y = 5;
	width = 1;
	height = 7;
	this->position = position;
	this->bullets = bullets;

	rect.x = position.x;
	rect.y = position.y;
	rect.w = width * scale.x;
	rect.h = height * scale.y;

	velocity.y = -2;

	SDL_Surface* surface = IMG_Load("res/images/bullet.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	SDL_FreeSurface(surface);
}

PlayerProjectile::~PlayerProjectile() {
	SDL_DestroyTexture(texture);
}

void PlayerProjectile::update(double delta) {
	Projectile::update(delta);

	if (position.y < -height * scale.y) {
		bullets->erase(bullets->begin() + this->id);
		delete this;
	}
}


void PlayerProjectile::render(SDL_Renderer* renderer) {
	rect.x = (int)position.x;
	rect.y = (int)position.y;

	if (SDL_RenderCopy(renderer, texture, NULL, &rect) < 0) {
		std::cerr << "Error rendering player projectile: " << SDL_GetError() << std::endl;
	}
}