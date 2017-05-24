#pragma once
#include "Shapes.h"
#include <ctime>

class Creator {
public:
	virtual Shape * create() = 0;
};

class Point_Creator:public Creator {
public:
	Shape * create() {
		srand(time(0));
		double x = static_cast<double>(rand());
		double y = static_cast<double>(rand());
		return new Point("point", x, y);
	}
};

class Circle_Creator: public Creator {
public:
	Shape * create() {
		srand(time(0));
		Point p("point", static_cast<double>(rand()), static_cast<double>(rand()));
		return new Circle("circle", p, static_cast<double>(rand()));
	}
};

class Square_Creator {
public:
	Shape * create() {
		srand(time(0));
		Point p("point", static_cast<double>(rand()), static_cast<double>(rand()));
		return new Square("square", p, static_cast<double>(rand()));
		
	}
};

class Rect_Creator {
public:
	Shape * create() {
		srand(time(0));
		double x1 = static_cast<double>(rand());
		double x2 = static_cast<double>(rand());
		if (x1 > x2) {
			double x = x1;
			x1 = x2;
			x2 = x;
		}
		double y1 = static_cast<double>(rand());
		double y2 = static_cast<double>(rand());
		if (y1 > y2) {
			double y = y1;
			y1 = y2;
			y2 = y;
		}
		Point p1("point", x1, y1);
		Point p2("point", x2, y2);
		
	
		return new Rect("rect", p1, p2);
	}
};

class Polyline_Creator {
public:
	Shape * create() {
		srand(time(0));
		Polyline * line = new Polyline("polyline");
		uint32_t n = rand()%5+1;
		for (uint32_t i = 0; i < n; ++i) {

			line->AddPoint(new Point("point", static_cast<double>(rand()), static_cast<double>(rand())));
		}
		return line;
	}
};
 
class Polygon_Creator {
public:
	Shape * create() {
		srand(time(0));
		Point p1("point", static_cast<double>(rand()), static_cast<double>(rand()));
		Polygon * pg = new Polygon("polygon");
		uint32_t n = rand()%5+1;
		for (uint32_t i = 0; i < n; ++i) {
	
			pg->AddPoint(new Point("point", static_cast<double>(rand()), static_cast<double>(rand())));
		}
		return pg;
	}
};