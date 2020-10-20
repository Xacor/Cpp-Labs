#include <iostream>

const size_t len = 1000;

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

template < typename T >
void PrintArray(T* arr, const size_t n) {
    for (int i = len - n; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void CountSort(char* arr, const size_t len) {
    const int k = 26;
    int counter[k] = { 0 };
    for (int i = 0; i < len; i++) {
        counter[int(arr[i] - 'a')]++;
    }
    int pos = 0;
    int j = 0;
    while (j <= k) {
        if (counter[j] > 0) {
            arr[pos] = char(int('a') + j);
            pos++;
            counter[j]--;
        }
        else {
            j++;
        }
    }
}

void Merge(int arr[], const int left, const int mid, const int right) {
    const int size1 = mid - left + 1;
    const int size2 = right - mid;
    int up[len / 2], down[len - len / 2];

    for (int i = 0; i < size1; i++) {
        up[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        down[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < size1 && j < size2) {
        if (up[i] <= down[j]) {
            arr[k] = up[i];
            i++;
        }
        else {
            arr[k] = down[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = up[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = down[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], const int left, const int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    while (1) {
        int cmd;
        std::cout << "Выберите команду:\n"
            << "1.Сортировка пузырьком\n"
            << "2.Сортировка подсчетом\n"
            << "3.Сортировка слиянием\n"
            << "4.Выход\n";
        std::cin >> cmd;


        if (cmd == 1) {
            int n = 0;
            std::cout << "Размер массива: ";
            std::cin >> n;

            int arr[len] = { 0 };
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }

            BoubleSort(arr, len);
            PrintArray(arr, n);
        }

        if (cmd == 2) {
            int n = 0;
            std::cout << "Размер массива: ";
            std::cin >> n;

            char arr[len] = { ' ' };
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }

            CountSort(arr, len);
            PrintArray(arr, n);
        }

        if (cmd == 3) {
            int n = 0;
            std::cout << "Размер массива: ";
            std::cin >> n;

            int arr[len] = { 0 };
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }

            MergeSort(arr, 0, len - 1);
            PrintArray(arr, n);
        }

        if (cmd == 4) {
            return 0;
        }
    }
}

