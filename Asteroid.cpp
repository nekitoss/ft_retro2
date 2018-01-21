
#include "Asteroid.hpp"

Asteroid::Asteroid() {
	this->_alive = true;
}

Asteroid::Asteroid(int x, int y) {
	this->_posX = x;
	this->_posY = y;
	this->_alive = true;
}

Asteroid::Asteroid(Asteroid const &src) {
	*this = src;
}

Asteroid::~Asteroid() {

}

Asteroid &Asteroid::operator=(Asteroid const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_speed = rhs.getSpeed();
	return *this;
}
