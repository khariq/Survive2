#include <iostream>

#include "../Systems/Position.h"

int main(int argc, char** argv)
{

	Survive::Position shooter(0, 0);

	while (true) {

		int x, y;
		std::cout << "X:";
		std::cin >> x;
		std::cout << "Y:";
		std::cin >> y;
		if (x == 0 && y == 0)
			break;

		Survive::Position target(x, y);

		std::cout << shooter.RangeTo(target) << std::endl;

	}
	
	return 1;
}