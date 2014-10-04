#include "RollDiceGame.h"

RollDiceGame::RollDiceGame()
{
	players = std::vector<Player*>();
	srand(time(nullptr));
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

void RollDiceGame::Play()
{
	int winningScore = rand() % 6 + 1;
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