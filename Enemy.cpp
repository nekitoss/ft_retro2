
#include "Enemy.hpp"

Enemy::Enemy() {
	this->_alive = true;
	this->_speed = 0.01;
}

Enemy::Enemy(int x, int y, float speed, std::string type) {
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

void Enemy::moveLeft() {
	if (this->_posX < -10)
	{
		this->_posX = 250;
		this->_posY = rand() % 66;
	}
	if (this->_dist >= 1)
		this->_posX--;
}

void Enemy::moveRight() {
	if (this->_dist >= 1)
		this->_posX++;
}

void Enemy::shoot() {
	this->bullet.setX(this->_posX - 1);
	this->bullet.setY(this->_posY);
	this->bullet.setSpeed(0.5f);
}

Enemy & Enemy::operator=(Enemy const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_type = rhs.getType();
	this->_speed = rhs.getSpeed();
	return *this;
}
