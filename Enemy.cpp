
#include "Enemy.hpp"

Enemy::Enemy() {
	this->_alive = true;
}

Enemy::Enemy(int x, int y, float speed, std::string &type) {
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_speed = speed;
	this->_alive = true;
}

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

Enemy::~Enemy() {

}

Enemy & Enemy::operator=(Enemy const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_type = rhs.getType();
	this->_speed = rhs.getSpeed();
	return *this;
}
