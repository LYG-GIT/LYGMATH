#include "BitVector.h"

namespace LygLib
{
	BitVector::BitVector()
	{
		_array = nullptr;
		_size = 0;

	}

	BitVector::BitVector(int size)
	{
		_array = nullptr;
		_size = size;
		resize(size);
	}

	BitVector::~BitVector()
	{
		if (_array != nullptr)
		{
			delete[] _array;
			_array = nullptr;
		}
	}

	void BitVector::resize(int size)
	{
		unsigned __int32* newArray = 0;
		if (size % 32 == 0)
		{
			size = size / 32;
		}
		else
		{
			size = (size / 32) + 1;
		}
		newArray = new unsigned __int32[size];
		if (newArray == 0)
		{
			return;
		}

		int min;
		if (size < _size)
		{
			min = size;
		}
		else
		{
			min = _size;
		}

		for (int index = 0; index < min; index++)
		{
			newArray[index] = _array[index];
		}
		_size = size;
		if (_array != 0)
		{
			delete [] _array;
		}
		_array = newArray;
	}

	bool BitVector::operator[](int index)
	{
		int cell = index / 32;
		int bit = index % 32;
		return (_array[cell] & (1 << bit)) >> bit;
	}

	void BitVector::set(int index, bool value)
	{
		int cell = index / 32;
		int bit = index % 32;
		if (value == true)
		{
			_array[cell] = (_array[cell] | (1 << bit));
		}
		else
		{
			_array[cell] = (_array[cell] & (~(1 << bit)));
		}
	}

	void BitVector::clear()
	{
		for (int index = 0; index < _size; index++)
		{
			_array[index] = 0;
		}
	}

	void BitVector::setAll()
	{
		for (int index = 0; index < _size; index++)
		{
			_array[index] = 0xFFFFFFFF;
		}
	}

	bool BitVector::writeToFile(const std::string& fileName)
	{


		return true;
	}

	bool BitVector::readFromFile(const std::string& fileName)
	{


		return true;
	}
}


