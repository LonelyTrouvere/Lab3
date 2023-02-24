#pragma once
#include"List.h"
#include"LinkedList.h"
#include"ArrayList.h"
class Figure
{
private:
	ArrayList<std::pair<int, int>> points;
public:
	Figure(ArrayList<std::pair<int, int>> list);
	Figure(LinkedList<std::pair<int, int>> list);
	void Add(std::pair<int, int> point);
	void Add(int x, int y);
};


