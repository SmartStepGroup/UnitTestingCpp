#pragma once
#include "Player.h"
#include <vector>

class RollDiceGame
{
public:
	RollDiceGame();
	~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	void Play();
	int WinningScore();

private:
	std::vector<Player*> players;
	int winningScore;
};

