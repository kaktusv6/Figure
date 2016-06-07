# pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <gtest/gtest_prod.h>

const double INTERVAL = 0.000001;

extern bool execle(double a, double b)
{
	double c = a - b;
	c *= c < 0 ? -1 : 1;

	return c < INTERVAL;
}

/* class Point */

class Point
{
public:
	double x;
	double y;
	Point();
	Point(double, double);
	void print();
	double norm();
	Point operator+ (Point);
	Point operator- (Point);
	Point operator* (double);
	double operator* (Point);
	Point operator/ (double);
//	bool operator== (Point);
	friend bool operator== (Point, Point);
	Point projection(Point e);
};

/* class IFigure */
/*   Interface  */

class IFigure
{
public:
	IFigure() {};
	virtual double computPerimeter() =0;
	virtual void print() =0;
};

/* class Segment */

class Segment : public IFigure
{
private:
	Point a_1;
	Point a_2;
public:
	Segment() {};
	Segment(Point, Point);
	Segment(double, double, double, double);
	Segment projection(Point);

	Point intersaction(Segment);
	Point toPoint();

	double computPerimeter();
	friend bool operator== (Segment segment1, Segment segment2);

	void print();
};

/* class Cercle */

class Cercle : public IFigure
{
private:
	Point center;
	double radius;
public:
	Cercle() {};

	Cercle(Point, double);

	Cercle(double,double,double);

	double computPerimeter();
	Segment projection(Point);
	void print() {}
};

/* class Rectangle */

class Rectangle : public IFigure 
{
	Point topLeftPoint;
	Point topRightPoint;

	Point bottomLeftPoint;
	Point bottomRightPoint;

	double angle;
public:
	Rectangle();

	Rectangle(Point, Point);
	Rectangle(Point, Point, double _angle);
	Rectangle(Point, Point, Point, Point);
	Rectangle(Point, Point, Point, Point, double _angle);

	Rectangle(double, double, double, double);
	Rectangle(double, double, double, double, double _angle);

	Segment projection(Point);
	double computPerimeter();
	void print() {}
};

/* class Square */

class Square : public Rectangle
{
public:
	Square();

	Square(Point, Point);
	Square(Point, Point, double _angle);
	Square(Point, Point, Point, Point);
	Square(Point, Point, Point, Point, double _angle);

	Square(double,double, double,double);
	Square(double,double, double,double, double _angle);
	void print() {}
};