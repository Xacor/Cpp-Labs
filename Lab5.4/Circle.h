#pragma once
#include "Position.h"

class Circle :
    virtual public Position
{
protected:
    double radius;
    
public:
    Circle();
    Circle(double l_x, double l_y, double l_radius);
    Circle(double l_radius);
    ~Circle();

    void set_radius(double l_radius);
    double get_radius();
};

