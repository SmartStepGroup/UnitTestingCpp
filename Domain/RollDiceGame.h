#pragma once
#include "Player.h"
#include "IDice.h"
#include <vector>

class RollDiceGame
{
public:
	RollDiceGame(IDice *dice);
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	void Play();

private:
	std::vector<Player*> m_players;
	IDice *m_dice;
};

