#pragma once
#include <string>
class Human
{
private:
	std::string surname;
	std::string name;
	int age;
public:
	Human(std::string l_surname, std::string l_name, int l_age);
	~Human();
	std::string get_surname();
	std::string get_name();
	int get_age();
};

