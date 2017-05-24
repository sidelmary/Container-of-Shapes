#pragma once
#include "Container.h"
#include "Base.h"
#include <cstdint>
#include <string>
#include <cmath>
#include "Exception.h"

class Shape : public virtual Printable {
public:
	static uint32_t counter;
	static uint32_t GetCount() {
		return counter;
	}
	virtual std::string get_string() = 0;
	virtual ~Shape() {
		--counter;
		
	
	};

	Shape() {
		++counter;

	}

	Shape(Shape const & other) {
		++counter;
	}
};

uint32_t Shape::counter;

class Point : public Shape, public Named {
public:
	Point(std::string name, double x, double y): Named(name), m_x(x), m_y(y) {}
	double get_x() const {
		return m_x;
	}
	double get_y() const {
		return m_y;
	}
	std::string get_string() {
		return get_name() + " : (" + std::to_string(m_x) + " , " + std::to_string(m_y) + ")";
	}
	virtual~Point() {}
	
private:
	double m_x;
	double m_y;
};




class Circle : public Shape, public Named {
public:

	Circle(std::string name ,Point const & center, double rad): Named(name), m_center(center), m_rad(rad) {
		m_area = 3.14*rad*rad;
	}

	std::string get_string() {
		return get_name() + " : " + m_center.get_string() + " | " + " rad = " + std::to_string(m_rad) + " | " + " area = " + std::to_string(m_area);
	}

	~Circle() {}
	
private:
	Point m_center;
	double m_rad;
	double m_area;
};

class Rect : public Shape, public Named {
public:
	Rect(std::string name, Point const & p1, Point const & p2): Named(name), m_p1(p1), m_p2(p2) {
		double x1 = p1.get_x();
		double x2 = p2.get_x();
		double y1 = p1.get_y();
		double y2 = p2.get_y();
		if ((x1 > x2) || (y1 > y2)) {
			throw Bad_rect();
		}
		m_area = (x1 - x2)*(y1 - y2);
	}
	std::string get_string() {
		return get_name() + " : " + m_p1.get_string() + m_p2.get_string() + " | area = " + std::to_string(m_area);
	}

	~Rect() {}
private:
	Point m_p1;
	Point m_p2;
	double m_area;
};

class Square : public Shape, public Named {
public:
	Square(std::string name, Point const & p, double len): Named(name), m_p1(p), m_len(len) {
		m_area = len*len;
	}
	std::string get_string() {
		return get_name() + " : " + m_p1.get_string() + "| length = " + std::to_string(m_len) + " | area = " + std::to_string(m_area);
	}
	~Square() {
	}
private:
	Point m_p1;
	double m_len;
	double m_area;
};

class Polyline : public Shape, public Named {
public:
	Polyline(std::string name): Named(name), m_line() {
		m_len = 0;
	}
	void AddPoint( Point * point) {
		if (!m_line.is_it_empty()) {
			Point* last_point = m_line.get_tail();
			m_len += calc_dist(*last_point, *point);
		}
		m_line.add_tail(point);
	}
	std::string get_string() {
		std::string info; 
		info = get_name() + " : ";
		for (uint32_t i = 0; i < m_line.get_size(); ++i) {
			info += m_line.get_value(i).get_string() + " ";
		}
		info += " | length = " + std::to_string(m_len);
		return info;
	}

	~Polyline() {
		if (!m_line.is_it_empty())
			m_line.clean();
	}
	
	
private:
	Container<Point> m_line;
	double m_len;
	double calc_dist(Point const & p1, Point const & p2) {
		double dist;
		double x = p1.get_x();
		double y = p1.get_y();
		double x_new = p2.get_x();
		double y_new = p2.get_y();
		dist = sqrt((x_new - x)*(x_new - x) + (y_new - y)*(y_new - y));
		return dist;
	}
};

class Polygon : public Shape, public Named {
public:
	Polygon(std::string name) : Named(name), m_polygon() {
		m_perimeter = 0;
		m_len = 0;
	}
	
	void AddPoint(Point * point) {
		if (!m_polygon.is_it_empty()) {
			Point* last_point = m_polygon.get_tail();
			m_len += calc_dist(*last_point, *point);
		}
		m_polygon.add_tail(point);
		m_perimeter = m_len + calc_dist(*m_polygon.get_tail(), *m_polygon.get_head());
	}

	std::string get_string() {
		std::string info;
		info = get_name() + " : ";
		for (uint32_t i = 0; i < m_polygon.get_size(); ++i) {
			info += m_polygon.get_value(i).get_string() + " ";
		}
		info+= m_polygon.get_head()->get_string() + " ";
		info += " | perimeter = " + std::to_string(m_perimeter);
		return info;
	}

	~Polygon() {
		m_polygon.clean();
	}

private:
	Container<Point> m_polygon;
	double m_len;
	double m_perimeter;
	double calc_dist(Point const & p1, Point const & p2) const {
		double dist;
		double x = p1.get_x();
		double y = p1.get_y();
		double x_new = p2.get_x();
		double y_new = p2.get_y();
		dist = sqrt((x_new - x)*(x_new - x) + (y_new - y)*(y_new - y));
		return dist;
	}
};