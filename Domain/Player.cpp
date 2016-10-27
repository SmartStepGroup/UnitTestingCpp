#include "Player.h"

Player::Player() : currentBet(Amount(0), Score(0)), chips(0)
{
}

void Player::MakeBet(Bet _bet)
{
	if (_bet.GetAmount() > GetChips())
	{
		throw "You can't bet more chips than you have. Buy more chips.";
	}

	currentBet = _bet;
	chips -= currentBet.GetAmount();
}

void Player::Win(Amount wonChips)
{
	chips += wonChips;
	currentBet = Bet::Zero();
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
	currentBet = Bet::Zero();
}

void Player::AddChips(Amount _chips)
{
	chips += _chips;
}