#include "Player.h"
#include <iostream>

Player::Player(SDL_Renderer* renderer) {
	rect.w = width * scale.x;
	rect.h = height * scale.y;
	
	this->renderer = renderer;
	position.x = SCREEN_WIDTH / 2 - width * scale.x / 2;
	position.y = SCREEN_HEIGHT - height * scale.y;
	SDL_Surface* surface = IMG_Load("res/images/player.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player() {
	SDL_DestroyTexture(texture);

	for (auto bullet : bullets) {
		delete bullet;
	}
}

void Player::update(double delta, std::map<int, int> keys) {
	if (keys[SDLK_a] == 1 || keys[SDLK_LEFT] == 1) {
		position.x -= speed * delta;
	}

	if (keys[SDLK_d] == 1 || keys[SDLK_RIGHT] == 1) {
		position.x += speed * delta;
	}

	if (position.x < 0)
		position.x = 0;
	else if(position.x > SCREEN_WIDTH - width * scale.x)
		position.x = SCREEN_WIDTH - width * scale.x;

	if (!canShoot) {
		if (bulletTimer <= 0) {
			bulletTimer = bulletCooldown;
			canShoot = true;
		}
		else {
			bulletTimer -= delta;
		}
	}

	std::cout << "TIMER: " << delta << std::endl;
}

void Player::render(SDL_Renderer* renderer) {
	rect.x = (int)position.x;
	rect.y = (int)position.y;
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Texture* Player::getTexture() {
	return texture;
}

void Player::setTexture(SDL_Texture* newTexture) {
	texture = newTexture;
}

int Player::spawnBullet() {
	if (canShoot) {
		PlayerProjectile* newBullet = new PlayerProjectile(renderer, getBulletSpawnPoint(), &bullets);
		bullets.push_back(newBullet);
		canShoot = false;
	}
	return 0;
}

Vector2<double> Player::getBulletSpawnPoint() {
	Vector2<double> sp = position;
	sp.x += (width * scale.x) / 2;
	sp.y -= (height - 2) * scale.y;
	return sp;
}