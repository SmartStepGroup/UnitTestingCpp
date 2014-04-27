#include "RollDiceGame.h"


RollDiceGame::RollDiceGame(Dice& _dice) : dice(_dice)
{
	players = std::list<Player>();
}


RollDiceGame::~RollDiceGame()
{
}

void RollDiceGame::Add(Player player)
{
	players.insert(players.end(), player);
}

int RollDiceGame::NumberOfPlayers()
{
	return players.size();
}

int RollDiceGame::WinningScore()
{
	return winningScore;
}

void RollDiceGame::Play()
{
	winningScore = dice.Roll();
}