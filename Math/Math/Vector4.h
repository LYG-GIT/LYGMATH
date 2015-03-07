#pragma once

#include <cmath>

#include "Common.h"

namespace LygMath
{
	class Vector4
	{
	public:
		Real x,y,z,w;

	public:
		inline Vector4():
			x(0),y(0),z(0),w(0)
		{

		}

		inline Vector4(const Real& xp,const Real& yp,const Real& zp,const Real &wp)
			:x(xp),y(yp),z(zp),w(wp)
		{
		}

		inline Vector4(const Vector4& v):
			x(v.x),
			y(v.y),
			z(v.z),
			w(v.w)
		{
		}

		inline Vector4& operator = (const Vector4& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;

			return *this;
		}
		

		~Vector4();

		inline bool operator == (const Vector4& v) const
		{
			 return((x == v.x) && 
				(y == v.y) && 
				(z == v.z) && 
				(w == v.w));
		}

		inline bool operator != (const Vector4& v) const
		{
			return !((*this) == v);
		}

		inline Vector4 operator + (const Vector4& v) const
		{
			return Vector4(
				x + v.x,
				y + v.y,
				z + v.z,
				w + v.w);
		}

		inline Vector4 operator - (const Vector4& v) const
		{
			return Vector4(
				x - v.x,
				y - v.y,
				z - v.z,
				w - v.w);
		}
		
		inline Vector4 operator * (const Real scalar) const
		{
			return Vector4(
				x * scalar,
				y * scalar,
				z * scalar,
				w * scalar);
		}

		inline Vector4 operator * (const Vector4& v) const
		{
			return Vector4(
				x * v.x,
				y * v.y,
				z * v.z,
				w * v.w);
		}

		inline const Vector4& operator + () const
		{
		     return *this;
		}
		
		inline Vector4 operator - () const
		{
		    return Vector4(-x, -y, -z, -w);
		}

		inline Real dotProduct(const Vector4& v)
		{
			return x * v.x + y * v.y + z * v.z + w * v.w;
		}

		inline Vector4 crossProduct(const Vector4& v)
		{
			return Vector4(
				y*v.z-z*v.y,
				z*v.x-x*v.z,
				x*v.y-y*v.x,
				0);
		}

		void normalize()
		{
			Real invm = 1.0/sqrt(x*x + y*y + z*z + w*w);
			x *= invm;
			y *= invm;
			z *= invm;
			w *= invm;
		}

		Real length()
		{
			return sqrt(x*x + y*y + z*z);
		}
/*
		
		
		Real angleBetween();
		Vector3 perpendicular();
		Vector3 prejection();
		*/



	};


}