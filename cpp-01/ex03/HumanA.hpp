#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
    private:
    std::string name;
    Weapon &weapon;
    // The weapon is a reference to a Weapon object, not a copy
    public:
    HumanA(std::string name, Weapon &weapon);
    void attack() const;
};

#endif