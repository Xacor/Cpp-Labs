#include "CircleInSquare.h"

CircleInSquare::CircleInSquare() : Position(), Circle(), Square()
{
}

CircleInSquare::CircleInSquare(double l_x, double l_y, double l_radius, double l_size)
{
	x = l_x;
	y = l_y;
	radius = l_radius;
	size = l_size;
}

CircleInSquare::~CircleInSquare()
{
}
