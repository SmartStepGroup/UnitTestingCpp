#include "Dice.h"
#include <time.h>
#include <string>


Dice::Dice()
{
	srand(time( nullptr ));
}


Dice::~Dice()
{
}


int Dice::Roll()
{
	return rand() % 6 + 1;
}
