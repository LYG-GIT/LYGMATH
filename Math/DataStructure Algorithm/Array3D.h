#pragma once

namespace LygLib
{
	template <class T>
	class Array3D
	{
	public:
		Array3D();
		Array3D(int width, int height, int depth);
		~Array3D();

		T& get(int x, int y, int z);
		void resize(int width, int height, int depth);
		int getSize();
		int getWidth();
		int getHeight();
		int getDepth();

	private:
		T* array;
		int width;
		int height;
		int depth;
	};

	template <class T>
	Array3D<T>::Array3D()
	{
		array = nullptr;
		width = 0;
		height = 0;
		depth = 0;
	}

	template <class T>
	Array3D<T>::Array3D(int width, int height, int depth)
	{
		array = new T[width * height * depth];
		this->width = width;
		this->height = height;
		this->depth = depth;
	}

	template <class T>
	Array3D<T>::~Array3D()
	{
		if (array != nullptr)
		{
			delete[] array;
		}
		array = nullptr;
	}

	template <class T>
	T& Array3D<T>::get(int x, int y, int z)
	{
		return array[z * width * height + y * width + x];
	}

	template <class T>
	void Array3D<T>::resize(int width, int height, int depth)
	{
		T* newArray = new T[width * height * depth];
		if (newArray == nullptr)
		{
			return
		}

		int minx = width < this->width ? width : this->width;
		int miny = height < this->height ? height : this->height;
		int minz = depth < this->depth ? depth : this->depth;

		for (int z = 0; z < minz; z++)
		{
			int t1 = z * width * height;
			int t2 = z * this->width * this->height;
			for (int y = 0; y < miny; y++)
			{
				int t3 = y * width;
				int t4 = y * this->width;
				for (int x = 0; x < minx; x++)
				{
					newArray[t1 + t3 + x] = array[t2 + t4 + x];
				}
			}
		}

		if (array != nullptr)
		{
			delete[] array;
		}

		array = newArray;
		this->width = width;
		this->height = height;
		this->depth = depth;
	}

	template <class T>
	int Array3D<T>::getSize()
	{
		return width * height * depth;
	}

	template <class T>
	int Array3D<T>::getWidth()
	{
		return width;
	}

	template <class T>
	int Array3D<T>::getHeight()
	{
		return height;
	}

	template <class T>
	int Array3D<T>::getDepth()
	{
		return depth;
	}
}


