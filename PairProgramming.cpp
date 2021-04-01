#include <iostream>

<<<<<< <Updated upstream
	using namespace std;
#define CATCH_CONFIG_MAIN


class Point {
private:
	int x, y;

public:
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	int& GetX() { return x; }
	int& GetY() { return y; }
};

class Line {
private:
	Point p1;
	Point p2;

public:
	Line::Line()
	{
	}

	Line(Point start, Point end) : p1(start), p2(end)
	{
	}

	const Point& startPoint() const {
		return p1;
	}
	Point& startPoint()
	{
		return p1;
	}
	const Point& endPoint() const
	{
		return p2;
	}
	Point& endPoint()
	{
		return p2;
	}
};

double GetSlope(Line l1) {
	double Y = l1.endPoint().GetY() - l1.startPoint().GetY();
	double X = l1.endPoint().GetX() - l1.startPoint().GetX();
	double LineSlope = Y / X;
}

bool Parallel(Line l1, Line l2) {
	double Slope1 = GetSlope(l1);
	double Slope2 = GetSlope(l2);
	if (Slope1 == Slope2)
		return true;
	else
		return false;
}

int main() {
	Line line;
	line.startPoint() = Point(4, 2);
	line.endPoint() = Point(6, 9);
}
>>>>>> > Stashed changes
