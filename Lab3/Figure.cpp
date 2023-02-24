#include "Figure.h"
Figure::Figure(ArrayList<std::pair<double, double>> list)
{
	points = list;
}

Figure::Figure(LinkedList<std::pair<double, double>> list)
{
	for (int i = 0; i < list.Size(); i++)
		points.Push_back(list[i]);
}

void Figure::Add(std::pair<double, double> point)
{
	points.Push_back(point); 
}

void Figure::Add(int x, int y)
{
	points.Push_back({ x, y });
}

int Figure::Count()
{
    return points.Size();
}

std::pair<double, double>& Figure::operator[](int i) {
    return points[i];
}


//Відстань між двома точками
double Figure::Distance(std::pair<double, double> p1, std::pair<double, double> p2) {
	double ans = sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
	return ans;
}

//Рахує кут в точці p2 в радіанах
double Figure::Angle(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3) {
    double x1 = p2.first - p1.first;
    double y1 = p2.second - p1.second;
    double x2 = p2.first - p3.first;
    double y2 = p2.second - p3.second;

    double scalar = x1 * x2 + y1 * y2;
    double d1 = Distance(p1, p2);
    double d2 = Distance(p2, p3);

    double ans = acos(scalar / (d1 * d2));

    return ans;
}

//Площа фігури
double Figure::Area() {
    double ans = 0;

    for (int i = 0; i < points.Size() - 1; i++)
    {
        ans += points[i].first * points[i + 1].second - points[i].second * points[i + 1].first;
    }

    ans += points[points.Size() - 1].first * points[0].second - points[points.Size() - 1].second * points[0].first;

    return fabs(ans) / 2;
}

//Периметер фігури
double Figure::Perimeter() {
    double ans = 0;
    for (int i = 0; i < points.Size() - 1; i++) {
        ans += Distance(points[i], points[i + 1]);
    }
    ans += Distance(points[0], points[points.Size() - 1]);
    return ans;
}

// Перевірка чи є фігура правильною
bool Figure::isRegular() {

    double side = Distance(points[0], points[points.Size() - 1]);

    for (int i = 0; i < points.Size() - 1; i++)
    {
        double x = Distance(points[i], points[i + 1]);
        if (x != side)
            return false;
    }

    double inangle = Angle(points[points.Size() - 1], points[0], points[1]);

    for (int i = 1; i < points.Size() - 1; i++)
    {
        double x = Angle(points[i - 1], points[i], points[i + 1]);
        if (x != inangle)
            return false;
    }

    return true;
}