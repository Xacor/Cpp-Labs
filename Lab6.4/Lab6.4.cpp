#include <set>
#include <utility>		//std::pair, std::make_pair()
#include <iostream>

int main()
{
	std::set<std::pair<int, int>> banset /*{std::make_pair(1, 98), std::make_pair(3, 35), std::make_pair(2, 73) }*/;
	int cmd = 0; //выбранная команда
	int id = 0; //id пользователя
	int res = 0; //баллы за тест
	bool exists = false; //сущесвует ли попытка для этого пользователя
	int k = 0; //счетчик количества элементов

	while (true) {
		std::cout << "1. Add result\n"
			<< "2. Show info\n"
			<< "3. Exit\n"
			<< "Input command: ";
		std::cin >> cmd;
		switch (cmd) {
		case 1:
			std::cin >> id >> res;

			for (auto it = banset.begin(); it != banset.end(); it++) { //итерирование по set
				if (it->first == id) { //проверка на существование введенного id
					std::cout << "Result for this id already exists!\n";
					exists = true;
					break;
				}
			}

			if (!exists)
				banset.insert(std::make_pair(id, res));
			break;

		case 2:
			
			for (auto it = banset.begin(); it != banset.end(); it++) { //подсчет количества элементов
				k++;
				std::cout.width(6);	//изменение ширины 
				std::cout.setf(std::ios::left); //выравнивание по левомо краю
				std::cout << it->first << it->second << '\n';
			}
			std::cout << k << " results\n";
			break;

		case 3:
			return 0;
		}
	}
}
