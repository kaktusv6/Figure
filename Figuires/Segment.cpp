//
// Created by vasiliy on 07.04.16.
//

#include "Figure.h"

using namespace std;

/* class Segment */
Segment::Segment(Point a, Point b)
{
	if (a == b) { /* error */ }
	a_1 = a, a_2 =b;
}
Segment::Segment(double a_x, double a_y, double b_x, double b_y) :
	a_1(a_x, a_y),
	a_2(b_x, b_y)
{  }
double Segment::computPerimeter()
{
	return (a_1 - a_2).norm();
}
Point Segment::intersaction(Segment segment)
{

//	 паралельность векторов можно проверить черех cos угла между отрезками
	// (a_1, b_1) = |a_1||b_1| cos()
	// (a_2, b_2) = |a_2||b_2| cos()

	double angle = 0;

	angle = (this->toPoint() * segment.toPoint()) /
		(this->toPoint().norm() * segment.toPoint().norm());
// неправельно реализован execle
	if (execle(angle, 1))
		return Point(INFINITY, INFINITY);

	Point point[4] = {
		segment.a_2 - segment.a_1,
		this->a_1 - this->a_2,
		segment.a_2 - this->a_2,
		segment.a_1 - this->a_1
	};

	double cosAngle = (point[2].norm()*point[3].norm())/(point[3]*point[2]);
	if (execle(cosAngle, 0))
		return this->a_1;
	double 	a = point[0].x,
		b = point[1].x,
		c = point[0].y,
		d = point[1].y,
		t_1 = 0, t_2 = 0;
//	if (a == 0 && b == 0)
//	{
	// => отрезки паралельны оси Y
	// имеют либо 1 точку либо бесконечное кол-во(inf) либо точек пересечения нет.
	// если inf тогда возращаем отрезок который содержит эти пересечения
//	}
//	else if (c == 0 && d == 0)
//	{
	// => отрезки паралельны оси X
	// имеют либо 1 точку либо бесконечное кол-во(inf) либо точек пересечения нет.
	// если inf тогда возращаем отрезок который содержит эти пересечения
//	}
	if (a == 0) // tested
	{
		a = point[2].x;
		t_1 = a/b;

		a = point[2].y;
		t_2 = (a - d * t_1)/c;
		Point p = this->a_1*t_1 + this->a_2*(1 - t_1);
	}
	else if (c == 0)
	{
		c = point[2].y;
		t_1 = c/d;

		c = point[2].x;
		t_2 = (c - b * t_1)/a;
	}
	else if (b == 0)
	{
		b = point[2].x;
		t_2 = b/a;

		b = point[2].y;
		t_1 = (b - c*t_2) / d;
	}
	else if (d == 0)
	{
		d = point[2].y;
		t_2 = d/c;

		d = point[2].x;
		t_1 = (d - a*t_2) / b;
	}
	else
	{
		double x = a*d - c*b,
			h = point[2].x,
			k = point[2].y;

		t_2 = (h*d - k*b)/(a*d - c*b);
		t_1 = (k - t_2*c)/d;
	}
	Point p_1 = this->a_1*t_1 + this->a_2 - this->a_2*t_1;
	Point p_2 = segment.a_1*t_2 + segment.a_2 - segment.a_2*t_2;
	return p_1;
}
Point Segment::toPoint()
{
	Point bottomPoint(0, 0);
	Point upPoint(0, 0);

	if (this->a_1.y > this->a_2.y)
	{
		upPoint = this->a_1;
		bottomPoint = this->a_2;
	}
	else if (this->a_2.y > this->a_1.y)
	{
		upPoint = this->a_2;
		bottomPoint = this->a_1;
	}
	else
	{
		upPoint = this->a_1;
		bottomPoint = this->a_2;
	}


	return upPoint - bottomPoint;
}
Segment Segment::projection(Point e)
{
	return Segment(a_1.projection(e), a_2.projection(e));
}
bool operator== (const Segment segment1, const Segment segment2)
{
	if (!(segment1.a_1 == segment2.a_1 || segment1.a_1 == segment2.a_2)) return false;
	if (!(segment1.a_2 == segment2.a_1 || segment1.a_2 == segment2.a_2)) return false;
	return true;
}
void Segment::print()
{
	cout << '(' << a_1.x << ", " << a_1.y << ") -- ("
		<< a_2.x << ", " << a_2.y << ')' << endl;
}
//bool operator== (const Segment a, const Segment b)
//{
//	if (!(a.a_1 == b.a_1 || a.a_1 == b.a_2)) return false;
//	if (!(a.a_2 == b.a_1 || a.a_2 == b.a_2)) return false;
//	return true;
//}