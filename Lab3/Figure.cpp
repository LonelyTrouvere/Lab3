#include "Figure.h"
Figure::Figure(ArrayList<std::pair<int, int>> list)
{
	points = list;
}

Figure::Figure(LinkedList<std::pair<int, int>> list)
{
	for (int i = 0; i < list.Size(); i++)
		points.Push_back(list[i]);
}

void Figure::Add(std::pair<int, int> point)
{
	points.Push_back(point); 
}

void Figure::Add(int x, int y)
{
	points.Push_back({ x, y });
}
