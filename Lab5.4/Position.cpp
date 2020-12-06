#include "Position.h"

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(double l_x, double l_y)
{
	x = l_x;
	y = l_y;
}

Position::~Position()
{
}

double Position::get_x()
{
	return x;
}

double Position::get_y()
{
	return y;
}

void Position::set_x(double l_x)
{
	x = l_x;
}

void Position::set_y(double l_y)
{
	y = l_y;
}
