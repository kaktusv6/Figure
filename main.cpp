#include "Figuires/Figure.cpp"
#include <gtest/gtest.h>

using namespace std;

class FigureTest : public ::testing::Test
{
protected:
	Point p;
	Segment *a, *b = NULL;
	Cercle *c = NULL;
	Rectangle *r = NULL;
	Square *s = NULL;
	void SetUp()
	{

	}
};
TEST_F(FigureTest, TestPerimetrFigures)
{
	a = new Segment(1,2, 4,3);
	ASSERT_DOUBLE_EQ(sqrt(10), a->computPerimeter());

	a = new Segment(0,0, 2,2);
	ASSERT_DOUBLE_EQ(2*sqrt(2), a->computPerimeter());

	a = new Segment(3,2, 3,4);
	ASSERT_DOUBLE_EQ(Point(0, 2).norm(), a->computPerimeter());

	c = new Cercle(2,2, 2);
	ASSERT_DOUBLE_EQ(2*M_PI*2, c->computPerimeter());

	c = new Cercle(3,10, 2);
	ASSERT_DOUBLE_EQ(2*M_PI*2, c->computPerimeter());

	c = new Cercle(2,2, 4);
	ASSERT_DOUBLE_EQ(2*M_PI*4, c->computPerimeter());

	r = new Rectangle(0,0, 10,40);
	ASSERT_DOUBLE_EQ(2*(10 + 40), r->computPerimeter());

	r = new Rectangle(5,2, 10,40);
	ASSERT_DOUBLE_EQ(2*(5 + 38), r->computPerimeter());

	r = new Rectangle(5,2, 10,40);
	ASSERT_DOUBLE_EQ(2*(5 + 38), r->computPerimeter());
}
TEST_F(FigureTest, TestSegmentToPoint)
{
	a = new Segment(0, 0, 1, 2);
	ASSERT_EQ(Point(1, 2), a->toPoint());

	a = new Segment(-2, -2, 2, 2);
	ASSERT_EQ(Point(4, 4), a->toPoint());

	a = new Segment(0, 3, -5, 8);
	ASSERT_EQ(Point(-5, 5), a->toPoint());

	a = new Segment(0, 3, -5, 8);
	ASSERT_EQ(Point(-5, 5), a->toPoint());

	a = new Segment(-6, -3, -6, 3);
	ASSERT_EQ(Point(0, 6), a->toPoint());

	a = new Segment(6, 3, 3, 3);
	ASSERT_EQ(Point(3, 0), a->toPoint());
}
TEST_F(FigureTest, TestProjectionPoint)
{
	p = Point(1.5, 3.5);
	ASSERT_EQ(Point(2.5, 2.5), p.projection(Point(1, 1)));

	p = Point(1.5, 3.5);
	ASSERT_EQ(Point(2.5, 2.5), p.projection(Point(2, 2)));

	p = Point(1.5, 3.5);
	ASSERT_EQ(Point(2.5, 2.5), p.projection(Point(-0.75, -0.75)));

	p = Point(0, -1.5);
	ASSERT_EQ(Point(-0.75, -0.75), p.projection(Point(1, 1)));

	p = Point(-1, 1);
	ASSERT_EQ(Point(0, 0), p.projection(Point(1, 1)));
}
TEST_F(FigureTest, TestProjectionSegment)
{
	a = new Segment(3,1, 5,5);
	p = Point(6, 2);
	ASSERT_EQ(Segment(3,1, 6,2), a->projection(p));

	a = new Segment(-2,-4, 3,6);
	p = Point(3, 1);
	ASSERT_EQ(Segment(-3,-1, 4.5,1.5), a->projection(p));
}
TEST_F(FigureTest, TestProjectionCercle)
{
	c = new Cercle(2,8, sqrt(2));
	p = Point(2, 2);
	ASSERT_TRUE(Segment(4,4, 6,6) == c->projection(p));

	c = new Cercle(2,7, 2);
	p = Point(2, 0);
	ASSERT_TRUE(Segment(0,0, 4,0) == c->projection(p));

	c = new Cercle(2,7, 2);
	p = Point(0, 2);
	ASSERT_TRUE(Segment(0,5, 0,9) == c->projection(p));
}
TEST_F(FigureTest, TestProjectionRectangle)
{
	r = new Rectangle(0,6, 3,4);
	p = Point(2, 2);
	ASSERT_TRUE(Segment(2,2, 4.5,4.5) == r->projection(p));

	r = new Rectangle(5,4, 8,2);
	p = Point(1.45, 0);
	ASSERT_TRUE(Segment(5,0, 8,0) == r->projection(p));

	r = new Rectangle(Point(2,6), Point(4,8), Point(5,7), Point(3,5), M_PI/4);
	p = Point(1.45, 1.45);
	ASSERT_TRUE(Segment(4,4, 6,6) == r->projection(p));

	r = new Rectangle(3,5, 6,2);
	p = Point(1.45, 1.45);
	ASSERT_TRUE(Segment(2.5,2.5, 5.5,5.5) == r->projection(p));

	r = new Rectangle(3,7, 6,1);
	p = Point(1, 2);
	ASSERT_TRUE(Segment(1,2, 4,8) == r->projection(p));

	r = new Rectangle(3,7, 6,1);
	p = Point(1, 2);
	ASSERT_TRUE(Segment(1,2, 4,8) == r->projection(p));
}
TEST_F(FigureTest, TestProjectionSquare)
{
	s = new Square(1,6, 3,4);
	p = Point(1.093, 1.093);
	ASSERT_TRUE(Segment(2.5,2.5, 4.5,4.5) == s->projection(p));

	s = new Square(1,3, 3,1);
	p = Point(.000000093, .000000093);
	ASSERT_TRUE(Segment(1,1, 3,3) == s->projection(p));

	s = new Square(3,4, 6,1);
	p = Point(.2342393, .2342393);
	ASSERT_TRUE(Segment(2,2, 5,5) == s->projection(p));
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}