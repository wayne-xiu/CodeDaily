// CodeDaily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


//class Person
//{
//public:
//	int get_age() const { return age_; }
//	void set_age(int value) { age_ = value; }
//	// unfortunately, this doesn't work with GCC, for Clang, special setting is needed
//	__declspec(property(get = get_age, put = set_age)) int age;
//private:
//	int age_ = 0;
//};

#include <functional>

template<typename T>
class property {
public:
    property(
        std::function<void(T)> setter,
        std::function<T()> getter) :
        setter_(setter), getter_(getter) { }
    operator T() const { return getter_(); }
    property<T>& operator= (const T& value) { setter_(value); return *this; }
    T& value() { return value_; }
private:
    std::function<void(T)> setter_;
    std::function<T()> getter_;
    T value_;
};

class Person {
public:
    property<int> age {
        [this](int x) { this->age.value() = x; },        // Setter ... yes you can do this!
            [this]() -> int {  return this->age.value(); } // Getter.
    };
};

int main() {

	Person p;
	//std::cout << p.age << std::endl;
	p.age = 20;
	std::cout << p.age << std::endl;

	return 0;
}
