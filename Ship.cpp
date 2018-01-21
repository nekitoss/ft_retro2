
#include "Ship.hpp"

Ship::Ship() {
	this->_alive = true;
	this->_lives = 3;
	this->bullet.setSpeed(0.15f);
	this->bullet.setX(250);
	this->_score = 0;
}

Ship::Ship(int x, int y, std::string type) {
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_alive = true;
	this->_lives = 3;
	this->bullet.setX(250);
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
	this->_score++;
}

void Ship::shoot() {
	if (this->bullet.getX() == 250)
	{
		this->bullet.setX(this->_posX + 1);
		this->bullet.setY(this->_posY);
	}
}

 Ship &Ship::operator=(Ship const &rhs) {
	 this->_posX = rhs.getX();
	 this->_posY = rhs.getY();
	 this->_type = rhs.getType();
	 return *this;
}
