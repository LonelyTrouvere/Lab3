#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Figure.h"

int main()
{

	ArrayList<int> list;
	double a[] = { 5.1, 4.9, 4.7, 4.6, 5.0, 5.4, 4.6, 5.0, 4.4, 4.9, 5.4, 4.8, 4.8, 4.3, 5.8, 5.7, 5.4, 5.1, 5.7, 5.1};

	for (int i = 0; i < 20; i++)
		list.Push_back(a[i]);

	list.MergeSort();

	int i = 0;
	for ( i = 0; i < list.Size(); i++)
		std::cout << list[i] << ' ';

	for (int i = 0; i < list.Size()-1; i++)
	{
		if (list[i] > list[i + 1])
		{
			std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			break;
		}
	}
}

