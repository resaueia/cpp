#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->type = type;
}

const std::string& Weapon::getType() const{
    return (type);
}

void Weapon::setType(std::string newtype){
    type = newtype;
}