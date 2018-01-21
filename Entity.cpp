
#include "Entity.hpp"

Entity::Entity() {

}

Entity::Entity(int x, int y, std::string &type) : _posX(x), _posY(y), _type(type) {

}

Entity::Entity(Entity const &src) {
	*this = src;
}

Entity::~Entity() {

}

void Entity::setX(int n) { this->_posX = n; }
void Entity::setY(int n) { this->_posY = n; }
void Entity::setSpeed(float f) { this->_speed = f; }

int Entity::getX() const { return this->_posX; };
int Entity::getY() const { return this->_posY; };
float Entity::getSpeed() const { return this->_speed; }
std::string Entity::getType() const { return this->_type; };


void Entity::moveUp() { this->_posY++; }
void Entity::moveDown() { this->_posY--; }
void Entity::moveLeft() { this->_posX--; }
void Entity::moveRight() { this->_posX++; }

Entity & Entity::operator=(Entity const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_type = rhs.getType();
	return *this;
}
