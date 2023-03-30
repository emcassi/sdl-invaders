#include "Projectile.h"

void Projectile::update(double delta) {
	position.x += velocity.x * delta;
	position.y += velocity.y * delta;
}