#pragma once
#include <iostream>

class Entity {
public:
	Entity();
	Entity(int x, int y, std::string &type);
	Entity(Entity const &src);
	~Entity();

	void setX(int n);
	void setY(int n);
	void setSpeed(float f);
	int getX() const;
	int getY() const;
	float getSpeed() const;
	std::string getType() const;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	Entity &operator=(Entity const &rhs);
protected:
	int _posX;
	int _posY;
	std::string _type;
	float _speed;
	bool _alive;
};