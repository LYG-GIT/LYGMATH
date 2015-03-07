#pragma once

#include <iostream>

#include "Common.h"

namespace LygMath
{
	class Vector2
	{
	public:
		inline Vector2() :
			x(0), y(0)
		{
		}

		inline Vector2(const Real x, const Real y):
			x(x), y(y)
		{			
		}

		inline Vector2(const Vector2& v)
		{
			x = v.x;
			y = v.y;
		}

		inline Vector2& operator = (const Vector2& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}

		inline Vector2& operator = (const Real scalar)
		{
			x = scalar;
			y = scalar;
			return *this;
		}
		
		inline const Vector2 operator + () const
		{
			return *this;
		}

		inline Vector2 operator + (const Real scalar) const
		{
			return Vector2(x + scalar, y + scalar);
		}

		inline Vector2 operator + (const Vector2& v) const
		{
			return Vector2(x + v.x, y + v.y);
		}

		inline Vector2 operator += (const Real scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		inline Vector2 operator += (const Vector2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		inline Vector2 operator - () const 
		{
			return Vector2(-x, -y);
		}

		inline Vector2 operator - (Real scalar) const
		{
			return Vector2(x - scalar, y - scalar);
		}

		inline Vector2 operator - (const Vector2& v) const
		{
			return Vector2(x - v.x, y - v.y);
		}

		inline Vector2 operator -= (const Real scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		inline Vector2 operator -= (const Vector2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}

		inline Vector2 operator * (const Real scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}

		inline Vector2 operator * (const Vector2& v) const
		{
			return Vector2(x * v.x, y * v.y);
		}

		inline friend Vector2 operator * (const Real scalar, const Vector2& v)
		{
			return Vector2(scalar * v.x, scalar * v.y);
		}

		inline Vector2 operator *= (const Real scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		inline Vector2 operator *= (const Vector2& v)
		{
			x *= v.x;
			y *= v.y;
			return *this;
		}

		inline Vector2 operator / (const Real scalar) const 
		{
			return approachToZero(scalar) ? (*this) : Vector2(x / scalar, y / scalar);
		}

		inline Vector2 operator / (const Vector2& v) const
		{
			return Vector2(x / v.x, y / v.y);
		}

		inline Vector2 operator /= (const Real scalar)
		{
			if (!approachToZero(scalar))
			{
				x /= scalar;
				y /= scalar;
			}
			return *this;
		}

		inline Vector2 operator /= (const Vector2& v)
		{
			x /= v.x;
			y /= v.y;
			return *this;
		}

		inline bool operator == (const Vector2& v) const
		{
			return ( x == v.x && y == v.y );
		}

		inline bool operator != (const Vector2& v) const
		{
			return (x != v.x || y != v.y);
		}

		inline Real length() const
		{
			return sqrt( x * x + y * y );
		}

		inline Real squaredLength() const
		{
			return x * x + y * y;
		}

		inline Real distance(const Vector2& v) const 
		{
			return (*this - v).length();
		}

		inline Real dotProduct(const Vector2& v) const
		{
			return x * v.x + y * v.y;
		}

		inline Real normalize()
		{
			Real length = sqrt(x * x + y * y);
			if (!approachToZero(length))
			{
				Real fInvLength = 1.0f / length;
				x *= fInvLength;
				y *= fInvLength;
			}
			return length;
		}

		inline Vector2 midPoint(const Vector2& v) const
		{
			return Vector2((x + v.x) * 0.5f, (y + v.y) * 0.5f);
		}

		inline Vector2 perpendicular() const
		{
			return Vector2(-y, x);
		}

		inline Real crossProduct(const Vector2& v) const
		{
			return x * v.y - y * v.x;
		}

		inline Vector2 reflect(const Vector2& normal) const
		{
			return Vector2(*this - (2 * this->dotProduct(normal) * normal));
		}

		friend std::ostream& operator<<(std::ostream& os, Vector2& v)
		{
			os << "[" << v.x << "," << v.y << "]";
			return os;
		}

	public:
		Real x;
		Real y;
	};
}

