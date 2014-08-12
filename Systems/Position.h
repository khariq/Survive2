#pragma once

#include "Point2D.h"

namespace Survive {

	class Position
	{
	public:
		__declspec(dllexport) Position();
		__declspec(dllexport) Position(int x, int y);
		__declspec(dllexport) Position(Point2D& position);

		__declspec(dllexport) ~Position();

		__declspec(dllexport) int RangeTo(const Position& target);

	protected:
		Point2D _position;
	};

}