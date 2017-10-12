#pragma once
#include"point.h"


Point::Point(){
	_x = _y = 0;
}

Point::Point(int x, int y){
	_x = x;
	_y = y;
}

Point::Point(const Point &p){
	_x = p._x;
	_y = p._y;
}
