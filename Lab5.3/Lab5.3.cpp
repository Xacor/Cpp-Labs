﻿#include <iostream>
#include "Matrix3d.h"

int main()
{
    Matrix3d matr1, matr2;
    std::cin >> matr1 >> matr2;
    std::cout << matr1 << matr2;
    std::cout << "-matr1\n" << -matr1;
    std::cout << "matr1 + matr2\n" << matr1 + matr2;
    std::cout << "matr1 - matr2\n" << matr1 - matr2;
    std::cout << "matr1 * matr2\n" << matr1 * matr2;
    std::cout << "matr1 * 3\n" << matr1 * 3;
    std::cout << "5 * matr2\n" << 5 * matr2;


}
