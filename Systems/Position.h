#pragma once

#include "Point2D.h"

namespace Survive {

	class Position
	{
	public:
		Position();
		Position(int x, int y);
		Position(Point2D& position);

		~Position();

		int RangeTo(const Position& target);

		int GetX() const;
		int GetY() const;

	protected:
		Point2D _position;
	};

}