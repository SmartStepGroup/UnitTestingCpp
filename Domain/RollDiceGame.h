#pragma once
#include "Player.h"
#include <vector>

class IDice
{
public:
	virtual int Roll() = 0;
};

class Dice : public IDice
{
public:
	virtual int Roll();
};

class RollDiceGame
{
public:
	explicit RollDiceGame(IDice* dice);
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	//virtual int RollDice();
	void Play();

private:
	std::vector<Player*> players;
	IDice* m_dice;
};

