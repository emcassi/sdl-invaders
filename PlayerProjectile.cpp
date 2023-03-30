#include "PlayerProjectile.h"
#include <SDL_image.h>

PlayerProjectile::PlayerProjectile(SDL_Renderer* renderer, Vector2<double> position) {
	this->position = position;

	rect.x = position.x;
	rect.y = position.y;
	rect.w = width * scale.x;
	rect.h = height * scale.y;
	
	SDL_Surface* surface = IMG_Load("res/images/bullet.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void PlayerProjectile::update(double delta) {
	Projectile::update(delta);
}

void PlayerProjectile::render(SDL_Renderer* renderer) {
	rect.x = (int)position.x;
	rect.y = (int)position.y;
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}