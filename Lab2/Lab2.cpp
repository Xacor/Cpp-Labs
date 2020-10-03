#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true) {
		int cmd;
		std::cout << "Выберите команду:\n"
			<< "1.Числовой треуголник\n"
			<< "2.Биномиальные коэффициенты\n"
			<< "3.Вычисление среднего арифметического\n"
			<< "4.Выход\n";
		std::cin >> cmd;
		switch (cmd)
			case 1:
				std::cout << "Введите число:\n";
				int n;
				std::cin >> n;
				for (int i = 0; i <= n; i++) {
					for (int j = 0; j <= i; j++) {
						std::cout << j;
					}
				}
	}
}

