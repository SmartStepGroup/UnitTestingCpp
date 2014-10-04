#pragma once
#include "Player.h"
#include <vector>
#include <time.h>

class RollDiceGame
{
public:
	RollDiceGame();
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	void Play();
	virtual int RollDice();

private:
	std::vector<Player*> players;
};

