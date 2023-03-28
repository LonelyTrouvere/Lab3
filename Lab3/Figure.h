#pragma once
#include"List.h"
#include"LinkedList.h"
#include"ArrayList.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Represents a figure with a collection of points.
 */
class Figure
{
private:
    ArrayList<std::pair<double, double>> points; 
public:
    /**
     * @brief Constructs a new, empty Figure object.
     */
    Figure();

    /**
     * @brief Constructs a new Figure object with the specified list of points.
     *
     * @param list The Array list of points to initialize the Figure with.
     */
    Figure(ArrayList<std::pair<double, double>> list);

    /**
     * @brief Constructs a new Figure object with the specified linked list of points.
     *
     * @param list The linked list of points to initialize the Figure with.
     */
    Figure(LinkedList<std::pair<double, double>> list);

    /**
     * @brief The types of triangles that can be determined from the figure.
     */
    enum ETriangleSideType {
        ORDINARY, /**< The triangle is ordinary (no equal sides). */
        ISOSCELES, /**< The triangle is isosceles (two equal sides). */
        EQUILATERAL, /**< The triangle is equilateral (all sides are equal). */
        NOTATRIANGLE /**< The figure is not a triangle. */
    };

    /**
     * @brief The types of angles that can be determined from the figure.
     */
    enum ETriangleAngleType {
        ACUTE, /**< The triangle is acute (all angles are less than 90 degrees). */
        OBTUSE, /**< The triangle is obtuse (one angle is greater than 90 degrees). */
        RECTANGULAR, /**< The triangle is rectangular (one angle is equal to 90 degrees). */
        NOTATRIANGLE2 /**< The figure is not a triangle. */
    };

    /**
     * @brief The types of quadrangles that can be determined from the figure.
     */
    enum EQuadrangleType {
        SQUARE, /**< The quadrangle is a square. */
        DIAMOND, /**< The quadrangle is a diamond (rhombus). */
        RECTANGLE, /**< The quadrangle is a rectangle. */
        PARALLELOGRAM, /**< The quadrangle is a parallelogram. */
        TRAPEZE, /**< The quadrangle is a trapeze. */
        ARBITARY, /**< The quadrangle is arbitrary (no specific type). */
        NOTAQUADRANGLE /**< The figure is not a quadrangle. */
    };

    /**
     * @brief The types of trapezes that can be determined from the figure.
     */
    enum ETrapezeType {
        ARBITARYT, /**< The trapeze is arbitrary (no specific type). */
        ISOSCELEST, /**< The trapeze is isosceles (two sides are parallel and two sides are not). */
        RECTANGULART, /**< The trapeze is rectangular (two sides are perpendicular). */
        NOTATRAPEZE /**< The figure is not a trapeze. */
    };

    /**
     * @brief Returns a reference to the point at the specified position in the figure.
     *
     * @param i The index of the point to retrieve.
     * @return A reference to the point at the specified position in the figure.
     */
    std::pair<double, double>& operator[](int i);

    /**
     * @brief Adds a point to the figure.
     *
     * @param point The point to add to the figure.
     */
	void Add(std::pair<double, double> point);
    /**
     * \brief Adds a point to the Figure.
     * \param x The x-coordinate of the point to add.
     * \param y The y-coordinate of the point to add.
     */
    void Add(double x, double y);

    /**
     * \brief Returns the number of points in the Figure.
     * \return The number of points in the Figure.
     */
    int Count();

    /**
     * \brief Returns the distance between two points.
     * \param p1 The first point.
     * \param p2 The second point.
     * \return The distance between the two points.
     */
    static double Distance(std::pair<double, double> p1, std::pair<double, double> p2);

    /**
     * \brief Returns the angle between three points.
     * \param p1 The first point.
     * \param p2 The second point.
     * \param p3 The third point.
     * \return The angle between the three points.
     */
    static double Angle(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3);

    /**
     * \brief Calculates and returns the area of the Figure.
     * \return The area of the Figure.
     */
    double Area();

    /**
     * \brief Calculates and returns the perimeter of the Figure.
     * \return The perimeter of the Figure.
     */
    double Perimeter();

    /**
     * \brief Determines if the Figure is regular (i.e., all sides and angles are equal).
     * \return True if the Figure is regular, false otherwise.
     */
    bool isRegular();

    /**
     * \brief Returns the type of triangle based on the side lengths.
     * \return The type of triangle based on the side lengths.
     */
    ETriangleSideType TriangleSideType();

    /**
     * \brief Returns the type of triangle based on the angle measurements.
     * \return The type of triangle based on the angle measurements.
     */
    ETriangleAngleType TriangleAngleType();

    /**
     * \brief Returns the type of quadrangle.
     * \return The type of quadrangle.
     */
    EQuadrangleType QuadrangleType();

    /**
     * \brief Returns the type of trapeze.
     * \return The type of trapeze.
     */
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


