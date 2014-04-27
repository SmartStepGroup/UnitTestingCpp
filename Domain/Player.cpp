#include "Player.h"


Player::Player() : currentBet(0, 0), chips(0)
{
}

void Player::MakeBet(Bet _bet)
{
	currentBet = _bet;
	chips -= currentBet.Amount();
}

void Player::Win(int wonChips)
{
	chips += wonChips;
	currentBet = Bet(0, 0);
}

Bet Player::GetCurrentBet()
{
	return currentBet;
}

Player::~Player()
{
}

void Player::Lose()
{
	currentBet = Bet(0, 0);
}

int Player::GetChips()
{
	return chips;
}

void Player::AddChips(int _chips)
{
	chips += _chips;
}