#include "Bet.h"

Bet::Bet(int _amount, int _score)
{
	amount = _amount;
	score = _score;
}

int Bet::Score()
{
	return score;
}

int Bet::Amount()
{
	return amount;
}

Bet::~Bet()
{
}
