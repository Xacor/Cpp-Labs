#include <iostream>
#include <vector>
#include <string>
#include "Human.h"

bool CompareSurname(Human left, Human right) { //сравнение по Human фамилии
    return left.get_surname() < right.get_surname();
}

bool CompareName(Human left, Human right) { //сравнение по Human имени
    return left.get_name() < right.get_name(); 
}

bool CompareAge(Human left, Human right) { //сравнение по Human возрасту
    return left.get_age() < right.get_age(); 
}


template <typename T>
bool Compare(T left, T right) { //сравнение встроенных типов
    return left < right;
} 

template <typename C>
void QuickSort(std::vector<C>& vect, int start, int finish, bool (*Cmp)(C, C)/*указатель на функцию, чтобы передавать компаратор в качестве аргумента*/) //быстрая сортировка
{   
    int left = start;
    int right = finish;
    C middle = vect[(start + finish) / 2];
    C temp;

    while (left < right)
    {
        while (Cmp(vect[left], middle))
            left++;
        while (Cmp(middle, vect[right]))
            right--;
        if (left <= right)
        {
            temp = vect[left];
            vect[left] = vect[right];
            vect[right] = temp;
            left++;
            right--;

        }
    }
    if (right > start)
        QuickSort(vect, start, right, Cmp);
    if (left < finish)
        QuickSort(vect, left, finish, Cmp);
}


int main()
{
    std::vector<Human> a = {
        Human("Ivanov", "Ivan", 20),
        Human("Riabov", "Konstantin", 18),
        Human("Nikolaev", "Vladislav", 19),
        Human("Petrov", "Victor", 42)
    };

    std::vector<Human> b = a;
    std::vector<Human> c = a;
    std::vector<double> d = { 4.1, 8.2, 1, 0, 9.45, 7 };
    std::vector<std::string> f = { "Apple", "Pineapple", "AXYZ" };
    
    
    QuickSort(a, 0, a.size()-1, CompareSurname);
    std::cout << "Sorted by surname vector of Human:\n";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << '\n';

    QuickSort(b, 0, b.size() - 1, CompareName);
    std::cout << "Sorted by name vector of Human:\n";
    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << '\n';

    QuickSort(c, 0, c.size() - 1, CompareAge);
    std::cout << "Sorted by age vector of Human:\n";
    for (int i = 0; i < c.size(); i++)
        std::cout << c[i] << '\n';

    QuickSort(d, 0, d.size() - 1, Compare);
    std::cout << "Sorted vector of double:\n";
    for (int i = 0; i < d.size(); i++)
        std::cout << d[i] << ' ';
    std::cout << '\n';

    QuickSort(f, 0, f.size() - 1, Compare);
    std::cout << "Sorted vector of std::string:\n";
    for (int i = 0; i < f.size(); i++)
        std::cout << f[i] << ' ';
    std::cout << '\n';
    
}
