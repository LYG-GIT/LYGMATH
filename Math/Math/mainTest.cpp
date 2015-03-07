#include <iostream>
#include "LygMath.h"

int main()
{
	using namespace LygMath;
	Vector2 v(3, 4);
	Vector2 v1(3, 2);
	std::cout << (v != v1);
	
	std::cin.get();
}