#pragma once
#include <iostream>

class Entity {
public:
	Entity();
	Entity(int x, int y, std::string &type);
	Entity(Entity const &src);
	virtual ~Entity();

	void setX(int n);
	void setY(int n);
	void setSpeed(float f);
	void setType(std::string type);
	void setMaxX(int n);
	void setMaxY(int n);
	void setDist(float f);

	int getX() const;
	int getY() const;
	float getSpeed() const;
	std::string getType() const;
	float getDist() const;
	int getMaxX() const;
	int getMaxY() const;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void travel();
	Entity &operator=(Entity const &rhs);
protected:
	float _dist;
	int _posX;
	int _posY;
	std::string _type;
	float _speed;
	bool _alive;
	int _maxX;
	int _maxY;
};
