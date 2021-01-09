#include "Human.h"

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
