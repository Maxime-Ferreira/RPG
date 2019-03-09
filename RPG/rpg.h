#pragma once

typedef struct Weapon {
	int damage;
	int ammo;

}Weapon;

typedef struct Character {
	int life;
	Weapon weapon;

}Character;

void launchAttack(Character *ennemy, Weapon** array);

void receiveAttack(Character *myCharacter, Weapon** array);

void initializeCharacter(Character *c);

void endGame(Character *myCharacter);

Weapon* initializeWeapon(int ammo, int damage);

Weapon** listWeapon();

void freeWeapon();

void freeListWeapon();