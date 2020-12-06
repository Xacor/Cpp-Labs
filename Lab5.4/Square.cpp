#include "Square.h"

Square::Square() : Position()
{
	size = 0;
}

Square::Square(double l_x, double l_y, double l_size) : Position()
{
	size = l_size;
}

Square::Square(double l_size) : Position()
{
	size = l_size;
}

Square::~Square()
{
}

void Square::set_size(double l_size)
{
	size = l_size;
}

double Square::get_size()
{
	return size;
}
