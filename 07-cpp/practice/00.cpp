#include <iostream>

template <typename T>

void showTwice(T value) {
	std::cout << value << " " << value << std::endl;
}

int main(){
	showTwice(42);
	showTwice(3.14f);
	showTwice("Hello, World!");
	return 0;
}

/*
what is important to understand is that the compiler generates 
a different version of the function for each type you use.
It is able to identify the type based on the argument you pass
to the function.
*/