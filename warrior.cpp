#include <iostream>
#include <stdexcept>
#include "Warrior.h"


using namespace std;

//warrior constructor
Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) 
: Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {

}

void Warrior::attack(Character& opponent) {
    int count = 0;
    if (opponent.getType() == WARRIOR) { //check if opponent is also a warrior
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        //if same allegiance, do not attack
        if (this->allegiance == opp.allegiance) {
            count += 1;
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
    }

    if (count == 0) {
        double calc = (health / MAX_HEALTH) * (attackStrength); //calculate and perfrom damage
        opponent.damage(calc); 
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << calc << " damage." << endl;
    }
}
