
#include "Bullet.hpp"

Bullet::Bullet() {

}

Bullet::Bullet(int x, int y, float spd, std::string type) {
	this->_posX = x;
	this->_posY = y;
	this->_speed = spd;
	this->_type = type;
}

Bullet::Bullet(Bullet const &src) {
	*this = src;
}

Bullet::~Bullet() {

}

Bullet &Bullet::operator=(Bullet const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_speed = rhs.getSpeed();
	this->_type = rhs.getType();
	return *this;
}
