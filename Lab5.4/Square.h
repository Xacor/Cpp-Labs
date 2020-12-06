#pragma once
#include "Position.h"

class Square :
    virtual public Position
{
protected:
    double size;

public:
    Square();
    Square(double l_x, double l_y, double l_size);
    Square(double l_size);
    ~Square();

    void set_size(double l_size);
    double get_size();
};

