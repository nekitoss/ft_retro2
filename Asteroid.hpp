
#pragma once

#include "Entity.hpp"

class Asteroid : public Entity {
public:
	Asteroid();
	Asteroid(int x, int y);
	Asteroid(Asteroid const &src);
	~Asteroid();

	Asteroid &operator=(Asteroid const &rhs);
};
