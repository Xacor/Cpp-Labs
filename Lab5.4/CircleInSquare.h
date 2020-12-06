#pragma once
#include "Circle.h"
#include "Square.h"
class CircleInSquare :
	public Circle, 
	public Square
{

public:
	CircleInSquare();
	CircleInSquare(double l_x, double l_y, double l_radius, double l_size);
	~CircleInSquare();
};

