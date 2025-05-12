#include <iostream>
#include <string>

// A reference is basically a nickname for a given variable

int main()
{
    std::string text = "Hello, World!";
    std::string &ref = text;
    std::string *ptr = &text;

    std::cout << "Text variable address: " << &text << std::endl;
    std::cout << "Pointer points to: " << ptr << std::endl;
    std::cout << "Reference address is: " << &ref << std::endl;

    std::cout << "Text variable value: " << text<< std::endl;
    std::cout << "Value via *ptr: " << *ptr << std::endl;
    std::cout << "Value via ref: " << ref << std::endl;

    return (0);
}