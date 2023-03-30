#include "Projectile.h"

void Projectile::update(double delta) {
	position.x += velocity.x;
	position.y += velocity.y;
}