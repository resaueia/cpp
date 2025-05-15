#include <iostream>
#include <string>

int main()
{
    std::string content = "bananas e laranjas";
    std::string s1 = "a";
    std::string s2 = "e";

    size_t pos = 0;

    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::cout << content << std::endl;
    return 0;
}