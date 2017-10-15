#pragma once
#include<ostream>

using namespace std;

class Point{
private :
	double _x, _y;

public :
	Point();
	Point(double x, double y);
	Point(const Point &p);
	virtual ~Point();

	double getX() const { return _x; }
	double getY() const { return _y; }
	void setX(double x){ _x = x; }
	void setY(double y){ _y = y; }

	Point operator=(const Point&)const;
	bool operator==(const Point&)const;
	friend ostream& operator<<(ostream&, const Point&);
	Point operator+(const Point&)const;
	Point operator-(const Point&)const;
};
