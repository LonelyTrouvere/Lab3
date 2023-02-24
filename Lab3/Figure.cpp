#include "Figure.h"

Figure::Figure()
{
    ArrayList<std::pair<double, double>> list;
    points = list;
}

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

Figure::ETriangleSideType Figure::TriangleSideType()
{
    if (this->isRegular()) return Figure::ETriangleSideType::EQUILATERAL;
    else
        if (this->IsoscelesTriangle()) return Figure::ETriangleSideType::ISOSCELES;
        else
            return Figure::ETriangleSideType::ORDINARY;
}

Figure::ETriangleAngleType Figure::TriangleAngleType()
{
    if (this->ObtuseAngular()) Figure::ETriangleAngleType::OBTUSE;
    else
        if (this->RectangularTriangle()) Figure::ETriangleAngleType::RECTANGULAR;
        else
            return Figure::ETriangleAngleType::ACUTE;
}

Figure::EQuadrangleType Figure::QuadrangleType()
{
    if (this->Square()) return Figure::EQuadrangleType::SQUARE;
    if (this->Diamond()) return Figure::EQuadrangleType::DIAMOND;
    if (this->Rectangle()) return Figure::EQuadrangleType::RECTANGLE;
    if (this->Parallelogram()) return Figure::EQuadrangleType::PARALLELOGRAM;
    if (this->Trapeze()) return Figure::EQuadrangleType::TRAPEZE;
    return Figure::EQuadrangleType::ARBITARY;
}

Figure::ETrapezeType Figure::TrapezeType()
{
    if (this->IsoscelesTrapeze()) return Figure::ETrapezeType::ISOSCELEST;
    if (this->RectengularTrapeze()) return Figure::ETrapezeType::RECTANGULART;
    return Figure::ETrapezeType::ARBITARYT;
}

//Перевірка трикутника на рівнобедренність
bool Figure::IsoscelesTriangle() {

    double a = Distance(points[0], points[1]),
    b = Distance(points[1], points[2]),
    c = Distance(points[0], points[2]);

    if (a == b || b == c || a == c)
        return true;
    else
        return false;
}

// Перевірка на прямокутний трикутник
bool Figure::RectangularTriangle()
{
    if (points.Size() != 3) return false;

    double phi1 = Angle(points[0], points[1], points[2]),
        phi2 = Angle(points[1], points[2], points[0]),
        phi3 = Angle(points[2], points[0], points[1]);

    const double HALF_PI = M_PI/2;

    if (phi1 == HALF_PI || phi2 == HALF_PI || phi3 == HALF_PI)
        return true;

    return false;
}

// Перевірка на тупокутний трикутник
bool Figure::ObtuseAngular()
{
    double phi1 = Figure::Angle(points[0], points[1], points[2]),
        phi2 = Figure::Angle(points[1], points[2], points[0]),
        phi3 = Figure::Angle(points[2], points[0], points[1]);

    const double HALF_PI = M_PI / 2;

    if (phi1 > HALF_PI || phi2 > HALF_PI || phi3 > HALF_PI)
        return true;

    return false;
}

//Перевірка на паралелограм
bool Figure::Parallelogram()
{
    double a = Distance(points[0], points[1]),
        b = Distance(points[1], points[2]),
        c = Distance(points[2], points[3]),
        d = Distance(points[3], points[0]);

    if (a == c && b == d)
        return true;

    return false;
}

//Перевірка на прямокутник
bool Figure::Rectangle()
{
    double ang = Angle(points[1], points[2], points[3]);

    if (this->Parallelogram() && ang == M_PI / 2)
        return true;

    return false;
}

//Перевірка на ромб
bool Figure::Diamond()
{
    double a = Distance(points[0], points[1]),
        b = Distance(points[1], points[2]),
        c = Distance(points[2], points[3]),
        d = Distance(points[3], points[0]);

    if (a == b == c == d)
        return true;

    return false;
}

//Перевірка на квадрат
bool Figure::Square()
{
    if (this->Rectangle() && this->Diamond())
        return true;
    return false;
}

//Перевірка на трапецію
bool Figure::Trapeze()
{
    std::pair<double, double> a = { points[1].first - points[0].first, points[1].second - points[0].second },
        b = { points[2].first - points[1].first, points[2].second - points[1].second },
        c = { points[2].first - points[3].first, points[2].second - points[3].second },
        d = { points[3].first - points[0].first, points[3].second - points[0].second };

    if (a.first == c.first && c.first == 0) { a.first = a.second; c.first = c.second; }
    if (b.first == d.first && d.first == 0) { b.first = b.second; d.first = d.second; }
    if (a.second == c.second && c.second == 0) { a.second = a.first; c.second = c.first; }
    if (b.second == d.second && d.second == 0) { b.second = b.first; d.second = d.first; }

    if ((fabs(a.first / c.first) == fabs(a.second / c.second) && fabs(b.first / d.first) != fabs(b.second / d.second)) ||
        (fabs(a.first / c.first) != fabs(a.second / c.second) && fabs(b.first / d.first) == fabs(b.second / d.second)))
    {
        return true;
    }

    return false;
}

//Перевірка на ріівнобедренну трапецію
bool Figure::IsoscelesTrapeze()
{
    double a = Distance(points[0], points[1]),
        b = Distance(points[1], points[2]),
        c = Distance(points[2], points[3]),
        d = Distance(points[3], points[0]);

    if (this->Trapeze() && (a == c || b == d))
        return true;

    return false;
}

//Перевірка на прямокутну трапецію
bool Figure::RectengularTrapeze()
{
    double phi1 = Angle(points[0], points[1], points[2]),
        phi2 = Angle(points[1], points[2], points[3]),
        phi3 = Angle(points[2], points[3], points[0]);

    if (this->Trapeze() && (phi1 == M_PI / 2 || phi2 == M_PI / 2 || phi3 == M_PI / 2))
        return true;

    return false;
}