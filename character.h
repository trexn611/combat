#include <string>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD}; //enum for character types

const double MAX_HEALTH = 100.0; //constant for max health (100)

class Character {
 protected:
	HeroType type; //type of character
	string name; //name of character
	double health; //curennt health of character
	double attackStrength; //base attack strength

 public:
 	Character(HeroType type, const string &name, double health, double attackStrength);
 	HeroType getType() const;
 	const string & getName() const;
 	int getHealth() const;
 	void damage(double d); //damage
 	bool isAlive() const; //status
 	virtual void attack(Character &) = 0; //pure virtual attack
 };

#endif
