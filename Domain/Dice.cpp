#include "Dice.h"
#include <time.h>
#include <stdlib.h>

Dice::Dice() {
	srand(time(nullptr));
}

int Dice::Roll() {
	return rand() % 6 + 1;
}

Dice::~Dice() {}
