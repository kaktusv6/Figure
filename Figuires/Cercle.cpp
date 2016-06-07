//
// Created by vasiliy on 07.04.16.
//

#include "Figure.h"

/* class Cercle */
Cercle::Cercle(Point _center, double r)
{
	center = _center;
	radius = r;
}
Cercle::Cercle(double c_x,double c_y,double r) :
	center(c_x, c_y)
{
	radius = r;
}
double Cercle::computPerimeter()
{
	return 2 * M_PI * radius;
}
Segment Cercle::projection(Point e)
{
	Point center = this->center.projection(e);
	Point normVector = e/e.norm();
	return Segment(normVector*(center.norm() - radius), normVector*(center.norm() + radius));
}
