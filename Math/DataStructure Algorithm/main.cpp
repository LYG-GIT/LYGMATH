#include <iostream>
#include "LygLib.h"
#include "HeaderFileCompress.h"

int main()
{
	using namespace std;
	using namespace LygLib;
	Array<int> a;
	Array2D<int> b;
	BitVector c;
	SLinkedLists<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.push_front(4);
	list.push_front(5);
	list.pop_front();

	list.pop_back();


	SLinkedLists<int>::iterator iter1 = list.last();
	SLinkedLists<int>::iterator iter2 = list.insert(iter1, 6);

	iter1 = list.begin();
	iter1++;
	iter1 = list.erase(iter1);

	for (SLinkedLists<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << *iter1 << endl;
	cout << list.length << endl;
	cin.get();
	return 0;
}