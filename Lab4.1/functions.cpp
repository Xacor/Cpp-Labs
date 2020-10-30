#include "functions.h"
#include <cstring>
#include <iostream>
#include <algorithm>

void SetString(char*& str, size_t* length) {				//функци€ ввода строки
	if (str != nullptr) delete[] str;						//очистка пам€ти

	std::cout << "–азмер строки: ";
	std::cin >> *length;
	str = new char[*length+1];
	std::cin.ignore();										//пропускаем символ конца ввода
	std::cin.getline(str, *length+1);
}

void AllTolower(char* str) {								//переводит все символы в нижний регистр
	for (int i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}

void EraseSpace(char*& str) {						//удал€ет пробелы из строки и сдвигает строку влево, уменьша€ еЄ размер
	size_t len = strlen(str);						//двигаем null справа налево уменьша€ размер
	for (int i = 0; i < len; i++) {
		if (isspace(str[i])) {
			for (int j = i; j < len; j++) {
				str[j] = str[j + 1];
			}
		}
	}
}

bool IsPalindrome(char* str) {								//функци€ проверки на палиндром
	EraseSpace(str);										//удал€ем все пробелы
	AllTolower(str);										//переводи все в нижний регистр
	size_t len = strlen(str);								//вычисл€ем длину получившейс€ строки 
	
	for (int i = 0; i < len / 2 + 1; i++) {
		if (str[i] != str[len - i - 1])	return false;		//если не совпадает iый и iый с конца элемент, то строка не палиндром				
	}
	return true;											//если дошли до конца, значит строка палиндром
}

void CopyArr(int* dest,int length ,int* src) {				//функи€ копировани€ одного массива в другой
	for (int j = 0; j < length; j++) {
		dest[j] = src[j];
	}
}

int* Find(const char* str, const char* substr) {
	int len = strlen(str);							//длина строки
	int sublen = strlen(substr);					//длина подстроки
	int* result = nullptr;							//объ€вл€ю массив дл€ результата
	int ressize = 0;								//размер массива дл€ результата
	int pos = 0;									//отвечает за кол-во подр€д совпавших символов с подстрокой
	for (int i = 0; i < len+1; i++) {				//проходим по всей строке
		if (str[i] == substr[pos]) pos++;			//если нашли ещЄ один совпавший символ, увеличиваем счетчик на 1
		else if (str[i] == substr[0]) pos = 1;		//если встретилс€ первый символ из подстроки, присваиваем счетчику значение 1												
		else pos = 0;								//если это не символ из подстроки, обнул€ем счетчик

		if (pos == sublen) {
			
			int* tmp = new int[ressize];			//создаю буферный массив, чтоб не потер€ть значени€ из result во врем€ выделени€ пам€ти
			CopyArr(tmp, ressize, result);
			
			ressize++;
			result = new int[ressize];				//выдел€ю новую пам€ть под result
			
			CopyArr(result, ressize, tmp);
			
			result[ressize - 1] = i+1-sublen;		//записываю в result индекс начала вхождени€ подстроки
			delete[] tmp;							//освобождаю пам€ть
			pos = 0;
		}
	}
	int* tmp = new int[ressize];
	CopyArr(tmp, ressize, result);
	
	delete[] result;
	ressize++;
	result = new int[ressize];
	
	CopyArr(result, ressize, tmp);
	result[ressize - 1] = -1;						//записываю -1 в конце result, чтобы знать когда остановитьс€ в main
	delete[] tmp;
	return result;
}

void Encrypt(char* str, int key) {
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char* begin = alphabet;										//указатель на начало алфавита
	char* end = alphabet + sizeof(alphabet);					//указатель на конец алфавита
	EraseSpace(str);
	for (int i = 0; i < strlen(str); i++) {
		char* ch = std::find(begin, end, str[i]);				
		if (ch != end) 
			str[i] = *(begin + (ch - begin + key) % sizeof(alphabet));
	}
}

void AllNames(const char* str) {
	
	bool inquotes = false;									

	for (int i = 0; i < strlen(str); i++) {					//проход по строке
		
		if (str[i] == '\"') {								//если символ €вл€етс€ кавычкой
			
			if (inquotes) std::cout << std::endl;			//если до этого были в кавычках, переходим на новую строку
															//это нужно дл€ отделени€ названий друг от друга
			inquotes = !inquotes;							//мен€ем inquotes на противоположное значение
			continue;
		}

		if (inquotes) {										//если внутри кавычек
			std::cout << str[i];							//выводим символ на печать
		}
	}
}