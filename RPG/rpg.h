#pragma once
#define WEAPONS_MAX_COUNT 16
#define GRENADES_MAX_COUNT 8
#define WEAPON_NAME_SIZE 16

typedef struct Weapon {
	int damage;
	int ammo;
	char name [WEAPON_NAME_SIZE];
}Weapon;

typedef struct Character {
	int life;
}Character;

typedef struct Grenade {
	int quantity;
	int damage;
}Grenade;

typedef struct ArrayWeapon {
	Weapon* array;
	unsigned int index;
}ArrayWeapon;

typedef struct ArrayGrenade {
	Grenade* array;
	unsigned int index;
}ArrayGrenade;

typedef struct RPG {
	ArrayWeapon* weapons;
	ArrayGrenade* grenades;
	Character character1, character2;
}RPG;

void freeArrayWeapon(ArrayWeapon* _array);
void freeArrayGrenade(ArrayGrenade* _array);

void addWeapon(RPG* _game, int _dam, int _ammo);
void addGrenade(RPG* _game, int _dam, int _quant);

void play(RPG*);

RPG* initlializeRPG();
void freeRPG(RPG*);

void _attackW(Character* ch, Weapon* w);

/*
void launchAttack(Character *ennemy, Weapon** array);
void receiveAttack(Character *myCharacter, Weapon** array);
void initializeCharacter(Character *c);
void endGame(Character *myCharacter);
Weapon* initializeWeapon(int ammo, int damage);
Weapon** listWeapon();
Grenade* initializeGrenade(int quantity, int damage);
Grenade** listGrenade();
void freeWeapon();
void freeListWeapon();*/

