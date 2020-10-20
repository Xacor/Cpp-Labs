#include <iostream>
#include "funcs.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    size_t length = 0;
    int* arr = nullptr;

    while (1) {
        std::cout << "1.Ввод массива\n"
            << "2.Вывод массива в консоль\n"
            << "3.Сортировка по сумме цифр, стоящих на четных местах\n"
            << "4.Отсортировать массив по возрастанию последней цифры\n"
            << "5.Выход\n";
        int cmd;
        std::cin >> cmd;

        switch (cmd) {
        case 1:
            SetArray(arr, &length);
            break;
        case 2:
            PrintArray(arr, &length);
            break;
        case 3:
            DigitSumSort(arr, &length);
            break;
        case 4:
            LastDigitSort(arr, &length);
            break;
        case 5:
            delete[] arr;
            return 0;       
        default:
            break;
        }
    }
}

