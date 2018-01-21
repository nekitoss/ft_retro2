
#pragma once

#include "Entity.hpp"
#include "Bullet.hpp"

class Enemy : public Entity {
public:
	Enemy();
	Enemy(int x, int y, float speed, std::string type);
	Enemy(Enemy const &src);
	~Enemy();

	Bullet bullet;
	void shoot();
	void moveLeft();
	Enemy &operator=(Enemy const &rhs);
protected:
};
