#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>


int main()
{
	std::list<std::pair<int, std::string>> students;
	std::ifstream input("students.txt");
	if (input.is_open()) {
		std::string line;
		while (!input.eof()) { //чтение списка из текстового файла
			int group;
			std::string surname;
			input >> group >> surname;
			students.push_back(std::make_pair(group, surname));
		}
	} else std::cout << "File not found" << '\n';

	students.sort( //сортировка списка по номеру группы через лямда функцию
		[](std::pair<int, std::string> a, std::pair<int, std::string> b) {
			return (a.first < b.first);
		}
	);

	int prev_group = 0; //запоминание какую группу выводили до этого (для структурированного вывода) 
	for (auto it = students.begin(); it != students.end(); it++) { //вывод по группам
		std::pair<int, std::string> buf = *it;
		if (prev_group != buf.first) {
			std::cout << buf.first << '\t' << buf.second << '\n';
			prev_group = buf.first;
		}
		else {
			std::cout << '\t' << buf.second << '\n';
		}
	}
	return 0;
}

