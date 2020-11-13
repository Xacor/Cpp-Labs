#include "functions.h"
#include <cstring>
#include <iostream>


bool IsPalindrome(char* str) {								//������� �������� �� ���������
	int len = strlen(str);									//��������� ����� ������ 

	for (int i = 0, j = len-1; i < j; i++, j--) {
		if (str[i] == ' ') i++;				
		if (str[j] == ' ') j--;
		if (isupper(str[i])) str[i] = tolower(str[i]);
		if (isupper(str[j])) str[j] = tolower(str[j]);
		if (str[i] != str[j]) return false;
	}
	return true;											
}



int* FindSubstring2(const char* str, const char* substr) {
	int buff[255] = { -1 };
	int buff_size = 0;

	int str_len = strlen(str);
	int substr_len = strlen(substr);

	int pos = 0;									//�������� �� ���-�� ������ ��������� �������� � ����������
	for (int i = 0; i < str_len + 1; i++) {			//�������� �� ���� ������
		if (str[i] == substr[pos]) pos++;			//���� ����� ��� ���� ��������� ������, ����������� ������� �� 1

		else if (str[i] == substr[0]) pos = 1;		//���� ���������� ������ ������ �� ���������, ����������� �������� �������� 1												

		else pos = 0;

		if (pos == substr_len) {
			buff[buff_size] = i - substr_len + 1;
			buff_size++;
		}
	}

	int* result = new int[buff_size+1];
	for (int i = 0; i < buff_size + 1; i++) {
		result[i] = buff[i];
	}
	result[buff_size ] = -1;

	return result;
}

int FindSubstring1(const char* str, const char* substr, int startposition) {
	int str_len = strlen(str);
	int substr_len = strlen(substr);

	int pos = 0;
	for (int i = startposition; i < str_len + 1; i++) {			//�������� �� ���� ������
		if (str[i] == substr[pos]) pos++;						//���� ����� ��� ���� ��������� ������, ����������� ������� �� 1

		else if (str[i] == substr[0]) pos = 1;					//���� ���������� ������ ������ �� ���������, ����������� �������� �������� 1												

		else pos = 0;

		if (pos == substr_len) {
			return i - substr_len + 1;
		}
	}
}

void Encrypt(char* str, int key) {
	/*char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char* begin = alphabet;										//��������� �� ������ ��������
	char* end = alphabet + sizeof(alphabet);					//��������� �� ����� ��������
	for (int i = 0; i < strlen(str); i++) {

		if (!isspace(str[i])) {

			char* ch = std::find(begin, end, str[i]);

				if (ch != end)
				str[i] = *(begin + (ch - begin + key) % sizeof(alphabet));
		}
	}*/
	int asccii_num = 0;										//������ ����� ������� � ������� ���� � ������ ������
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isspace(str[i])) {								//���� ������ �� ���������� ��������
			continue;
		}
		asccii_num = int(str[i]) + key;
		if (((asccii_num > 90) && (int(str[i]) <= 90))  || ((asccii_num > 122) && (int(str[i]) <= 122))) {
			asccii_num -= 26;								//��������� ������ � ���������� ��������
		}
		str[i] = char(asccii_num);							//������ ������� ����������� ����� ��������
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