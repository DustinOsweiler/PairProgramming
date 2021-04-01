#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define pdd pair<double, double>

struct Point
{
	double x;
	double y;
	int GetX() { return x; }
	int GetY() { return y; }
};
class Line
{
private:
	Point p1;
	Point p2;

public:
	Line()
	{
	}

	Line(Point start, Point end) : p1(start), p2(end)
	{
	}

	const Point &startPoint() const
	{
		return p1;
	}
	Point &startPoint()
	{
		return p1;
	}
	const Point &endPoint() const
	{
		return p2;
	}
	Point &endPoint()
	{
		return p2;
	}
};

int LineFromPoints(pdd P, pdd B)
{
	double a = B.second - P.second;
	double b = P.first - B.first;
	double c = a * (P.first) + b * (P.second);

	if (b < 0)
	{
		cout << "The line passing through points P and Q "
				"is: "
			 << a << "x - " << b << "y = " << c << endl;
	}
	else
	{
		cout << "The line passing through points P and Q "
				"is: "
			 << a << "x + " << b << "y = " << c << endl;
	}
}

// These 3 points p,b,r the function checks if point b lies one the line segment pr

bool onSegment(Point p, Point b, Point r)
{
	if (b.x <= max(p.x, r.x) && b.x >= min(p.x, r.x) &&
		b.y <= max(p.y, r.y) && b.y >= min(p.y, r.y))
		return true;

	return false;
}

double orient(Point p, Point b, Point r)
{
	int val = (b.y - p.y) * (r.x - b.x) -
			  (b.x - p.x) * (r.y - b.y);
	if (val == 0)
	{
		return 0; //colinear
	}

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doesIntersect(Point x1, Point y1, Point x2, Point y2)
{
	int o1 = orient(x1, y1, x2);
	int o2 = orient(x1, y1, y2);
	int o3 = orient(x2, y2, x1);
	int o4 = orient(x2, y2, y1);

	// General case
	if (o1 != o2 && o3 != o4)
	{
		return true;
	}

	// Special Cases
	// x1, y1 and x2 are colinear and x2 lies on segment x1y1
	if (o1 == 0 && onSegment(x1, x2, y1))
		return true;

	// x1, y1 and y2 are colinear and y2 lies on segment x1y1
	if (o2 == 0 && onSegment(x1, y2, y1))
		return true;

	// x2, y2 and x1 are colinear and x1 lies on segment x2y2
	if (o3 == 0 && onSegment(x2, x1, y2))
		return true;

	// x2, y2 and y1 are colinear and y1 lies on segment x2y2
	if (o4 == 0 && onSegment(x2, y1, y2))
		return true;

	return false; // Doesn't fall in any of the above cases
}
double GetSlope(Line l1)
{
	double Y = l1.endPoint().GetY() - l1.startPoint().GetY();
	double X = l1.endPoint().GetX() - l1.startPoint().GetX();
	double LineSlope = Y / X;
}

bool Parallel(Line l1, Line l2)
{
	double Slope1 = GetSlope(l1);
	double Slope2 = GetSlope(l2);
	if (Slope1 == Slope2)
		return true;
	else
		return false;
}

void pointrepresentation(Point p1)
{
	cout << "X: " << p1.GetX() << ", Y: " << p1.GetY();
	return;
}

void linerepresentation(Line l1)
{
	cout << "Point 1: [X: " << l1.startPoint().GetX() << ", Y: " << l1.startPoint().GetY() << "], Point 2: [X: " << l1.endPoint().GetX() << ", Y: " << l1.endPoint().GetY() << "]";
	return;
}

int main()
{
	// Test to check Length of the line
	pdd P = make_pair(3, 2);
	pdd Q = make_pair(2, 6);
	LineFromPoints(P, Q);

	Point p1{2, 4};
	Point p2{6, 8};
	pdd pOnce = make_pair(2, 4);
	pdd pTwice = make_pair(6, 8);
	LineFromPoints(pOnce, pTwice);
	Point p3{1, 3};
	Point p4{3, 5};
	pdd pTres = make_pair(1, 3);
	pdd pFour = make_pair(3, 5);
	LineFromPoints(pTres, pFour);
	onSegment({1, 3}, {2, 4}, {6, 8}) ? cout << "Yes\n" : cout << "No\n";
	Line Test1(p1, p2);
	Line Test2(p3, p4);
	Parallel(Test1, Test2) ? cout << "Yes\n" : cout << "No\n";
	linerepresentation(Test1);
	linerepresentation(Test2);
	Point x1{2, 4};
	Point y1{6, 8};
	Point x2{1, 3};
	Point y2{3, 5};
	doesIntersect(x1, y1, x2, y2) ? cout << "Yes\n" : cout << "No\n";

	p1 = {4, 4};
	p2 = {6, 8};
	p3 = {4, 9};
	p4 = {8, 3};
	Test1 = {p1, p2};
	Test2 = {p3, p4};
	pOnce = make_pair(4, 4);
	pTwice = make_pair(6, 8);
	LineFromPoints(pOnce, pTwice);
	p3 = {4, 9};
	p4 = {8, 3};
	pTres = make_pair(4, 9);
	pFour = make_pair(8, 3);
	LineFromPoints(pTres, pFour);
	onSegment({4, 4}, {2, 3}, {6, 8}) ? cout << "Yes\n" : cout << "No\n";
	Parallel(Test1, Test2) ? cout << "Yes\n" : cout << "No\n";
	linerepresentation(Test1);
	linerepresentation(Test2);
	x1 = {4, 4};
	y1 = {6, 8};
	x2 = {4, 9};
	y2 = {3, 5};
	doesIntersect(x1, y1, x2, y2) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
