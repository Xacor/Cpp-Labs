#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix matrA, matrB;
	double arrA[] = { 1, 2, 3, 4, 5, 6};
	double arrB[] = { 7, 8, 9, 1, 2, 3 };
	matrA.Input(3, 2, arrA);
	matrB.Input(2, 3, arrB);

	matrA.Mult(&matrB);
	matrA.Print();
	
	return 0;
}

