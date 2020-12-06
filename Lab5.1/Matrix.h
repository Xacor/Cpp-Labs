#pragma once
#include <iostream>
#include <fstream>
#include <iterator>
	
class Matrix
{
private:
	size_t rows;
	size_t columns;
	double* elements;
public:
	Matrix();
	Matrix(size_t rows, size_t columns);
	Matrix(size_t rows, size_t columns,const double* arr);

	~Matrix();

	double get_element(size_t row, size_t column);
	void set_element(size_t row, size_t column, double argument);

	int get_rows();
	int get_columns();

	void Input();
	void Input(size_t row, size_t column);
	void Input(size_t row, size_t column, const double* arr);
	void Print();
	
	bool Sum(const Matrix* matr);
	void Sum(const double* arr);

	double Trace();

	bool Mult(const Matrix* matr);
	void Mult(const double* arr, size_t row, size_t col);
	void MultByNum(double n);

	void Copy(const Matrix* right);
	Matrix& operator=(const Matrix& right);
	
};


