#include "Player.h"


Player::Player() : currentBet(0, 0)
{
}

void Player::MakeBet(Bet _bet)
{
	currentBet = _bet;
}

Bet Player::GetCurrentBet()
{
	return currentBet;
}

Player::~Player()
{
}
