#pragma once
class Position
{
protected:
	double x;
	double y;

public:
	Position();
	Position(double l_x, double l_y);
	~Position();

	double get_x();
	double get_y();

	void set_x(double l_x);
	void set_y(double l_y);
};

