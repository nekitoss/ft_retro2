
#pragma once

#include "Entity.hpp"

class Bullet : public Entity {
public:
	Bullet();
	Bullet(int x, int y, float spd, std::string type);
	Bullet(Bullet const &src);
	~Bullet();

	Bullet &operator=(Bullet const &rhs);
};
