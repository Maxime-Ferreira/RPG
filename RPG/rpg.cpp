#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#pragma warning(disable : 6001)



/*
Weapon** listWeapon() {

	Weapon** arrayWeapon = (Weapon**)malloc(sizeof(Weapon*) * 10);
	Weapon *ak47 = initializeWeapon(25, 30);
	Weapon *deagle = initializeWeapon(48, 7);
	Weapon *awp = initializeWeapon(150, 10);
	arrayWeapon[0] = ak47;
	arrayWeapon[1] = deagle;
	arrayWeapon[2] = awp;
	return arrayWeapon;
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

Grenade* initializeGrenade(int quantity, int damage)
{
	Grenade* g = (Grenade*)malloc(sizeof(Grenade));
	g->damage = damage; 
	g->quantity = quantity;
	return g;
}

Grenade** listGrenade()
{
	Grenade** arrayGrenade = (Grenade**)malloc(sizeof(Grenade*) * 10);
	Grenade *flashbang = initializeGrenade(2, 0);
	Grenade *HEgrenade = initializeGrenade(1, 40);
	Grenade *molotov = initializeGrenade(1, 10);
	Grenade *smoke = initializeGrenade(1, 0);
	arrayGrenade[0] = flashbang;
	arrayGrenade[1] = HEgrenade;
	arrayGrenade[2] = molotov;
	arrayGrenade[3] = smoke;
	return arrayGrenade;
}
void launchAttack(Character *ennemy, Weapon** arrayWeapon) {
	int choice;
	printf("Choisi ton arme\n");
	printf("1: AK47\n");
	printf("2: Deagle\n");
	printf("3: AWP\n");
	printf("4: flashbang\n");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		ennemy->life -= arrayWeapon[0]->damage;
		arrayWeapon[0]->ammo--;
		break;
	case 2:
		ennemy->life -= arrayWeapon[1]->damage;
		arrayWeapon[1]->ammo--;
		break;
	case 3:
		ennemy->life -= arrayWeapon[2]->damage;
		arrayWeapon[2]->ammo--;
		break;

	default:
		printf("En cours de développement\n");
	}
	printf("hp de ton ennemie = %d\n\n", ennemy->life);
	endGame(ennemy);
}

void receiveAttack(Character *myCharacter, Weapon ** arrayWeapon) {
	int choice;
	printf("Choisi ton arme\n");
	printf("1: AK47\n");
	printf("2: Deagle\n");
	printf("3: AWP\n");
	scanf("%d", &choice);

	switch (choice) {

	case 1:
		myCharacter->life -= arrayWeapon[0]->damage;
		arrayWeapon[0]->ammo--;
		break;
	case 2:
		myCharacter->life -= arrayWeapon[1]->damage;
		arrayWeapon[1]->ammo--;
		break;
	case 3:
		myCharacter->life -= arrayWeapon[2]->damage;
		arrayWeapon[2]->ammo--;
		break;
	default:
		printf("En cours de développement\n");
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

void freeWeapon(Weapon** arrayWeapon)
{
	for (int i = 0; i < 9; i++) {
		free(arrayWeapon[i]);
	}
}

void freeGrenade(Weapon** arrayGrenade)
{
	for (int i = 0; i < 9; i++) {
		free(arrayGrenade[i]);
	}
}*/

void freeArrayWeapon(ArrayWeapon * _array) {
	free(_array->array);
	free(_array);
	_array = NULL;
}

void freeArrayGrenade(ArrayGrenade * _array) {
	free(_array->array);
	free(_array);
	_array = NULL;
}

void addWeapon(RPG * _game, int _dam, int _ammo) {
	ArrayWeapon* _array = _game->weapons;
	if (_array->index >= WEAPONS_MAX_COUNT) {
		printf("Erreur: la liste d'arme est pleine !\n");
		return;
	}
	_array->array[_array->index].ammo = _ammo;
	_array->array[_array->index].damage = _dam;

	++_array->index;
}

void addGrenade(RPG * _game, int _dam, int _quant) {
	ArrayGrenade* _array = _game->grenades;
	if (_array->index >= GRENADES_MAX_COUNT) {
		printf("Erreur: la liste de grenades est pleine !\n");
		return;
	}
	_array->array[_array->index].quantity = _quant;
	_array->array[_array->index].damage = _dam;

	++_array->index;
}

void play(RPG* game) {
	Character* activeCharacter = &game->character2;
	for (;;) {
		if (activeCharacter == &game->character2) activeCharacter = &game->character1;
		else activeCharacter = &game->character2;

		//A refaire :
		int choiceWeapon;
		printf("Choisi ton arme\n");
		printf("1: AK47\n");
		printf("2: Deagle\n");
		printf("3: AWP\n");
		scanf("%d", &choiceWeapon);

		int choiceGrenade;
		printf("Choisi ta grenade\n");
		printf("1: HE\n");
		printf("2: Molotov\n");
		scanf("%d", &choiceGrenade);

		_attack(activeCharacter, &game->weapons->array[choiceWeapon - 1], &game->grenades->array[choiceGrenade - 1]);
		
		system("pause");
		if (activeCharacter->life <= 0) {
			printf("Le mec est a 0 de vie, il a perdu !\n");
			system("pause");
			return;
		}
	}
}

RPG * initlializeRPG() {
	RPG* game = (RPG*)(malloc(sizeof(RPG)));
	game->weapons = (ArrayWeapon*)malloc(sizeof(ArrayWeapon));
	game->weapons->array = (Weapon*)malloc(sizeof(Weapon)*WEAPONS_MAX_COUNT);
	game->weapons->index = 0;
	game->grenades = (ArrayGrenade*)malloc(sizeof(ArrayGrenade));
	game->grenades->array = (Grenade*)malloc(sizeof(Grenade)*GRENADES_MAX_COUNT);
	game->grenades->index = 0;
	game->character1.life = 100;
	game->character2.life = 100;
	return game;
}

void freeRPG(RPG * game) {
	freeArrayWeapon(game->weapons);
	freeArrayGrenade(game->grenades);
	free(game);
}

void _attack(Character * ch, Weapon * w, Grenade* g) {
	ch->life -= w->damage;
	--w->ammo;
	ch->life -= g->damage;
	--g->quantity;
	printf("Le mec attaque a pris %i dommages, il lui reste %i points de vie\n", w->damage+g->damage, ch->life);
}

