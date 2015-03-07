#include "Common.h"

namespace LygMath
{
	void swap(Real& f1, Real& f2)
	{
		Real t;
		t = f1;
		f1 = f2;
		f2 = t;
	}

	bool approachToZero(Real real)
	{
		if (real < 0)
		{
			real = -real;
		}
		return (real < 1e-8);		
	}
}