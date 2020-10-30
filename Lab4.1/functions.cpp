#include "functions.h"
#include <cstring>
#include <iostream>
#include <algorithm>

void SetString(char*& str, size_t* length) {				//������� ����� ������
	if (str != nullptr) delete[] str;						//������� ������

	std::cout << "������ ������: ";
	std::cin >> *length;
	str = new char[*length+1];
	std::cin.ignore();										//���������� ������ ����� �����
	std::cin.getline(str, *length+1);
}

void AllTolower(char* str) {								//��������� ��� ������� � ������ �������
	for (int i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}

void EraseSpace(char*& str) {						//������� ������� �� ������ � �������� ������ �����, �������� � ������
	size_t len = strlen(str);						//������� null ������ ������ �������� ������
	for (int i = 0; i < len; i++) {
		if (isspace(str[i])) {
			for (int j = i; j < len; j++) {
				str[j] = str[j + 1];
			}
		}
	}
}

bool IsPalindrome(char* str) {								//������� �������� �� ���������
	EraseSpace(str);										//������� ��� �������
	AllTolower(str);										//�������� ��� � ������ �������
	size_t len = strlen(str);								//��������� ����� ������������ ������ 
	
	for (int i = 0; i < len / 2 + 1; i++) {
		if (str[i] != str[len - i - 1])	return false;		//���� �� ��������� i�� � i�� � ����� �������, �� ������ �� ���������				
	}
	return true;											//���� ����� �� �����, ������ ������ ���������
}

void CopyArr(int* dest,int length ,int* src) {				//������ ����������� ������ ������� � ������
	for (int j = 0; j < length; j++) {
		dest[j] = src[j];
	}
}

int* Find(const char* str, const char* substr) {
	int len = strlen(str);							//����� ������
	int sublen = strlen(substr);					//����� ���������
	int* result = nullptr;							//�������� ������ ��� ����������
	int ressize = 0;								//������ ������� ��� ����������
	int pos = 0;									//�������� �� ���-�� ������ ��������� �������� � ����������
	for (int i = 0; i < len+1; i++) {				//�������� �� ���� ������
		if (str[i] == substr[pos]) pos++;			//���� ����� ��� ���� ��������� ������, ����������� ������� �� 1
		else if (str[i] == substr[0]) pos = 1;		//���� ���������� ������ ������ �� ���������, ����������� �������� �������� 1												
		else pos = 0;								//���� ��� �� ������ �� ���������, �������� �������

		if (pos == sublen) {
			
			int* tmp = new int[ressize];			//������ �������� ������, ���� �� �������� �������� �� result �� ����� ��������� ������
			CopyArr(tmp, ressize, result);
			
			ressize++;
			result = new int[ressize];				//������� ����� ������ ��� result
			
			CopyArr(result, ressize, tmp);
			
			result[ressize - 1] = i+1-sublen;		//��������� � result ������ ������ ��������� ���������
			delete[] tmp;							//���������� ������
			pos = 0;
		}
	}
	int* tmp = new int[ressize];
	CopyArr(tmp, ressize, result);
	
	delete[] result;
	ressize++;
	result = new int[ressize];
	
	CopyArr(result, ressize, tmp);
	result[ressize - 1] = -1;						//��������� -1 � ����� result, ����� ����� ����� ������������ � main
	delete[] tmp;
	return result;
}

void Encrypt(char* str, int key) {
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char* begin = alphabet;										//��������� �� ������ ��������
	char* end = alphabet + sizeof(alphabet);					//��������� �� ����� ��������
	EraseSpace(str);
	for (int i = 0; i < strlen(str); i++) {
		char* ch = std::find(begin, end, str[i]);				
		if (ch != end) 
			str[i] = *(begin + (ch - begin + key) % sizeof(alphabet));
	}
}

void AllNames(const char* str) {
	
	bool inquotes = false;									

	for (int i = 0; i < strlen(str); i++) {					//������ �� ������
		
		if (str[i] == '\"') {								//���� ������ �������� ��������
			
			if (inquotes) std::cout << std::endl;			//���� �� ����� ���� � ��������, ��������� �� ����� ������
															//��� ����� ��� ��������� �������� ���� �� �����
			inquotes = !inquotes;							//������ inquotes �� ��������������� ��������
			continue;
		}

		if (inquotes) {										//���� ������ �������
			std::cout << str[i];							//������� ������ �� ������
		}
	}
}