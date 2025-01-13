#include <iostream>
#include <stdexcept>
#include "Character.h"

using namespace std;
//initialize character
Character::Character(HeroType type, const string &name, double health, double attackStrength) { 
    this->type = type; //assign the type (warrior, elf, wizard)
    this->name = name; //assign name
    this->health = health; //assign initial health
    this->attackStrength = attackStrength; //assign base attack strength
}

HeroType Character::getType() const {
    return type;
}

const string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::damage(double d) {
    health -= d; //reduce health by how much damage was taken
}
bool Character::isAlive() const { //check if character still alive if health is greater than 0
    if (getHealth() > 0) {
        return true; //character is alive
    }

    else {
        return false; //character is not alive
    }
}
