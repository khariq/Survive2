#include "Point2D.h"

using namespace Survive;


Point2D::Point2D() : _x(0), _y(0)
{
}

Point2D::Point2D(int x, int y) : _x(x), _y(y)
{
	
}

Point2D::Point2D(const Point2D& rhs) : _x(rhs._x), _y(rhs._y)
{
	
}

Point2D::~Point2D()
{
}
