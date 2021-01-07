#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>


bool Palindrome(std::string& str) { //функция вычисления палиндрома
	std::deque<char> deq;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ')
			deq.push_back(std::tolower(str[i])); //добавление в дек элементов строки в нижнем регистре
	}

	for (int i = 0; i < str.length() / 2; i++) { //проход по деку
		if (deq.front() != deq.back()) //если первый и последний элемент не совпадает, значит строка не является палиндромом
			return false;
		else {	//если первый и последний элемент не совпадает, удаляем из дека
			deq.pop_back();
			deq.pop_front();
		}
	}
	return true;
}

int vect_mult(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) { //z координата векторного произведения 
	return ((b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first));
}

std::deque<std::pair<int, int>> Graham(std::vector<std::pair<int, int>> cords) {
	std::deque<std::pair<int, int>> shell;
	std::pair<int, int> p0 = *(std::min_element(cords.begin(), cords.end(), [](std::pair<int, int> a, std::pair<int, int> b) { //находим стартовую точку, самая нижня среди левых
		return (a.first < b.first || (a.first == b.first && a.second < b.second)) ;
		}));
	shell.push_back(p0);
	cords.erase(std::find(cords.begin(), cords.end(), p0));
	
	std::sort(cords.begin(), cords.end(), [p0](std::pair<int, int> a, std::pair<int, int> b) { //сортировка точек через лямбда функцию по величине полярного угла относительно p0
		float angle_a = std::atan(float(a.second - p0.first) / (a.first - p0.first));
		float angle_b = std::atan(float(b.second - p0.first) / (b.first - p0.first));
		return (angle_a < angle_b);
		});
	

	shell.push_back(cords[0]); //добавление второй опорной точки в дек
	cords.erase(cords.begin());//удаление ее из входного вектора


	for (auto it = cords.begin(); it != cords.end(); it++) { 
		if (vect_mult(*(shell.end() - 2), shell.back(), *it) >= 0) { //если левый поворот, то добавляем в дек
			shell.push_back(*it);
		}
		else {
			while (vect_mult(*(shell.end()-2), shell.back(), *it) < 0){ //если правый поворот, то удаляем последний элемент дека до тех пор, пока поворот не станет левым
				shell.pop_back();
			}
			shell.push_back(*it);
		}

	}
	return shell;
}

int main()
{
	while (true) {
		std::string str;
		std::vector<std::pair<int, int>> cords; //vector пар, в которых первое значение - х, а второе - у
		std::deque<std::pair<int, int>> shell;
		int x, y = 0;
		int n;
		int cmd;
		std::cout << "1. Palindrome\n"
			<< "2. Graham's scan\n"
			<< "3. Exit\n"
			<< "Input option:";
		std::cin >> cmd;

		switch (cmd)
		{
		case 1:
			std::cout << "Input string: ";
			std::getchar();
			std::getline(std::cin, str); //getline для того, чтобы считывать с пробелами
			Palindrome(str) == true ? std::cout << "Yes\n" : std::cout << "No\n";
			break;
		case 2:
			std::cout << "Input number of points: ";
			std::cin >> n;

			for (int i = 0; i < n; i++) {
				std::cin >> x >> y;
				cords.push_back(std::make_pair(x, y));
			}

			shell = Graham(cords);

			for (auto it = shell.begin(); it != shell.end(); it++)
				std::cout << it->first << ' ' << it->second << '\n';

			break;
		case 3:
			return 0;
		}


	}
}


