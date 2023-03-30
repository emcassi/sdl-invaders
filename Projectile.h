#include <SDL.h>
#include "Vector2.h"

#pragma once
class Projectile
{
protected:
	int width, height;
public:
	SDL_Rect rect;
	SDL_Texture* texture;
	Vector2<double> position = Vector2<double>(0, 0);
	Vector2<double> velocity = Vector2<double>(0, 0);
	Vector2<double> scale = Vector2<double>(5, 5);

	virtual void update(double delta);
	virtual void render(SDL_Renderer* renderer);
};

