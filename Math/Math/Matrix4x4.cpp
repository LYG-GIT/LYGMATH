#include "Matrix4x4.h"
#include "Common.h"

namespace LygMath
{
	/*const Matrix4x4 Matrix4x4::IDENTITY(
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1);*/
	Matrix4x4::Matrix4x4() 
	{
		for (int i = 0; i < 16; i++)
		{
			m[16 / 4][16 % 4] = 0;
		}
	}

	Matrix4x4::Matrix4x4(Real m00,Real m01,Real m02,Real m03,
		Real m10,Real m11,Real m12,Real m13,
		Real m20,Real m21,Real m22,Real m23,
		Real m30,Real m31,Real m32,Real m33)
	{
		m[0][0] = m00;	m[0][1] = m01;	m[0][2] = m02;	m[0][3] = m03;
		m[1][0] = m10;	m[1][1] = m11;	m[1][2] = m12;	m[1][3] = m13;
		m[2][0] = m20;	m[2][1] = m21;	m[2][2] = m22;	m[2][3] = m23;
		m[3][0] = m30;	m[3][1] = m31;	m[3][2] = m32;	m[3][3] = m33;
	}


	Matrix4x4::Matrix4x4(const Matrix4x4& mat)
	{
		for (int i = 0;i<4;i++)
		{
			for (int j = 0;j<4;j++)
			{
				m[i][j] = mat.m[i][j];
			}
		}

	}

	Matrix4x4::~Matrix4x4(void)
	{
	}

	Vector4 Matrix4x4::operator*(const Vector4& v)
	{
		return Vector4(
			m[0][0]*v.x+m[0][1]*v.y+m[0][2]*v.z+m[0][3]*v.w,
			m[1][0]*v.x+m[1][1]*v.y+m[1][2]*v.z+m[1][3]*v.w,
			m[2][0]*v.x+m[2][1]*v.y+m[2][2]*v.z+m[2][3]*v.w,
			m[3][0]*v.x+m[3][1]*v.y+m[3][2]*v.z+m[3][3]*v.w);
	}

	Matrix4x4 operator*(const Matrix4x4& mat1, const Matrix4x4& mat2)
	{
		Matrix4x4 rmat;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rmat.m[i][j] = mat1.m[i][0] * mat2.m[0][j]+mat1.m[i][1] * mat2.m[1][j]+mat1.m[i][2] * mat2.m[2][j]+mat1.m[i][3] * mat2.m[3][j];
			}
		}
		return rmat;
	}

	Vector4 operator*(const Vector4& v,const Matrix4x4& mat)
	{
		return Vector4(
			v.x*mat.m[0][0]+v.y*mat.m[1][0]+v.z*mat.m[2][0]+v.w*mat.m[3][0],
			v.x*mat.m[0][1]+v.y*mat.m[1][1]+v.z*mat.m[2][1]+v.w*mat.m[3][1],
			v.x*mat.m[0][2]+v.y*mat.m[1][2]+v.z*mat.m[2][2]+v.w*mat.m[3][2],
			v.x*mat.m[0][3]+v.y*mat.m[1][3]+v.z*mat.m[2][3]+v.w*mat.m[3][3]
		);
	}

	Vector4 operator*=(Vector4& v,const Matrix4x4& m)
	{
		return v = (v * m);
	}

	void Matrix4x4::transposition()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = i; j < 4; j++)
			{
				swap(m[i][j],m[j][i]);
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, Matrix4x4& m)
	{
		for (int i = 0; i < 4;i++)
		{
			for (int j = 0; j < 4;j++)
			{
				os << m.m[i][j]<<"  \t";
			}
			os << std::endl;
		}	
		return os;
	}
	
}