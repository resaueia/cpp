#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
    private:
    std::string name;
    Weapon &weapon;
    // The weapon is a reference to a Weapon object, not a copy.
    // This means that HumanA will use the same Weapon object that is passed to it,
    // and any changes to the Weapon will be reflected in HumanA.
    // This is useful for sharing the same weapon between multiple HumanA instances or between HumanA and HumanB.
    // Using a reference avoids unnecessary copying and ensures that the weapon is always valid as long as the HumanA exists.
    public:
    HumanA(std::string name, Weapon &weapon);
    void attack() const;
};

#endif