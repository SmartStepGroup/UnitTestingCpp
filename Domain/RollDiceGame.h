#pragma once
#include "Player.h"
#include "IDice.h"
#include <vector>
#include <memory>

class RollDiceGame
{
public:
	RollDiceGame();
	RollDiceGame(RollDiceGame&& game);
	RollDiceGame(std::unique_ptr<IDice> dice);
	virtual ~RollDiceGame();
	void Add(Player& player);
	int NumberOfPlayers();
	void Play();

private:
	std::vector<Player*> players;
	std::unique_ptr<IDice> dice;
};

