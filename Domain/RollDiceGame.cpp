#include "RollDiceGame.h"


RollDiceGame::RollDiceGame(Dice& _dice) : dice(_dice)
{
	players = std::vector<Player*>();
}


RollDiceGame::~RollDiceGame()
{
}

void RollDiceGame::Add(Player& player)
{
	players.push_back(&player);
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
	for (std::vector<Player*>::iterator pplayer = players.begin(); pplayer != players.end(); ++pplayer)
	{
		Player& player = **pplayer;
		if (player.GetCurrentBet().Score() == winningScore)
		{
			player.Win(player.GetCurrentBet().Amount() * 6);
		}
		else
		{
			player.Lose();
		}
	}
}