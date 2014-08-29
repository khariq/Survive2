#include "Position.h"
#include <math.h>

using namespace Survive;

Position::Position()
{
}

Position::Position(int x, int y) : _position(x, y)
{

}

Position::Position(Point2D& position) : _position(position)
{

}

Position::~Position()
{
}

int Position::RangeTo(const Position& target)
{

	if (target._position.GetX() - _position.GetX() ==
		target._position.GetY() - _position.GetY())
	{
		return target._position.GetY() - _position.GetY();
	}

	return (int)sqrt(pow((double)target._position.GetX() - _position.GetX(), 2) + 
					 pow((double)target._position.GetY() - _position.GetY(), 2));
	
}

int Position::GetX() const 
{
	return _position.GetX();
}

int Position::GetY() const
{
	return _position.GetY();
}