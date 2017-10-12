#include<ostream>

using namespace std;

class Point{
private :
	double _x, _y;

public :
#pragma region constructeurs

	Point();

	Point(double x, double y);

	Point(const Point &p);

#pragma endregion constructeurs
#pragma region getters/setters

	double getX() const { return _x; }

	double getY() const { return _y; }

	void setX(double x){ _x = x; }

	void setY(double y){ _y = y; }

#pragma endregion getters/setters

	bool operator=(const Point&);

	friend ostream& operator<<(ostream&, const Point&);

	Point operator+(const Point&);
};