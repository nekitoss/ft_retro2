
#pragma once

#include "Enemy.hpp"

class Star : public Entity {
	Star();
	Star(Star const &src);
	~Star();

	Star &operator=(Star const &rhs);
};
