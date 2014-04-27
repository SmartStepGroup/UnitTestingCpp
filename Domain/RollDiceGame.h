#pragma once
#include "Player.h"
#include "Dice.h"
#include <list>

class RollDiceGame
{
public:
	RollDiceGame(Dice& dice);
	~RollDiceGame();
	void Add(Player player);
	int NumberOfPlayers();
	void Play();
	int WinningScore();

private:
	std::list<Player> players;
	Dice& dice;
	int winningScore;
};

