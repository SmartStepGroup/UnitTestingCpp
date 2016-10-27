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
	void Play();

protected:
	virtual int RollDice();
	virtual void OnPlayerWin(Player &player, int winscore);
	virtual void OnPlayerLose(Player &player);

private:
	std::vector<Player*> players;
};

