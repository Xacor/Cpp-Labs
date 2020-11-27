#include <cstring>
#include <iostream>

bool IsPalindrome(char* str) {								//функция проверки на палиндром
	int len = strlen(str);									//вычисляем длину строки 

	for (int i = 0, j = len - 1; i < j; i++, j--) {
		if (str[i] == ' ') i++;
		if (str[j] == ' ') j--;
		if (isupper(str[i])) str[i] = tolower(str[i]);
		if (isupper(str[j])) str[j] = tolower(str[j]);
		if (str[i] != str[j]) return false;
	}
	return true;
}



int* FindSubstring2(const char* str, const char* substr) {
	int buff[255] = { 0 };
	size_t buff_size = 0;

	int str_len = strlen(str);
	int substr_len = strlen(substr);

	int pos = 0;									//отвечает за кол-во подряд совпавших символов с подстрокой
	for (int i = 0; i < str_len + 1; i++) {			//проходим по всей строке
		if (str[i] == substr[pos]) pos++;			//если нашли ещё один совпавший символ, увеличиваем счетчик на 1

		else if (str[i] == substr[0]) pos = 1;		//если встретился первый символ из подстроки, присваиваем счетчику значение 1												

		else pos = 0;

		if (pos == substr_len) {
			buff[buff_size] = i - substr_len + 1;
			buff_size++;
		}
	}

	int* result = new int[buff_size + 1]{ 0 };
	for (int i = 0; i < buff_size + 1; i++) {
		result[i] = buff[i];
	}
	result[buff_size] = -1;

	return result;
}

int FindSubstring1(const char* str, const char* substr, int startposition) {
	int str_len = strlen(str);
	int substr_len = strlen(substr);

	int pos = 0;
	for (int i = startposition; i < str_len + 1; i++) {			//проходим по всей строке
		if (str[i] == substr[pos]) pos++;						//если нашли ещё один совпавший символ, увеличиваем счетчик на 1

		else if (str[i] == substr[0]) pos = 1;					//если встретился первый символ из подстроки, присваиваем счетчику значение 1												

		else pos = 0;

		if (pos == substr_len) {
			return i - substr_len + 1;
		}
	}
	return -1;
}

void Encrypt(char* str, int key) {
	int asccii_num = 0;																		//хранит номер символа в таблице аски с учетом сдвига
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isspace(str[i])) 
			continue;																		//если пробел, то пропускаем итерацию
		
		asccii_num = int(str[i]) + key;
		
		if (((asccii_num > 90) && (int(str[i]) <= 90)) || ((asccii_num > 122) && (int(str[i]) <= 122))) 	//если вышли за конец алфавита, то возвращаемся в начало
			asccii_num -= 26;																				//коррекция сдвига 
		
		str[i] = char(asccii_num);																			//ячейка массива принимает новое значение
	}
}

void AllNames(const char* str) {

	bool inquotes = false;

	for (int i = 0; i < strlen(str); i++) {					//проход по строке

		if (str[i] == '\"') {								//если символ является кавычкой

			if (inquotes) std::cout << std::endl;			//если до этого были в кавычках, переходим на новую строку
															//это нужно для отделения названий друг от друга
			inquotes = !inquotes;							//меняем inquotes на противоположное значение
			continue;
		}

		if (inquotes) {										//если внутри кавычек
			std::cout << str[i];							//выводим символ на печать
		}
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[255] = {};
    char substr[255] = {};
    int* pointer = nullptr;

    while (1) {
        std::cout << "1. Проверка на палиндром\n"
            << "2. Вывод всех вхождений\n"
            << "3. Шифр Цезаря\n"
            << "4. Вывод всех названий\n"
            << "5. Выход\n";
        int cmd;
        std::cin >> cmd;

        switch (cmd) {       
        
        case 1:
            std::cout << "Введите строку: \n";
            std::cin.get();
            std::cin.getline(str, 255);
            
            if (IsPalindrome(str)) printf("Строка является палиндромом\n");               //проверка на палиндром        
            else printf("Строка не является палиндромом\n");
            break;
        
        case 2:
			
            std::cout << "Введите строку: \n";
            std::cin.get();
            std::cin.getline(str, 255);

            std::cout << "Введите подстроку: \n";
            std::cin.getline(substr, 255);

            pointer = FindSubstring2(str, substr);
			int* adr;																	//используется для очищения памяти
			adr = pointer;
            while (*pointer != -1) {                                                      //вывод индексов начала вхождения
                std::cout << *pointer << " ";
                pointer++;
            }
			delete[] adr;
            std::cout << std::endl;
            break;
       
        case 3:
            std::cout << "Введите строку: \n";
            std::cin.get();
            std::cin.getline(str, 255);
            
            int key;
            std::cout << "Введите сдвиг: ";
            std::cin >> key;
            
            Encrypt(str, key);
            
            std::cout << str << std::endl;
            break;
        
        case 4:
            std::cout << "Введите строку: \n";
            std::cin.get();
            std::cin.getline(str, 255);
            
            AllNames(str);
            break;
        
        case 5:
            return 0;
        }
    }
}

