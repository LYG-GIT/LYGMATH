#include "HeaderFileCompress.h"


HeaderFileCompress::HeaderFileCompress()
{
	
}

HeaderFileCompress::HeaderFileCompress(const std::string& filePath)
{
	fin.open(filePath);
	fout.open(filePath + ".txt");
}

HeaderFileCompress::~HeaderFileCompress()
{
	fout.close();
	fin.close();
}

int HeaderFileCompress::open(const std::string& filePath)
{
	fin.close();
	fout.close();
	fin.open(filePath);
	fout.open(filePath + ".txt");
	return 0;
}


void HeaderFileCompress::print()
{
	fin.seekg(0);
	char ch;
	while (!fin.eof())
	{
		ch = fin.get();
		std::cout << ch;
	}
	fin.clear();
}

void HeaderFileCompress::compress()
{
	fin.seekg(0);
	fout.seekp(0);
	char ch ;
 	int quatation = 0;
	int annotation = 0;
 	while (!fin.eof())
	{
		ch = fin.get();
		switch (ch)
		{
		case '/':
			if (quatation == 0)
			{
				if (annotation == 0)
				{
					if (fin.peek() == '/')
					{
						annotation = 1;
					}
					if (fin.peek() == '*')
					{
						annotation = 2;
					}
				}
				else if (annotation == -1)
				{
					annotation = 0;
				}
			}
			else
			{
				fout << ch;
			}
			
			break;
		case '*':
			if ((annotation == 2) && (fin.peek() == '/'))
			{
				annotation = -1;
			}
			else if (annotation == 0)
				fout << ch;
			break;

		case '\n':
			if ((quatation == 0) && (annotation == 0))
			{
				if (fin.peek() != '\n')
				{
					fout << ch;
				}
			}
			else if (quatation == 1)
			{
				fout << ch;
			}
			else if (annotation == 1)
			{
				annotation = 0;
			}
			break;
		case ' ':
			if ((quatation == 0) && (annotation == 0))
			{
				if (fin.peek() != ' ')
				{
					fout << ch;
				}
			}
			else if (quatation == 1)
			{
				fout << ch;
			}
			break;
		case '\"':
			if (annotation == 0)
			{
				fout << ch;
				if (quatation == 0)
					quatation = 1;
				else
					quatation = 0;
			}
			break;


		default:
			if (annotation == 0)
			{
				fout << ch;
			}
			break;

		}

		
	}

	fin.clear();
	fout.clear();
}