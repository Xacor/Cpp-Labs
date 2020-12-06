#include "Position.h"
#include "Circle.h"
#include "CircleInSquare.h"
#include <iostream>

int main()
{
    CircleInSquare a(1, 2, 3, 4);
    std::cout << a.get_x() << '\n'
        << a.get_y() << '\n' 
        << a.get_radius() << '\n'
        << a.get_size();
}

