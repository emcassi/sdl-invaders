#pragma once
#include "Projectile.h"

class PlayerProjectile :
    public Projectile
{
public:
    std::vector<PlayerProjectile*>* bullets;
   
    PlayerProjectile(SDL_Renderer* renderer, Vector2<double> position, std::vector<PlayerProjectile*>* bullets);
    ~PlayerProjectile();

    virtual void update(double delta);
    virtual void render(SDL_Renderer* renderer);
};

