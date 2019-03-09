#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#pragma warning(disable : 6001)

Weapon** listWeapon() {

	Weapon** array = (Weapon**)malloc(sizeof(Weapon*) * 10);
	Weapon *ak47 = initializeWeapon(25, 30);
	Weapon *deagle = initializeWeapon(48, 7);
	Weapon *awp = initializeWeapon(150, 10);
	array[0] = ak47;
	array[1] = deagle;
	array[2] = awp;
	return array;
}

Weapon* initializeWeapon(int damage, int ammo)
{
	Weapon* w = (Weapon*)malloc(sizeof(Weapon));
	w->ammo = ammo;
	w->damage = damage;
	return w;
}

void initializeCharacter(Character *c)
{
	c->life = 100;
	c->weapon = { 0,0 };
}

void launchAttack(Character *ennemy, Weapon** array) {
	int choice;
	printf("Choisi ton arme\n");
	printf("1: AK47\n");
	printf("2: Deagle\n");
	printf("3: AWP\n");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		ennemy->life -= array[0]->damage;
		array[0]->ammo--;
		break;
	case 2:
		ennemy->life -= array[1]->damage;
		array[1]->ammo--;
		break;
	case 3:
		ennemy->life -= array[2]->damage;
		array[2]->ammo--;
		break;
	default:
		printf("Mes couilles on a pas mis autant d'arme fdp!!!!\n");
	}
	printf("hp de ennemy = %d\n\n", ennemy->life);
	endGame(ennemy);
}

void receiveAttack(Character *myCharacter, Weapon ** array) {
	int choice;
	printf("Choisi ton arme\n");
	printf("1: AK47\n");
	printf("2: Deagle\n");
	printf("3: AWP\n");
	scanf("%d", &choice);

	switch (choice) {

	case 1:
		myCharacter->life -= array[0]->damage;
		array[0]->ammo--;
		break;
	case 2:
		myCharacter->life -= array[1]->damage;
		array[1]->ammo--;
		break;
	case 3:
		myCharacter->life -= array[2]->damage;
		array[2]->ammo--;
		break;
	default:
		printf("Mes couilles on a pas mis autant d'arme fdp!!!!\n");
	}
	printf("hp de myCharacter = %d\n\n", myCharacter->life);
	endGame(myCharacter);
}

void endGame(Character *p) {
	if (p->life <= 0) {
		printf("T'as le niveau de Tibot donc t'as perdu\n");
		system("pause");
		exit(0);
	}
}
