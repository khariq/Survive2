#pragma once
#include "Object.h"

namespace Survive {

	class MobileObject : public Object
	{
	protected:

	public:
		MobileObject();
		~MobileObject();

		void MoveTo(int x, int y);
		void MoveTo(const Position& destination);
		void MoveTo(const Position const* destination);

	};

}