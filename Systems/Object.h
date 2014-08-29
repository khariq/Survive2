#pragma once

#include "Position.h"

namespace Survive {

	class Object
	{
	protected:
		Position* _position;
	public:
		Object();
		virtual ~Object();

		void SetPosition(int x, int y);
		void SetPosition(const Position& position);
		void SetPosition(const Position* position);

		const Position& GetPosition() const;
	};

}