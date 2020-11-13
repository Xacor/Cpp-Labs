#include <cstring>
#include <iostream>
#include <Windows.h>
#include "functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);                                                             // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    size_t length = 0;
    char* str = nullptr;

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
            SetString(str, &length);
            char buff[255];
            strcpy_s(buff, 255, str);
            
            if (IsPalindrome(buff))                                                 //проверка на палиндром
                printf("Строка является палиндромом\n");        
            else 
                printf("Строка не является палиндромом\n");
            break;
        
        case 2:          
            size_t sublength;
            sublength = 0;
            char* substr;
            substr = nullptr;
            SetString(str, &length);
            SetString(substr, &length);
            
            int* p;
            p = Find(str, substr);
            
            while (*p != -1) {                                                      //вывод индексов начала вхождения
                std::cout << *p << " ";
                p++;
            }
            std::cout << std::endl;

            break;
        case 3:
            SetString(str, &length);
            int key;
            std::cout << "Введите сдвиг: ";
            std::cin >> key;
            Encrypt(str, key);
            std::cout << str << std::endl;
            break;
        case 4:
            SetString(str, &length);
            AllNames(str);
            break;
        case 5:
            delete[] str;
            return 0;
        }
    }
}

