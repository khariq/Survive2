#pragma once

namespace Survive {

	class Point2D
	{
	public:
		Point2D();
		Point2D(int x, int y);
		Point2D(const Point2D& rhs);
		~Point2D();

		int GetX() const { return _x; }
		int GetY() const { return _y; }

	private:
		int _x;
		int _y;
	};

}