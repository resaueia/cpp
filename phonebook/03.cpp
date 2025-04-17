#include <iostream>

class Person{
	private:
		std::string secret;
	public:
		void set_secret(std::string s){
			secret = s;
		}
		void tell_secret(){
			std::cout << "My secret is: " << secret << std::endl;
		}
};

int main()
{
	Person p;
	//p.secret = "Not a secret"; // Error: secret is private
	p.set_secret("I loathe soccer.");
	p.tell_secret();
	return 0;
}