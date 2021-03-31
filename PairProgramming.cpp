#include <iostream>

<<<<<<< Updated upstream
	using namespace std;
#define CATCH_CONFIG_MAIN

=======
class Point {
private:
	int x, y;

public:
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
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

	const Point &startPoint() const{
		return p1;
	}
	Point &startPoint()
	{
		return p1;
	}
	const Point & endPoint() const 
	{
		return p2;
	}
	Point &endPoint()
	{
		return p2;
	}
};

int main() {
	Line line;
	line.startPoint() = Point(4, 2);
	line.endPoint() = Point(6, 9);
}
>>>>>>> Stashed changes
