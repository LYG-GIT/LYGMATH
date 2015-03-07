#pragma once

#include <iostream>

#include "Common.h"

namespace LygMath
{
	class Vector3
	{
	public:
		Vector3();
		~Vector3();


		friend std::ostream& operator<<(std::ostream& os, Vector3& v)
		{
			os << "[" << v.x << "," << v.y << "," << v.z << "]";
			return os;
		}
	public:
		Real x;
		Real y;
		Real z;
	};
}

