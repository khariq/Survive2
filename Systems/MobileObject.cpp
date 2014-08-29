#include "MobileObject.h"

using namespace Survive;

MobileObject::MobileObject()
{
}


MobileObject::~MobileObject()
{
}

void MobileObject::MoveTo(int x, int y)
{
	SetPosition(x, y);
}

void MobileObject::MoveTo(const Position& destination)
{
	SetPosition(destination);
}

void MobileObject::MoveTo(const Position const* destination)
{
	SetPosition(destination);
}



