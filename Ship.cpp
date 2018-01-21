
#include "Ship.hpp"

Ship::Ship() {
	this->_alive = true;
}

Ship::Ship(int x, int y, std::string type) {
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_alive = true;
}

Ship::Ship(Ship const &src) {
	*this = src;
}

Ship::~Ship() {

}

void Ship::shoot() {
	this->bullet.setX(this->_posX + 1);
	this->bullet.setY(this->_posY);
	this->bullet.setSpeed(1.f);
}

 Ship &Ship::operator=(Ship const &rhs) {
	 this->_posX = rhs.getX();
	 this->_posY = rhs.getY();
	 this->_type = rhs.getType();
	 return *this;
}