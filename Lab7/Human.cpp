#include "Human.h"

Human::Human()
{
	surname = "";
	name = "";
	age = 0;
}

Human::Human(std::string l_surname, std::string l_name, int l_age)
{
	surname = l_surname;
	name = l_name;
	age = l_age;
}

Human::~Human()
{
}
std::string Human::get_surname()
{
	return surname;
}
std::string Human::get_name()
{
	return name;
}
int Human::get_age()
{
	return age;
}

Human& Human::operator=(const Human& right)
{
	this->surname = right.surname;
	this->name = right.name;
	this->age = right.age;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Human& src)
{
	out << "Surname: " << src.surname << '\n'
		<< "Name: " << src.name << '\n'
		<< "Age: " << src.age << '\n';
	return out;	
}
