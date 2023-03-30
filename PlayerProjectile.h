#pragma once
#include "Projectile.h"
class PlayerProjectile :
    public Projectile
{
public:
    PlayerProjectile(SDL_Renderer* renderer, Vector2<double> position);
    ~PlayerProjectile();

    void update(double delta);
    void render(SDL_Renderer* renderer);
};

