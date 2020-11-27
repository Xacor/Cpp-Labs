#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix matrA, matrB;
	matrA.Input();
	matrB.Input();

	std::cout << matrA << '\n' << matrB << '\n';

	double arr[4] = { 0, 1, 2, 3 };
	Matrix mymatr(2, 2, arr);
	std::cout << mymatr;

	matrA.Mult(arr, 2, 2);
	std::cout << matrA << '\n';

	matrB.Sum(arr);
	std::cout << matrB << '\n';
	
	matrA.MultByNum(2);
	std::cout << "matrA * 2 \n" << matrA;

	matrA.Mult(&matrB);
	std::cout << "matrA * matrB \n" << matrA;

	matrA.Sum(&matrB);
	std::cout << "matrA + matrB \n" << matrA;

	std::cout << "matrA trace is " << matrA.Trace() << '\n';
	return 0;
}

