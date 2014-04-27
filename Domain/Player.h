#pragma once
#include "Bet.h"

class Player
{
public:
	Player();
	~Player();
	void MakeBet(Bet bet);
	Bet GetCurrentBet();

private: 
	Bet currentBet;
};

