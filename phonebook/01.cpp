#include <iostream>

class Person {
	public:
		void say_hi(){
			std::cout << "Hello, I'm a Person!" << std::endl;
		}
};

class Animal {
	public:
	void say_hi(){
		std::cout << "Hello, I'm an Animal!" << std::endl;
	}
};

int main()
{
	Person p;
	Animal a;
	p.say_hi();
	a.say_hi();
	return 0;
}