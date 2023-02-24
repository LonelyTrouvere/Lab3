#pragma once
#include"List.h"
#include"LinkedList.h"
#include"ArrayList.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Figure
{
private:
	ArrayList<std::pair<double, double>> points;
public:
	Figure();
	Figure(ArrayList<std::pair<double, double>> list);
	Figure(LinkedList<std::pair<double, double>> list); 

	enum ETriangleSideType {
		ORDINARY,
		ISOSCELES,
		EQUILATERAL
	};

	enum ETriangleAngleType {
		ACUTE,
		OBTUSE,
		RECTANGULAR
	};

	enum EQuadrangleType {
		SQUARE,
		DIAMOND,
		RECTANGLE,
		PARALLELOGRAM,
		TRAPEZE, 
		ARBITARY
	};

	enum ETrapezeType {
		ARBITARYT,
		ISOSCELEST,
		RECTANGULART
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

	//Функції, які повертають тип фігури
	ETriangleSideType TriangleSideType();
	ETriangleAngleType TriangleAngleType();
	EQuadrangleType QuadrangleType();
	ETrapezeType TrapezeType();

private:
	//Перевірки на різні типи фігур

	//Перевірки трикутника
	bool IsoscelesTriangle();
	bool RectangularTriangle();
	bool ObtuseAngular();

	//Перевірки типів чотирикутника
	bool Square();
	bool Diamond();
	bool Rectangle();
	bool Parallelogram();
	bool Trapeze();

	//Перевірка типу трапеції
	bool IsoscelesTrapeze();
	bool RectengularTrapeze();
};


