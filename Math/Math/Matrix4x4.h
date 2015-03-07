#pragma once

#include <iostream>
#include "Vector4.h"
namespace LygMath
{
	class Matrix4x4
	{
	public:
		Matrix4x4();
		~Matrix4x4();
		Matrix4x4(
			Real m00,Real m01,Real m02,Real m03,
			Real m10,Real m11,Real m12,Real m13,
			Real m20,Real m21,Real m22,Real m23,
			Real m30,Real m31,Real m32,Real m33);
		Matrix4x4(const Matrix4x4& pMatrex4x4);
		Vector4 operator * (const Vector4& pVector);
		friend Matrix4x4 operator * (const Matrix4x4& pM1,const Matrix4x4& pM2);
		friend Vector4 operator*(const Vector4& pV,const Matrix4x4& pM);
		friend Vector4 operator*=(Vector4& pV,const Matrix4x4& pM);

		void transposition();
		friend std::ostream& operator<<(std::ostream& os, Matrix4x4& m);


	public:
		Real m[4][4];

	//static const Matrix4x4 IDENTITY;
	};

	
}
