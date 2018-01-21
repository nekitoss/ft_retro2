
#pragma once

#include "Entity.hpp"

class Bullet : public Entity {
public:
	Bullet();
	Bullet(int x, int y, float spd, std::string type);
	Bullet(Bullet const &src);
	~Bullet();

	void moveLeft();
	void moveRight();
	Bullet &operator=(Bullet const &rhs);
};
