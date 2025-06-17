#include "Zombie.hpp"

Zombie *newZombie(std::string name){
    return new Zombie(name);
}

// This function creates a Zombie object on the heap with the given name and returns a pointer to it.
// It allows for dynamic memory management, meaning the Zombie object can persist beyond the scope of the function.
// The caller is responsible for deleting the Zombie object to avoid memory leaks.
// This is useful when you need the Zombie to exist beyond the function call, such as in a game loop or for further interactions.