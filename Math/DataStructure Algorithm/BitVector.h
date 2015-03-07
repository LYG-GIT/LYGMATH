#pragma once

#include <string>

namespace LygLib
{
	class BitVector
	{
	public:
		BitVector();
		BitVector(int size);
		~BitVector();

		void resize(int size);
		bool operator[](int index);
		void set(int index, bool value);
		void setAll();
		void clear();
		bool writeToFile(const std::string& fileName);
		bool readFromFile(const std::string& fileName);

	protected:
		unsigned __int32* _array;
		int _size;
	};
}

