#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"

int main()
{

	LinkedList<int> list;
	list.Push_back(3);
	list.Push_back(5);

	for (int i = 0; i < list.Size(); i++)
		std::cout << list[i]+1 << ' ';

}

