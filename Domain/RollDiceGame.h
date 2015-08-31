#pragma once
#include "Player.h"
#include <vector>
#include "IDice.h"

class RollDiceGame
{
public:
	RollDiceGame(IDice* dice);
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	virtual int RollDice();
	void Play();

private:
	std::vector<Player*> players;
	IDice* _dice;
};

