#pragma once
#include "Player.h"
#include <vector>
#include "bet.h"

class RollDiceGame
{
public:
	RollDiceGame();
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	void Play();

protected:
	virtual Score RollDice();
	virtual void OnPlayerWin(Player &player, Score winscore);
	virtual void OnPlayerLose(Player &player);

private:
	std::vector<Player*> players;
};

