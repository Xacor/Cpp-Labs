#include <iostream>
#include <queue>
#include <algorithm>




void print_and_add(int t, std::queue<int>& q2, std::queue<int>& q3, std::queue<int>& q5) {
    if (t != 1) {
        std::cout << t << ' ';
    }
    q2.push(t * 2);
    q3.push(t * 3);
    q5.push(t * 5);
}


int main()
{
    std::cout << "Input number:\n";
    int n;
    std::cin >> n;

    std::queue<int> q2;
    std::queue<int> q3;
    std::queue<int> q5;


    q2.push(2);
    q3.push(3);
    q5.push(5);
    /*print_and_add(1, q2,  q3, q5);*/
    int k = 0; //счетчик выведенных чисел

    while (k != n) {
        int x = std::min({ q2.front(), q3.front(), q5.front() });
        print_and_add(x, q2, q3, q5);
        k++;
        if (x == q2.front())
            q2.pop();
        if (x == q3.front())
            q3.pop();
        if (x == q5.front())
            q5.pop();
    }
   
}

