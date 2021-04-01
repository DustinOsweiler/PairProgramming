#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


struct Point
{
	double x;
	double y;
};

// These 3 points p,b,r the function checks if point b lies one the line segment pr

bool onSegment(Point p, Point b, Point r)
{
	  if (b.x <= max(p.x, r.x) && b.x >= min(p.x, r.x) &&
        b.y <= max(p.y, r.y) && b.y >= min(p.y, r.y))
       return true;
  
    return false;
}

int orient(Point p, Point b, Point r)
{
	int val = (b.y - p.y) * (r.x - b.x) -
			  (b.x - p.x) * (r.y - b.y);
	if (val == 0)
	{
		return 0; //colinear
	}

	return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doesIntersect(Point x1, Point y1, Point x2, Point y2)
{
	double o1 = orient(x1,y1,x2);
	double o2 = orient(x1,y1,y2);
	double o3 = orient(x2,y2,x1);
	double o4 = orient(x2,y2,y1);

	// General case
	if (o1 != o2 && o3 != o4){
        return true;
	}

	// Special Cases
    // x1, y1 and x2 are colinear and x2 lies on segment x1y1
    if (o1 == 0 && onSegment(x1, x2, y1)) return true;
  
    // x1, y1 and y2 are colinear and y2 lies on segment x1y1
    if (o2 == 0 && onSegment(x1, y2, y1)) return true;
  
    // x2, y2 and x1 are colinear and x1 lies on segment x2y2
    if (o3 == 0 && onSegment(x2, x1, y2)) return true;
  
     // x2, y2 and y1 are colinear and y1 lies on segment x2y2
    if (o4 == 0 && onSegment(x2, y1, y2)) return true;
  
    return false; // Doesn't fall in any of the above cases
}
class Line
{

public:
	double x1;
	double x2;
	double y1;
	double y2;
};



int main()
{
	// What this should do is find the length of the line segment between x and y coordinates
	double x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	double s;
	s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	cout << fixed << setprecision(3);
	cout << s << endl;
	return 0;

	struct Point x1 = {1, 1}, y1 = {10, 1};
    struct Point x2 = {1, 2}, y2 = {10, 2};
  
    doesIntersect(x1, y1, x2, y2)? cout << "Yes\n": cout << "No\n";
  
    x1 = {10, 0}, y1 = {0, 10};
    x2 = {0, 0}, y2 = {10, 10};
    doesIntersect(x1, y1, x2, y2)? cout << "Yes\n": cout << "No\n";
  
    x1 = {-5, -5}, y1 = {0, 0};
    x2 = {1, 1}, y2 = {10, 10};
    doesIntersect(x1, y1, x2, y2)? cout << "Yes\n": cout << "No\n";
  
    return 0;
}
