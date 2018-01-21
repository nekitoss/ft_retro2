
#pragma once
#include "Entity.hpp"
#include "Bullet.hpp"

class Ship : public Entity {
public:
	Ship();
	Ship(int x, int y, std::string type);
	Ship(Ship const &src);
	~Ship();

	Ship &operator=(Ship const &rhs);
	Bullet bullet;
	void shoot();
protected:
	int _hp;
private:
	int _lives;
};
