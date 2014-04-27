#pragma once
#include "Bet.h"

class Player
{
public:
	Player();
	~Player();
	void MakeBet(Bet bet);
	Bet GetCurrentBet();
	void AddChips(int chips);
	int GetChips();
	void Lose();
	void Win(int chips);

private: 
	Bet currentBet;
	int chips;
};

