#include "Matrix.h"

Matrix::Matrix()
{
	columns = 0;
	rows = 0;
	elements = nullptr;
}

Matrix::Matrix(size_t rows, size_t columns) 
{
	this->rows = rows;
	this->columns = columns;
	elements = new double[rows * columns]{ 0 };
}

Matrix::Matrix(size_t rows, size_t columns, const double* arr)
{
	this->rows = rows;
	this->columns = columns;
	elements = new double[rows * columns]{ 0 };
	for (int i = 0; i < rows * columns; i++) {
		elements[i] = arr[i];
	}

}

Matrix::~Matrix()
{
	if (elements != nullptr)
		delete[] elements;
}

double Matrix::get_element(size_t row, size_t column)
{
	return elements[row * columns + column];
}

void Matrix::set_element(size_t row, size_t column, double argument)
{
	this->elements[row * columns + column] = argument;
}

int Matrix::get_rows()
{
	return this->rows;
}

int Matrix::get_columns()
{
	return this->columns;
}

void Matrix::Input()
{
	std::cout << "Input number of rows:";
	std::cin >> rows;
	std::cout << "Input nimber of columns:";
	std::cin >> columns;
	if (elements != nullptr)
		delete[] elements;
	elements = new double[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		std::cin >> elements[i];
}

void Matrix::Input(size_t row, size_t column)
{
	rows = row;
	columns = column;
	if (elements != nullptr)
		delete[] elements;
	elements = new double[row * column];

	for (int i = 0; i < row * column; i++)
		std::cin >> elements[i];
}

void Matrix::Input(size_t row, size_t column, const double* arr)
{
	rows = row;
	columns = column;
	if (elements != nullptr)
		delete[] elements;
	elements = new double[row * column];
	for (int i = 0; i < row * column; i++)
		elements[i] = arr[i];
}

void Matrix::Print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) 
			std::cout << get_element(i, j) << '\t';
		std::cout << std::endl;
	}
}

double Matrix::Trace()
{
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j)
				sum += elements[i * columns + j];
		}
	}
	return sum;
}

bool Matrix::Sum(const Matrix* matr)
{
	if (rows != matr->rows || columns != matr->columns)
		return false;

	for (int i = 0; i < rows * columns; i++)
		elements[i] = elements[i] + matr->elements[i];
	
	return true;
}

void Matrix::Sum(const double* arr)
{
	for (int i = 0; i < this->columns * this->rows; i++) {
		elements[i] += arr[i];
	}
}


bool Matrix::Mult(const Matrix* matr)
{
	if (this->columns != matr->rows) 
		return false;
	
	Matrix result(this->rows, matr->columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < matr->columns; j++) {
			double sum = 0;
			for (int k = 0; k < this->columns; k++) {
				double a = this->get_element(i, k);
				double b = matr->elements[matr->columns*k + j]; 
				sum += a*b;
			}
			result.set_element(i, j, sum);	
		}
	}
	
	*this = result;
	return true;
}

void Matrix::MultByNum(double n)
{
	for (int i = 0; i < this->rows * this->columns; i++)
		this->elements[i] *= n;
}

void Matrix::Mult(const double* arr, size_t row, size_t col)
{
	Matrix result(this->rows, col);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < col; j++) {
			double sum = 0;
			for (int k = 0; k < this->columns; k++) {
				double a = this->get_element(i, k);
				double b = arr[col * k + j];
				sum += a * b;
			}
			result.set_element(i, j, sum);
		}
	}

	*this = result;
}

void Matrix::Copy(Matrix* right)
{
	this->columns = right->columns;
	this->rows = right->rows;
	delete[] this->elements;
	this->elements = new double[this->columns * this->rows];
	for (int i = 0; i < rows * columns; i++)
		this->elements[i] = right->elements[i];
}

Matrix& Matrix::operator= (const Matrix& right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}
	
	this->columns = right.columns;
	this->rows = right.rows;
	delete[] this->elements;
	this->elements = new double[this->columns * this->rows];
	for (int i = 0; i < rows * columns; i++)
		this->elements[i] = right.elements[i];
	return *this;
}



