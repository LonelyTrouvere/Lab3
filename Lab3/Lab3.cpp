#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Figure.h"

int main()
{

	Figure f;

	f.Add(0, 0);
	f.Add(2,2);
	f.Add(7, 2);
	f.Add(7, 0);

	std::cout << f.TrapezeType();
}

