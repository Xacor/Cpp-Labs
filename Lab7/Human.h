#pragma once
#include <string>
#include <iostream>
class Human
{
private:
	std::string surname;
	std::string name;
	int age;
public:
	Human();
	Human(std::string l_surname, std::string l_name, int l_age);
	~Human();
	std::string get_surname();
	std::string get_name();
	int get_age();


	friend std::ostream& operator<< (std::ostream& out, const Human& src);
	Human& operator=(const Human& right);
};

