//
// Created by vasiliy on 07.04.16.
//

#include "Figure.h"

using namespace std;

/* class Rectangle */
Rectangle::Rectangle () {};

Rectangle::Rectangle(Point a, Point b) :
	topLeftPoint(a),
	bottomRightPoint(b),
	topRightPoint(b.x, a.y),
	bottomLeftPoint(a.x, b.y)
{ angle = 0; }
Rectangle::Rectangle(Point a, Point b, double _angle) :
	topLeftPoint(a),
	bottomRightPoint(b),
	topRightPoint(bottomRightPoint.x, topLeftPoint.y),
	bottomLeftPoint(topLeftPoint.x, bottomRightPoint.y)
{ angle = _angle; }
Rectangle::Rectangle(Point topL, Point topR, Point botR, Point botL) :
	topLeftPoint(topL),
	topRightPoint(topR),
	bottomRightPoint(botR),
	bottomLeftPoint(botL)
{ angle = 0; }
Rectangle::Rectangle(Point topL, Point topR, Point botR, Point botL, double _angle) :
	topLeftPoint(topL),
	topRightPoint(topR),
	bottomRightPoint(botR),
	bottomLeftPoint(botL)
{ angle = _angle; }
Rectangle::Rectangle(double a_x, double a_y, double b_x, double b_y) :
	Rectangle(Point(a_x, a_y), Point(b_x, b_y))
{ angle = 0; }
Rectangle::Rectangle(double a_x, double a_y, double b_x, double b_y, double _angle) :
	Rectangle(Point(a_x, a_y), Point(b_x, b_y))
{ angle = _angle; }
Segment Rectangle::projection(Point e)
{
	Point p[2] = {
		bottomLeftPoint.projection(e),
		bottomRightPoint.projection(e)
	};
	if (p[0].x < p[1].x)
		return Segment(p[0], topRightPoint.projection(e));
	return Segment(topLeftPoint.projection(e), p[1]);
}
double Rectangle::computPerimeter()
{
	Point p[2] = {
		bottomLeftPoint - bottomRightPoint,
		topRightPoint - bottomRightPoint
	};

	return 2*(p[0].norm() + p[1].norm());
}