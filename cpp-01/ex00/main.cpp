#include "Zombie.hpp"

int main(){
    Zombie *z = newZombie("Hippie");
    z->announce();
    delete z;
    randomChump("Stacy");
    return (0);
}