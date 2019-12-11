#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#pragma warning(disable : 6001)

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