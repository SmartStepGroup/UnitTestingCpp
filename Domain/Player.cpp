#include "Player.h"

#include <stdexcept>

Player::Player() : currentBet(0, 0), chips(0)
{
}

void Player::MakeBet(Bet _bet)
{
	if (_bet.Amount() > GetChips())
	{
		throw std::runtime_error("You can't bet more chips than you have. Buy more chips.");
	}

	if (_bet.Amount() < 0)
	{
		throw std::runtime_error("Bet amount should not be negative");
	}

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
	if (_chips < 0)
		throw std::runtime_error("Chips value is negative number");

	chips += _chips;
}