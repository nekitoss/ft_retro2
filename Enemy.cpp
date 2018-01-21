 
#include "Enemy.hpp"

Enemy::Enemy() {
	this->_alive = true;
	this->_speed = 0.01;
	this->bullet.setSpeed(0.005f);
	this->_dist = 0;
}

Enemy::Enemy(int x, int y, float speed, std::string type) {
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_speed = speed;
	this->_alive = true;
	this->bullet.setSpeed(0.05f);
	this->_dist = 0;
}

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

Enemy::~Enemy() {

}

void Enemy::moveLeft() {
	if (this->_posX < -10)
	{
		this->_posX = this->_maxX;
		this->_posY = rand() % (this->_maxY - 4) + 1;
	}
	else if (this->_dist >= 1)
		this->_posX--;
}

void Enemy::shoot() {
	if ((this->bullet.getX() < -100 || this->bullet.getX() == this->_maxX) && this->_posX > 0 && this->_posX < this->_maxX)
	{
		this->bullet.setX(this->_posX - 1);
		this->bullet.setY(this->_posY);
	}
}


Enemy & Enemy::operator=(Enemy const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_type = rhs.getType();
	this->_speed = rhs.getSpeed();
	return *this;
}
