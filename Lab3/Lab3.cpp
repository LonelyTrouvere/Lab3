#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Figure.h"

int main()
{

	Figure f;

	f.Add(1, 1);
	f.Add(0, 1);
	f.Add(0, 0);
	f.Add(1, 0);

	std::cout << f.QuadrangleType();
}

