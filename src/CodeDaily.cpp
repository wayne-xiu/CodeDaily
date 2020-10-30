// CodeDaily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


class Person
{
public:
	int get_age() const { return age_; }
	void set_age(int value) { age_ = value; }
	__declspec(property(get = get_age, put = set_age)) int age;
private:
	int age_ = 0;
};

int main() {

	Person p;
	std::cout << p.age << std::endl;
	p.age = 20;
	std::cout << p.age << std::endl;

	return 0;
}
