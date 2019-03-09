#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main() {
	Character ennemy;
	initializeCharacter(&ennemy);
	Character myCharacter;
	initializeCharacter(&myCharacter);
	Weapon **array = listWeapon();
	for (;;) {
		launchAttack(&ennemy, array); 
		receiveAttack(&myCharacter, array);
	}
	return 0;
}