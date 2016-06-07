//
// Created by vasiliy on 07.04.16.
//

#include "Figure.h"

/* class Square*/
Square::Square()
{ }

Square::Square(double x_1, double y_1, double x_2, double y_2) :
	Rectangle(x_1, y_1, x_2, y_2)
{  }

Square::Square(double x_1, double y_1, double x_2, double y_2, double _angle) :
	Rectangle(x_1, y_1, x_2, y_2, _angle)
{  }

Square::Square(Point topLeft, Point bottomRight) :
	Rectangle(topLeft, bottomRight)
{ }

Square::Square(Point topLeft, Point bottomRight, double _angle) :
	Rectangle(topLeft, bottomRight, _angle)
{ }

Square::Square(Point topL, Point topR, Point botR, Point botL) :
	Rectangle(topL, topR, botR, botL)
{ }

Square::Square(Point topL, Point topR, Point botR, Point botL, double _angle) :
	Rectangle(topL, topR, botR, botL, _angle)
{ }