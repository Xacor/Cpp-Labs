#include <iostream>
#include <bitset>
#include <limits>

int main() {

    std::cout << "1.\nRyabov Konstantin Dmitrievich, 201-351" << std::endl;

    std::cout << "2.\n" << "min int=" << std::numeric_limits<int>::min() << ','
        << " max int=" << std::numeric_limits<int>::max() << ','
        << " size of int=" << sizeof(int) << std::endl

        << "min unsigned int=" << std::numeric_limits<unsigned int>::min() << ','
        << " max unsigned int=" << std::numeric_limits<unsigned int>::max() << ','
        << " size of unsigned int=" << sizeof(unsigned int) << std::endl

        << "min short=" << std::numeric_limits<short>::min() << ','
        << " max short=" << std::numeric_limits<short>::max() << ','
        << " size of short" << sizeof(short) << std::endl

        << "min unsigned short=" << std::numeric_limits<unsigned short>::min() << ','
        << " max unsigned short=" << std::numeric_limits<unsigned short>::max() << ','
        << "size of unsigned short=" << sizeof(unsigned short) << std::endl

        << "min long=" << std::numeric_limits<long>::min() << ','
        << " max long=" << std::numeric_limits<long>::max() << ','
        << " size of long=" << sizeof(long) << std::endl

        << "min long long=" << std::numeric_limits<long long>::min() << ','
        << " max long long=" << std::numeric_limits<long long>::max() << ','
        << " size of long long=" << sizeof(long long) << std::endl

        << "min double=" << std::numeric_limits<double>::min() << ','
        << " max double=" << std::numeric_limits<double>::max() << ','
        << " size of double=" << sizeof(double) << std::endl

        << "min char=" << static_cast<int>(std::numeric_limits<char>::min()) << ','
        << " max char=" << static_cast<int>(std::numeric_limits<char>::max()) << ','
        << " size of char=" << sizeof(char) << std::endl

        << "min bool=" << std::numeric_limits<bool>::min() << ','
        << " max bool=" << std::numeric_limits<bool>::max() << ','
        << " size of bool=" << sizeof(bool) << std::endl;

    setlocale(LC_ALL, "Russian");
    std::cout << "3.\nВведите число: ";
    int n;
    std::cin >> n;

    std::cout << "В бинарном виде " << std::bitset<16>(n) << std::endl;


    std::cout << "В шестнадцатиричном виде " << std::hex << n << std::endl;
    std::cout << "bool " << bool(n) << std::endl;
    std::cout << "double " << double(n) << std::endl;
    std::cout << "char " << static_cast<char>(n) << std::endl;

    std::cout << "4.\nВведите коэффициенты a * x = b: ";
    int a, b;
    std::cin >> a >> b;

    std::cout << "x = " << b << '/' << a << std::endl;
    std::cout << "x = " << double(b) / double(a) << std::endl;
    std::cout << "Ответ: " << double(b) / double(a) << std::endl;

    std::cout << "5.\nВведите координаты отрезка на прямой: ";
    int x1, x2;
    std::cin >> x1 >> x2;
    std::cout << "Середина отрезка находится в точке с координатой " << (x2 + x1) / 2. << std::endl;

    return 0;
}