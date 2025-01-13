#include <iostream>
#include <stdexcept>
#include "Wizard.h"


using namespace std;

//wizard constructor
Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
: Character(WIZARD, name, health, attackStrength), rank(rank) {

}
    

void Wizard::attack(Character& opponent) {
    if (opponent.getType() == WIZARD) { //check if opponent is wizard
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double calc = ((this->rank * 1.0)/ opp.rank) * (attackStrength); //calculate damage
        opp.damage(calc); //perform damage

        //display results against wizard
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl; 
        cout << opp.getName() << " takes " << calc << " damage." << endl;
    }

    else {
        //display results against non wizard
        opponent.damage(attackStrength);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << attackStrength << " damage." << endl;
    }
}
