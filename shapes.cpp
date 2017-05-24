#include "Shapes.h"
#include <iostream>
int main() {
	Point p1("point", 1, 1);
	Point p2("point", 3, 2);

	//std::cout << p1;

	//Circle c1("circle", p1, 1);
	//std::cout<<c1; 

	

	

	Polyline pl("line", p1);
	std::cout << std::endl << p1;


}