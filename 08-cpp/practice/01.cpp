#include <iostream>
#include <vector>
#include <algorithm> // contém std::sort

int main() {
	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	std::vector<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it <<std::endl;

	it = std::find(numbers.begin(), numbers.end(), 30);
	if (it != numbers.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
}

