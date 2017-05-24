#include "Factory.h"
#include <iostream>



int main() {
	Container<Shape> Shapes;

	Point_Creator point_creator;
	Circle_Creator circle_creator;
	Rect_Creator rect_creator;
	Square_Creator square_creator;
	Polyline_Creator polyline_creator;
	Polygon_Creator polygon_creator;


	/*std::cout <<  "Start " << Shape::GetCount() << std::endl;
	Point * p1 = new Point("point", 1, 1);
	std::cout << "Step1 " << Shape::GetCount() << std::endl;
	Point * p2 =  new Point("point", 2, 2);
	std::cout << "Step2 " << Shape::GetCount() << std::endl;
	Polyline line("polyline");
	std::cout << "Step3 " << Shape::GetCount() << std::endl;
	line.AddPoint(*p1);
	
	std::cout << "Step4 " << Shape::GetCount() << std::endl;
	line.AddPoint(*p2);
	std::cout << "Step5 " << Shape::GetCount() << std::endl;

	delete p1;
	delete p2;
	std::cout << "Step6 " << Shape::GetCount() << std::endl;

	Shape * l = polyline_creator.create();
	std::cout << "Step7 " << Shape::GetCount() << std::endl;


	//line.AddPoint(*p2);
	//std::cout << "Step4 " << Shape::GetCount() << std::endl;
	//std::cout << Shape::GetCount() << std::endl;
	*/

	
	srand(time(0));
	uint32_t n=25;
	for (uint32_t i = 0; i < n; ++i) {
		uint32_t key = rand()%6;
		switch (key)
		{
			Shape * sh;
		case 0:
			sh = point_creator.create();
			Shapes.add_tail(sh);
			break;
		case 1:
			Shapes.add_tail(circle_creator.create());
			break;
		case 2:
			Shapes.add_tail(rect_creator.create());
			break;
		case 3:
			Shapes.add_tail(square_creator.create());
			break;
		case 4:
			Shapes.add_tail(polyline_creator.create());
			break;
		case 5:
			Shapes.add_tail(polygon_creator.create());
			break;
		}
		std::cout << *(Shapes.get_tail()) << std::endl;
	}
	

	std::cout << Shape::GetCount() << std::endl;
	
	Shapes.clean();
	
	
	
	std::cout << Shape::GetCount() << std::endl;

}