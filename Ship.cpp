
#include "Ship.hpp"

Ship::Ship() {
	this->_alive = true;
	this->_lives = 3;
	this->bullet.setSpeed(0.15f);
	this->_score = 0;
	this->_type = "C";
	this->_posY = 1;
}

Ship::Ship(int x, int y, std::string type) {
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_alive = true;
	this->_lives = 3;
	this->bullet.setSpeed(0.15f);
	this->_score = 0;
}

Ship::Ship(Ship const &src) {
	*this = src;
}

Ship::~Ship() {

}

int Ship::getLives() { return this->_lives; }
int Ship::getScore() { return this->_score; }

void Ship::damage() {
	this->_lives--;
}

void Ship::kill() {
	if (this->_lives > 0)
		this->_score++;
}

void Ship::shoot() {
	if (this->bullet.getX() >= this->_maxX + 10)
	{
		this->bullet.setX(this->_posX + 1);
		this->bullet.setY(this->_posY + 1);
	}
}

 Ship &Ship::operator=(Ship const &rhs) {
	 this->_posX = rhs.getX();
	 this->_posY = rhs.getY();
	 this->_type = rhs.getType();
	 return *this;
}
