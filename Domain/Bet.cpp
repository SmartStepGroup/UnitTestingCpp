#include "Bet.h"

Bet::Bet(int _amount, int _score)
{
	amount = _amount;
	score = _score;
}

int Bet::Score() const
{
	return score;
}

int Bet::Amount() const
{
	return amount;
}

Bet::~Bet()
{
}
