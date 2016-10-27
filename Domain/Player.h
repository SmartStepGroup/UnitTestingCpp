#pragma once
#include "Bet.h"

class Player
{
public:
	Player();
	virtual ~Player();
	void MakeBet(Bet bet);
	Bet GetCurrentBet();
	void AddChips(int chips);
	int GetChips();
	void Lose();
	virtual void Win(int chips);

private: 
	Bet currentBet;
	int chips;
};

