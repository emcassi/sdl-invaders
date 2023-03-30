#include <SDL_image.h>
#include "Macs.h"
#include "Vector2.h"
#include "PlayerProjectile.h"
#include <map>
#include <vector>

#pragma once
class Player
{
public:
	SDL_Rect rect;
	Vector2<double> position = { position.x = 0, position.y = 0 };
	Vector2<double> scale = { scale.x = 5, scale.y = 5 };
	double speed = 0.7f;
	std::vector<PlayerProjectile*> bullets;
private:
	SDL_Texture* texture;
	int width = 13, height = 8;
	SDL_Renderer* renderer;
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void update(double delta, std::map<int, int> keys);
	void render(SDL_Renderer* renderer);

	SDL_Texture* getTexture();
	void setTexture(SDL_Texture* newTexture);
	int spawnBullet();

private:
	Vector2<double> getBulletSpawnPoint();
};

