
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
void Entity::setType(std::string type) { this->_type = type; }
void Entity::setMaxX(int n) { this->_maxX = n; }
void Entity::setMaxY(int n) { this->_maxY = n; }
void Entity::setDist(float f) { this->_dist = f; }

int Entity::getX() const { return this->_posX; };
int Entity::getY() const { return this->_posY; };
float Entity::getSpeed() const { return this->_speed; }
float Entity::getDist() const { return this->_dist; }
std::string Entity::getType() const { return this->_type; };
int Entity::getMaxX() const { return this->_maxX; }
int Entity::getMaxY() const { return this->_maxY; }

void Entity::moveUp() {
	if (this->_posY > 0)
		this->_posY--;
}

void Entity::moveDown() {
	if (this->_posY < this->_maxY)
		this->_posY++;
}

void Entity::moveLeft() {
	if (this->_posX > 0)
		this->_posX--;
}

void Entity::moveRight() {
	if (this->_posX < this->_maxX)
		this->_posX++;
}

void Entity::travel() {
	if (this->_dist > 1)
		this->_dist -= 1;
	this->_dist += this->_speed;

}
Entity & Entity::operator=(Entity const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	this->_type = rhs.getType();
	return *this;
}
