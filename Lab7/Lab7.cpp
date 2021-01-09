#include <iostream>
#include <vector>
#include <string>
#include "Human.h"



template < class C>
class Container 
{

};


void QuickSort(const std::vector<int>::iterator start, const std::vector<int>::iterator end)
{   
    std::vector<int>::iterator left = start;
    std::vector<int>::iterator right = end;
    std::vector<int>::iterator pivot = left + (right - left) / 2; //указатель на центальный элемент
    int tmp;
    while (left <= right) {
        while (*left < *pivot)
            left++;
        while (*right > *pivot)
            right--;
    
       /* tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;

        if (right > start)
            QuickSort(start, right);
        if (left < end)
            QuickSort(left, end);*/
    }
}

int main()
{
    std::vector<int> a = { 5, 1, 8, 6, 3, 0, 4 };
    QuickSort(a.begin(), a.end()-1);

    std::cout << "jopa";
}
