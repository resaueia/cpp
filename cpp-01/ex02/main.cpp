#include <iostream>

int main()
{
    std::string text = "HI THIS IS BRAIN";
    std::string *ptr = &text;
    std::string &ref = text;

    std::cout << "Memory adress of the string value: " << &text << std::endl;
    std::cout << "Memory address held by stringPTR: " << ptr << std::endl;
    std::cout << "Memory address of the pointer to the string: " << &ptr << std::endl;
    std::cout << "Memory address held by stringREF: " << &ref << std::endl;

    std::cout << "===========================================" << std::endl;

    std::cout << "Value of the string variable: " << text << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *ptr << std::endl;
    std::cout << "Value pointed to by strringREF: " << ref << std::endl;

    return (0);
}