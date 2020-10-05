#include <iostream>
#include <bitset>
#include <limits>

int main() {

    std::cout << "1.\nRyabov Konstantin Dmitrievich, 201-351" << std::endl;

    std::cout << "2.\n" << "min int=" << INT_MIN << ','
        << " max int=" << INT_MAX << ','
        << " size of int=" << sizeof(int) << std::endl

        << "min unsigned int=" << 0 << ','
        << " max unsigned int=" << UINT_MAX << ','
        << " size of unsigned int=" << sizeof(unsigned int) << std::endl

        << "min short=" << SHRT_MIN << ','
        << " max short=" << SHRT_MAX << ','
        << " size of short" << sizeof(short) << std::endl

        << "min unsigned short=" << 0 << ','
        << " max unsigned short=" << USHRT_MAX << ','
        << "size of unsigned short=" << sizeof(unsigned short) << std::endl

        << "min long=" << LONG_MIN << ','
        << " max long=" << LONG_MAX << ','
        << " size of long=" << sizeof(long) << std::endl

        << "min long long=" << LLONG_MIN << ','
        << " max long long=" << LLONG_MAX << ','
        << " size of long long=" << sizeof(long long) << std::endl

        << "min double=" << DBL_MIN << ','
        << " max double=" << DBL_MAX << ','
        << " size of double=" << sizeof(double) << std::endl

        << "min char=" << CHAR_MIN << ','
        << " max char=" << CHAR_MAX << ','
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
    std::cout << "x = " << double(b)/a << std::endl;
    std::cout << "Ответ: " << double(b)/a << std::endl;

    std::cout << "5.\nВведите координаты отрезка на прямой: ";
    int x1, x2;
    std::cin >> x1 >> x2;
    std::cout << "Середина отрезка:" << (x1 + x2) / 2.;

    return 0;
}