#pragma once
#include <iostream>

class Matrix3d
{
private:
	size_t rows;
	double* elements;
public:
	Matrix3d();
	Matrix3d(const Matrix3d& src);
	Matrix3d(size_t rows);
	~Matrix3d();

	double get_element(size_t row, size_t column);
	void set_element(size_t row, size_t column, double argument);

	int get_rows();

	void Input();
	void Print();

	double Trace();


	
	friend std::ostream& operator<< (std::ostream& out, const Matrix3d& matr);
	friend std::istream& operator>> (std::istream& in, Matrix3d& matr);

	friend Matrix3d operator+(const Matrix3d& left, const Matrix3d& right);
	friend Matrix3d operator-(const Matrix3d& left, const Matrix3d& right);
	
	friend Matrix3d operator*(const Matrix3d& left, const Matrix3d& right);
	friend Matrix3d operator*(const Matrix3d& left, const int& right);
	friend Matrix3d operator*(const int& left, const Matrix3d& right);

	Matrix3d& operator=(const Matrix3d& right);
	
};

const Matrix3d operator-(const Matrix3d& matr);
