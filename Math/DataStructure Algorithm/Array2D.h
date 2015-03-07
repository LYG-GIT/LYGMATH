#pragma once


namespace LygLib
{
	template <class T>
	class Array2D
	{
	public:
		Array2D();
		Array2D(int width, int height);
		~Array2D();

		T& get(int x, int y);
		void resize(int width, int height);
		int getWidth();
		int getHeight();
		int getSize();
	private:
		T* array;
		int width;
		int height;
	};

	template <class T>
	Array2D<T>::Array2D()
	{
		array = nullptr;
	}

	template <class T>
	Array2D<T>::Array2D(int width, int height)
	{
		array = new T[width * height];
		this->width = width;
		this->height = height;t
	}

	template <class T>
	Array2D<T>::~Array2D()
	{
		if (array != nullptr)
		{
			delete[] array;
		}
		array = nullptr;
	}

	template <class T>
	T& Array2D<T>::get(int x, int y)
	{
		return array[y * width + x];
	}

	template <class T>
	void Array2D<T>::resize(int width, int height)
	{
		T* newArray = new T[width * height];
		if (newArray == nullptr)
		{
			return;
		}

		int minx = width < this.width ? width : this->width;
		int miny = height < this.height ? height : this->height;

		for (int y = 0; y < miny; y++)
		{
			int t1 = y * width;
			int t2 = y * this->width;
			for (int x = 0; x < minx; x++)
			{
				newArray[t1 + x] = array[t2 + x];
			}
		}

		if (array != nullptr)
		{
			delete[] array;
		}

		array = newArray;
		this->width = width;
		this->height = height;
	}

	template <class T>
	int Array2D<T>::getWidth()
	{
		return width;
	}

	template <class T>
	int Array2D<T>::getHeight()
	{
		return height();
	}

	template <class T>
	int Array2D<T>::getSize()
	{
		return width * height;
	}
}

