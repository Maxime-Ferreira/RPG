#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main() {
	/*Character ennemy;
	initializeCharacter(&ennemy);
	Character myCharacter;
	initializeCharacter(&myCharacter);
	Weapon **array = listWeapon();
	for (;;) {

		launchAttack(&ennemy, array);
		receiveAttack(&myCharacter, array);
	}*/

	RPG* game = initlializeRPG();
	addWeapon(game, 25, 30);//AK47
	addWeapon(game, 48, 7); //awp
	addWeapon(game, 150, 10);//deagle
	addGrenade(game, 40, 1); //HE
	addGrenade(game, 0, 2); //flashbang
	addGrenade(game, 10, 1); //molotov
	addGrenade(game, 0, 1); //smoke

	play(game);

	freeRPG(game);
	return 0;
}