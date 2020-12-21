#include "Matrix3d.h"

Matrix3d::Matrix3d()
{
	rows = 0;
	elements = nullptr;
}

Matrix3d::Matrix3d(const Matrix3d& src)
{
	this->rows = src.rows;
	this->elements = new double[rows * rows]{ 0 };

	for (int i = 0; i < rows * rows; i++)
		elements[i] = src.elements[i];
}

Matrix3d::Matrix3d(size_t l_rows)
{
	rows = l_rows;
	elements = new double[rows * rows]{ 0 };
}

Matrix3d::~Matrix3d()
{
	if (elements != nullptr)
		delete[] elements;
}

double Matrix3d::get_element(size_t row, size_t column)
{
	return elements[row * rows + column];
}

void Matrix3d::set_element(size_t row, size_t column, double argument)
{
	this->elements[row * rows + column] = argument;
}

int Matrix3d::get_rows()
{
	return this->rows;
}

void Matrix3d::Input()
{
	if (elements != nullptr)
		delete[] elements;
	std::cout << "Input number of rows:";
	std::cin >> rows;

	
	elements = new double[rows * rows]{ 0 };
	std::cout << "Input first diagonal:" << '\n';
	for (int i = 1; i < rows * rows; i+= rows +1)
		std::cin >> elements[i];

	std::cout << "Input main diagonal:" << '\n';
	for (int i = 0; i < rows * rows; i += rows + 1)
		std::cin >> elements[i];

	std::cout << "Input third diagonal:" << '\n';
	for (int i = rows; i < rows * rows; i += rows + 1)
		std::cin >> elements[i];
}

void Matrix3d::Print() 
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++)
			std::cout << get_element(i, j) << '\t';
		std::cout << std::endl;
	}
}

double Matrix3d::Trace()
{
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (i == j)
				sum += elements[i * rows + j];
		}
	}
	return sum;
}

std::ostream& operator<<(std::ostream& out, const Matrix3d& matr)
{
	out << "Rows = " << matr.rows << ' ' << "Columns = " << matr.rows << '\n';
	for (int i = 0; i < matr.rows; i++) {
		for (int j = 0; j < matr.rows; j++) {
			out << matr.elements[i * matr.rows + j] << '\t';
		}
		out << '\n';
	}
	return out;
}

std::istream& operator>> (std::istream& in, Matrix3d& matr)
{
	if (matr.elements != nullptr)
		delete[] matr.elements;
	std::cout << "Input number of rows:";
	in >> matr.rows;


	matr.elements = new double[matr.rows * matr.rows]{ 0 };
	std::cout << "Input first diagonal:" << '\n';
	for (int i = 1; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	std::cout << "Input main diagonal:" << '\n';
	for (int i = 0; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	std::cout << "Input third diagonal:" << '\n';
	for (int i = matr.rows; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	return in;
}

Matrix3d operator+(const Matrix3d& left, const Matrix3d& right)
{
	Matrix3d result(left);
	for (int i = 0; i < left.rows * left.rows; i++)
		result.elements[i] += right.elements[i];
	return result;
}

Matrix3d operator-(const Matrix3d& left, const Matrix3d& right)
{
	Matrix3d result(left);
	for (int i = 0; i < left.rows * left.rows; i++)
		result.elements[i] -= right.elements[i];
	return result;
}

const Matrix3d operator-(const Matrix3d& matr)
{
	Matrix3d result(matr);
	for (int i = 0; i < result.get_rows(); i++) {
		for (int j = 0; j < result.get_rows(); j++) {
			if (result.get_element(i, j) == 0)
				continue;
			result.set_element(i, j, -result.get_element(i, j));
		}
	}

	return result;
}



Matrix3d& Matrix3d::operator= (const Matrix3d& right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}

	this->rows = right.rows;
	delete[] this->elements;
	this->elements = new double[this->rows * this->rows];
	for (int i = 0; i < rows * rows; i++)
		this->elements[i] = right.elements[i];
	return *this;
}

Matrix3d operator*(const Matrix3d& left, const Matrix3d& right)
{
	
	Matrix3d result(left);

	for (int i = 0; i < left.rows; i++) {
		for (int j = 0; j < left.rows; j++) {
			double sum = 0;
			for (int k = 0; k < left.rows; k++) {
				double a = left.elements[i*left.rows+k];
				double b = right.elements[right.rows * k + j];
				sum += a * b;
			}
			result.set_element(i, j, sum);
		}
	}

	return result;
}

Matrix3d operator*(const Matrix3d& left, const int& right)
{
	Matrix3d result(left);

	for (int i = 1; i < left.rows * left.rows; i += left.rows + 1)
		result.elements[i] *= right;

	for (int i = 0; i < left.rows * left.rows; i += left.rows + 1)
		result.elements[i] *= right;

	for (int i = left.rows; i < left.rows * left.rows; i += left.rows + 1)
		result.elements[i] *= right;
	
	return result;
}

Matrix3d operator*(const int& left, const Matrix3d& right)
{
	Matrix3d result(right);

	for (int i = 1; i < right.rows * right.rows; i += right.rows + 1)
		result.elements[i] *= left;

	for (int i = 0; i < right.rows * right.rows; i += right.rows + 1)
		result.elements[i] *= left;

	for (int i = right.rows; i < right.rows * right.rows; i += right.rows + 1)
		result.elements[i] *= left;

	return result;
}
