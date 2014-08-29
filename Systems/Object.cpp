#include "Object.h"
#include "NullRefException.h"

using namespace Survive;

Object::Object() 
{
	_position = NULL;
}


Object::~Object()
{
	if (_position != NULL)
	{
		delete _position;
		_position = NULL;
	}

}

void Object::SetPosition(int x, int y)
{
	if (_position != NULL)
	{
		delete _position;
	}

	_position = new Survive::Position(x, y);
	
}

void Object::SetPosition(const Position& position)
{
	if (_position != NULL)
	{
		delete _position;
	}

	_position = new Survive::Position(position);
}

void Object::SetPosition(const Position* position)
{
	if (_position != NULL)
	{
		delete _position;
	}

	_position = new Survive::Position(*position);
}

const Position& Object::GetPosition() const
{
	
	if (_position == NULL)
	{
		throw Survive::NullRefException("Position has not be set.");
	}
	

	if (_position != NULL)
	{
		return *_position;
	}

}
