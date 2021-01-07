#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

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

    while (q2.size() + q3.size() + q5.size() < n) { //пока не найдено достаточно чисел
        int min = std::min({ q2.back(), q3.back(), q5.back() }); //находим минимальное последнее число в очередях
        
        if (min = q2.back())
            q2.push(std::min({ min * 2, min * 3, min * 5 })); //запоминание нового числа
        
        if (min = q3.back())
            q3.push(std::min({ min * 2, min * 3, min * 5 }));
        
        if (min = q5.back())
            q5.push(std::min({ min * 2, min * 3, min * 5 }));
    }
    
    std::vector<int> result;
    int k = q2.size();
    for (int i = 0; i < k; i++) {
        result.push_back(q2.front());
        q2.pop();

        result.push_back(q3.front());
        q3.pop();

        result.push_back(q5.front());
        q5.pop();
    }
    std::sort(result.begin(), result.end());
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << '\n';
    }
    return 0;
}

