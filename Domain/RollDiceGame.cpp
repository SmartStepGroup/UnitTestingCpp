#include "RollDiceGame.h"
#include <stdlib.h>
#include <ctime>

RollDiceGame::RollDiceGame() {
	players = std::vector<Player*>();
	srand(time(nullptr));
}


RollDiceGame::~RollDiceGame() {}

void RollDiceGame::Add(Player& player) {
	players.push_back(&player);
}

int RollDiceGame::NumberOfPlayers() {
	return players.size();
}

void RollDiceGame::Play() {
	int winningScore = RollDice();
	for (std::vector<Player*>::iterator pplayer = players.begin(); pplayer != players.end(); ++pplayer) {
		Player& player = **pplayer;
		if (player.GetCurrentBet().Score() == winningScore) {
			OnPlayerWin(player, winningScore);
		}
		else {
			OnPlayerLose(player);
		}
	}
}

int RollDiceGame::RollDice()
{
	return (rand() % 6) + 1;
}

void RollDiceGame::OnPlayerWin(Player &player, int /* winscore */)
{
	player.Win(player.GetCurrentBet().Amount() * 6);
}

void RollDiceGame::OnPlayerLose(Player &player)
{
	player.Lose();
}
