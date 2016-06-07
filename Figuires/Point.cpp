#include "Figure.h"

using namespace std;

/* class Point */
Point::Point ()
{  }
Point::Point(double _x, double _y) : x(_x), y(_y)
{  }
void Point::print()
{
	cout << '(' << this->x << ',' << this->y << ')' << endl;
}
double Point::norm()
{
	return sqrt(this->x * this->x + this->y * this->y);
}
Point Point::operator+ (Point a)
{
	return Point(this->x + a.x, this->y + a.y);
}
Point Point::operator- (Point a)
{
	return Point(this->x - a.x, this->y - a.y);
}
Point Point::operator* (double a)
{
	return Point(this->x * a, this->y * a);
}
double Point::operator* (Point a)
{
	return this->x*a.x + this->y*a.y;
}
Point Point::operator/ (double a)
{
	return Point(this->x/a, this->y/a);
}
//bool Point::operator== (Point a)
//{
////	bool b = execle(x, a.x) && execle(y, a.y);
//	return (*this - a).norm() < INTERVAL;
//}
bool operator== (Point a, Point b)
{
	return (b - a).norm() < INTERVAL;
}
Point Point::projection(Point e)
{
	return e * ((*this*e)/(e.norm() * e.norm()));
}
