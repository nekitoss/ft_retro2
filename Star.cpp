
#include "Star.hpp"

Star::Star() {

}

Star::Star(Star const &src) {
	*this = src;
}

Star::~Star() {

}

Star& Star::operator=(Star const &rhs) {
	this->_posX = rhs.getX();
	this->_posY = rhs.getY();
	return *this;
}