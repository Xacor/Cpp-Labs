#include <iostream>

//auto SetArray(const size_t len) {
//    auto arr[len];
//    for (int i = 0; i < len; i++) {
//        std::cin << arr[i];
//    }
//}

void BoubleSort(int* arr, const size_t len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int buff = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buff;
            }
        }
    }
}

void PrintArray(int* arr, const size_t len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    while (1) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            std::cout << "Введите размер массива: ";
            

            BoubleSort(arr, len);
            PrintArray(arr, len);
            break;
        }
    }
}

