#include "Circle.h"

Circle::Circle() : Position()
{
	radius = 0;
}

Circle::Circle(double l_x, double l_y, double l_radius) : Position(l_x, l_y)
{
	radius = l_radius;
}

Circle::Circle(double l_radius) : Position()
{
	radius = l_radius;
}

Circle::~Circle()
{
}

void Circle::set_radius(double l_radius)
{
	radius = l_radius;
}

double Circle::get_radius()
{
	return radius;
}
