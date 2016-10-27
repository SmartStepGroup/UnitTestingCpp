#pragma once
#include "Bet.h"

class Player
{
public:
	Player();
	~Player();
	void MakeBet(Bet bet);
	Bet GetCurrentBet();
	void AddChips(Amount chips);
	Amount GetChips() const { return chips; }
	void Lose();
	void Win(Amount chips);

private: 
	Bet currentBet;
	Amount chips;
};

