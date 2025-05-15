#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void replace_all(std::string &text, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    while ((pos = text.find(s1, pos)) != std::string::npos)
    {
        text.erase(pos, s1.length());
        text.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int c, char **v)
{
    if (c != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = v[1];
    std::string s1 = v[2];
    std::string s2 = v[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();
    replace_all(content, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: could not create output file " << filename + ".replace" << std::endl;
        return 1;
    }
    outfile << content;
    outfile.close();
    return 0;
}