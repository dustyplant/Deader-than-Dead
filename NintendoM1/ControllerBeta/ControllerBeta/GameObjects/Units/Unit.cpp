#include "Unit.h"

Unit::Unit(int xPosInit , int yPosInit , int widthCollision , int heightCollision, 
	int numSheetColumns , int numSheetRows , int frameWidth , int frameHeight , SDL_Surface * spriteSheet) 
		: GameObject(xPosInit, yPosInit, widthCollision, heightCollision, 
		(int)abs((widthCollision-frameWidth)/2), (int)abs((heightCollision-frameHeight)/2))
{
	this->sprite.init(numSheetColumns, numSheetRows, frameWidth, frameHeight, spriteSheet);
}

Unit::~Unit() {}

void Unit::update(Uint32 timeElapsedMs){/*Please override*/}

void Unit::draw(SDL_Surface *destination, int xOffset, int yOffset)
{
	this->sprite.draw(this->pos.x - xOffset, this->pos.y - yOffset, destination);
}

void Unit::checkCollisionWith(GameObject * otherObject){/*Please override*/}

void Unit::setPosition(int xPosNew, int yPosNew)
{
	Unit::setBoxPosition(xPosNew,yPosNew);
}

void Unit::moveBy(int xMoveBy, int yMoveBy)
{
	Unit::moveBox(xMoveBy,yMoveBy);
}

void Unit::saveCurPosToOldPos()
{
	this->xPosOld = collisionBox.x;
	this->yPosOld = collisionBox.y;
}

bool Unit::stayedInSamePosition()
{
	return xPosOld == collisionBox.x && yPosOld == collisionBox.y;
}

//Getters; a method of making attributes read-only.
int Unit::getXPos() const {return this->collisionBox.x;}
int Unit::getYPos() const {return this->collisionBox.y;}