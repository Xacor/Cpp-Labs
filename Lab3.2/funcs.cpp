#include "funcs.h"
#include <iostream>
#include <cmath>
#include <random>

void SetArray(int*& arr, size_t* length) {
	if (arr != nullptr) delete[] arr;

	std::cout << "������ �������: ";
	std::cin >> *length;
	arr = new int[*length];
	std::random_device rd;		// non-deterministic generator
	std::mt19937 gen(rd());		//��������� ��������� �����
	std::uniform_int_distribution<> dist(0, 10000);
	for (int i = 0; i < *length; i++) {
		//std::cin >> arr[i];
		arr[i] = dist(gen);
	}
}

void PrintArray(const int* arr, const size_t* length) {
	for (int i = 0; i < *length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int DigitSum(const int* n) {	//������� ����� ����, ������� �� ������ ��������
	int result = 0;
	int buff = *n;
	int k = 0;			//���-�� �������� � ����� n
	while (buff > 0) {
		buff /= 10;		//������� ���-�� ��������
		k++;
	}

	for (int i = 1; i < k; i += 2) {				//�������� ����� ������� � i ������� � ���������� � 
		result += (*n / int(pow(10, i))) % 10;		//pow(10,i) �������� 10 � ������� i
	}
	return result;
}   

void DigitSumSort(int* arr, const size_t* length) {	//����������� ���������� �� ����� ����, ������� � ������ ��������
	for (int i = 0; i < *length; i++) {
		for (int j = 0; j < *length - i - 1; j++) {
			if (DigitSum(&arr[j]) > DigitSum(&arr[j + 1])) {		
				int buff = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

void LastDigitSort(int* arr, const size_t* length) {
	for (int i = 0; i < *length; i++) {
		for (int j = 0; j < *length - i - 1; j++) {
			if (arr[j] % 10 > arr[j + 1] % 10) {	//���������� ��������� �� ��������� �����
				int buff = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = buff;
			}
			else if ((arr[j] % 10 == arr[j + 1] % 10) && (arr[j] < arr[j+1]))  {	//������� ��� ���������� �� ��������, � ������ ���������� ����
				int buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
		}
	}
}