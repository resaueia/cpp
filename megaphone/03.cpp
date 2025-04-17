#include <iostream>
#include <string>

int	main(void)
{
	std::string word = "test";
	int count = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == 'e')
		{
			count++;
		}
		std::cout << word[i] << std::endl;
	}
	std::cout << "There were " << count << " letter(s) 'e' found." << std::endl;
	return (0);
}