
#pragma once

#include "Entity.hpp"

class Enemy : public Entity {
public:
	Enemy();
	Enemy(int x, int y, float speed, std::string &type);
	Enemy(Enemy const &src);
	~Enemy();

	Enemy &operator=(Enemy const &rhs);
protected:
};
