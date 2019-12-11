#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main() {

	RPG* game = initlializeRPG();
	addWeapon(game, 25, 30);//AK47
	addWeapon(game, 48, 7); //awp
	addWeapon(game, 150, 10);//deagle
	addGrenade(game, 40, 1); //HE
	addGrenade(game, 10, 1); //molo

	play(game);

	freeRPG(game);
	return 0;
}