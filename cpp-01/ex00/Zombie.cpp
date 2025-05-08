#include "Zombie.hpp"

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
    this->name = name;
    std::cout << "Zombie " << name << " was created!" << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie " << name << " was destroyed!" << std::endl;
}