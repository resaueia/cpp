#include "Zombie.hpp"

void randomChump(std::string name){
    Zombie z(name);
    z.announce();
}

// This function creates a Zombie object on the stack with the given name,
// announces it, and then the object is automatically destroyed when it goes out of scope.
// It is a convenient way to create a Zombie without needing to manage memory manually.
// I dont need the zombie afterwards for the function already makes it do everything I need it to do