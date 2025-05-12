#include <iostream>
#include <string>

int main()
{
    std::string text = "Hello, World!";
    std::string *ptr = &text;

    std::cout << "Text variable address: " << &text << std::endl;
    std::cout << "Pointer variable address: " << ptr << std::endl;
    std::cout << "String value: " << text << std::endl;
    std::cout << "Text value: " << *ptr << std::endl;

    return (0);
}