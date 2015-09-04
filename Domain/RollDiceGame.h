#pragma once
#include "Player.h"
#include <vector>

class RollDiceGame
{
public:
	RollDiceGame();
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	virtual int RollDice();
	void Play();

private:
	std::vector<Player*> players;
};

