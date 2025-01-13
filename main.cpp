#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {
	int seed; 
	cout << "Enter seed value: "; //Prompt user for seed value to get random seed generator
	cin >> seed;
	cout << endl;
	
	srand(seed); //Random seed generator

	vector<Character *> adventurers; //Vector to store various adventurers
	adventurers.push_back(new Warrior("Arthur", 100, 5, "King George"));
	adventurers.push_back(new Warrior("Jane", 100, 6, "King George"));
	adventurers.push_back(new Warrior("Bob", 100, 4, "Queen Emily"));
	adventurers.push_back(new Elf("Raegron", 100, 4, "Sylvarian"));
	adventurers.push_back(new Elf("Cereasstar", 100, 3, "Sylvarian"));
	adventurers.push_back(new Elf("Melimion", 100, 4, "Valinorian"));
	adventurers.push_back(new Wizard("Merlin", 100, 5, 10));
	adventurers.push_back(new Wizard("Adali", 100, 5, 8));
	adventurers.push_back(new Wizard("Vrydore", 100, 4, 6));

	unsigned numAttacks = 10 + rand() % 11; //Number of attacks between 10-20
	unsigned attacker, defender; 

	//loop to simulate attacks
	for (unsigned i = 0; i < numAttacks; ++i) { 
		attacker = rand() % adventurers.size(); //random attacker
		do {
			defender = rand() % adventurers.size(); //random defender
		} while (defender == attacker); //make sure defender and attacker are not the same
		
		adventurers.at(attacker)->attack(*adventurers.at(defender)); //perform attack
		cout << endl;
	}
	cout << "-----Health Remaining-----" << endl; //print remaining health
	for (unsigned i = 0; i < adventurers.size(); ++i) {
		cout << adventurers.at(i)->getName() << ": " 
			<< adventurers.at(i)->getHealth() << endl;
	}

	return 0;
}
