#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
	float counter = 0; //счетчик слов
    std::map<std::string, int> stats;
	std::ifstream input("input.txt");
	if (input.is_open()) {
		std::string word;
		while (!input.eof()) { //чтение текста из текстового файла
			input >> word; //считывание слова из файлового потока
			
			if (std::ispunct(*(word.end()-1))) word.pop_back(); //вырезание знаков препинания из конца слова

			if (std::ispunct(word[0])) word.erase(0, 1); //вырезание знаков препинания из начала слова
			
			std::for_each(word.begin(), word.end(), [](char& c) { //перевод всех слов в нижний регистр
				c = ::tolower(c);
				});
			if (word.empty())
				continue;
			counter++;
			if (stats.find(word) == stats.end()) { //проверка на вхождение
				stats.insert({ word, 1 });
			}
			else {
				stats[word]++;
			}
		}
	}
	else std::cout << "File not found" << '\n';

	std::cout << "Total amount: " << counter << '\n';
	for (auto it = stats.begin(); it != stats.end(); it++) { //модификация потока вывода и вывод на печать
		std::cout.width(20); 
		std::cout.setf(std::ios::left);
		std::cout << it->first;
		std::cout << it->second / counter * 100 << "\%\n";

	}
}
