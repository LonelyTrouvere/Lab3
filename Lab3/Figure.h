#pragma once
#include"List.h"
#include"LinkedList.h"
#include"ArrayList.h"
class Figure
{
private:
	ArrayList<std::pair<double, double>> points;
public:
	Figure(ArrayList<std::pair<double, double>> list);
	Figure(LinkedList<std::pair<double, double>> list); 

	enum TriangleSideType {
		ORDINARY,
		ISOSCELES,
		EQUILATERAL
	};

	enum TriangleAngleType {
		ACUTE,
		OBTUSE,
		RECTANGULAR
	};

	enum QuadrangleType {
		SQUARE,

	};

	std::pair<double, double>& operator[](int i);
	void Add(std::pair<double, double> point);
	void Add(int x, int y);
	int Count();

	static double Distance(std::pair<double, double> p1, std::pair<double, double> p2);
	static double Angle(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3);
	double Area();
	double Perimeter();
	bool isRegular();
};


