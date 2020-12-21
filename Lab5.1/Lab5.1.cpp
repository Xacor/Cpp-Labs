#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix matrA, matrB;
	double arrA[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	double arrB[] = { 7, 8, 9, 1, 2, 3 };

	matrA.Input(3, 3, arrA);
	matrA.Print();
	
	std::cout << "matrA trace= " << matrA.Trace() << '\n';
	
	matrB.Input(3, 2, arrB);
	matrB.Print();

	matrA.Mult(&matrB);
	std::cout << "matrA * matrB = \n";
	matrA.Print();

	matrB.Sum(arrB, 3, 2);
	std::cout << "matrB + matrB = \n";
	matrB.Print();

	std::cout << "matrB * arrB = \n";
	matrB.Mult(arrB, 2, 3);
	matrB.Print();
	
	return 0;
}

