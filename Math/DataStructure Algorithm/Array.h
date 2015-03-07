#pragma once

#include <string>

namespace LygLib
{
	template<class T>
	class Array
	{
	public:
		Array();
		Array(int size);
		~Array();
		
		operator T*();

		T& operator[](int index);

		int getSize();
		void resize(int size);
		void insert(T item, int index);
		void remove(int index);
		bool writeToFile(const std::string& fileName);
		bool readFromFile(const std::string& fileName);

	private:
		T* array;
		int size;
	};



	template<class T>
	Array<T>::Array()
	{
		array = nullptr;
	}

	template<class T>
	Array<T>::Array(int size)
	{
		array = new T[10];
		this->size = size;
	}

	template<class T>
	Array<T>::~Array()
	{
		if (array != nullptr)
		{
			delete[] array;
		}
		array = nullptr;
	}

	template<class T>
	Array<T>::operator T*()
	{
		return array;
	}

	template<class T>
	T& Array<T>::operator[](int index)
	{
		return array[index];
	}

	template<class T>
	int Array<T>::getSize()
	{
		return size;
	}

	template<class T>
	void Array<T>::resize(int size)
	{
		T* newArray = new T[size];
		if (newArray == nullptr)
		{
			return;
		}

		int minSize;
		if (this->size > size)
		{
			minSize = size;
		}
		else
		{
			minSize = this->size;
		}

		for (int i = 0; i < minSize; i++)
		{
			newArray[i] = array[i];
		}
		this->size = size;

		if (array != nullptr)
		{
			delete [] array;
		}
		array = newArray;
	}

	template<class T>
	void Array<T>::insert(T item, int index)
	{
		for (int i = size - 1; i > index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = item;
	}

	template<class T>
	void Array<T>::remove(int index)
	{
		for (int i = index + 1; i < size; i++)
		{
			array[i - 1] = array[i];
		}
	}

	template<class T>
	bool Array<T>::writeToFile(const std::string& fileName)
	{

	}

	template<class T>
	bool Array<T>::readFromFile(const std::string& fileName)
	{

	}
}


