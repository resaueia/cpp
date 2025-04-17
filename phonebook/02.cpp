#include <iostream>

class Car{
	public:
		std::string brand;
		int year;
		void show_details(){
			std::cout << "The model's brand is " << brand << " and the year is " << year << std::endl;
		}
};

int main()
{
	Car car1;
	Car car2;
	car1.brand = "BYD";
	car1.year = 2025;
	car2.brand = "Porsche";
	car2.year = 2023;
	car1.show_details();
	car2.show_details();
	return 0;
}