#include <iostream>
#include <string>

void task1() {
	int n;
	std::cout << "Введите число:\n";
	std::cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++)
			std::cout << j;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double benom(int n, int k)
{
	if (k > n / 2)
		k = n - k; // возьмем минимальное из k, n-k.. В силу симметричности C(n,k)=C(n,n-k)
	if (k == 1)
		return n;
	if (k == 0)
		return 1;
	double r = 1;

	for (int i = 1; i <= k; ++i) {
		r *= n - k + i;
		r /= i;
	}
	return ceil(r - 0.2);
}

void task2() {
	int  n;
	std::cout << "Введите число:\n";
	std::cin >> n;
	for (int i = 0; i <= n; i++) {
		std::cout << benom(n, i) << " ";
	}
	std::cout << std::endl;
}

void task3() {
	std::string s;
	double sum = 0;
	int count = 0;
	getchar();
	std::cout << "Введите числа:\n";
	while (true) {
		getline(std::cin, s);
		if (s.empty()) 
			break;
		sum += std::stoi(s);
		count++;
	}
	std::cout << "Среднее арифметическое = " << sum / count << std::endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	while (true) {
		std::cout << "Выберите команду:\n"
			<< "1.Числовой треуголник\n"
			<< "2.Биномиальные коэффициенты\n"
			<< "3.Вычисление среднего арифметического\n"
			<< "4.Выход\n";

		int cmd;
		std::cin >> cmd;

		switch (cmd) {
			case 1:
				task1();
				break;

			case 2:
				task2();
				break;

			case 3:
				task3();
				break;

			case 4:
				return 0;
			
			default:
				std::cout << "Введена неверная команда" << std::endl;
		}
	}
}

