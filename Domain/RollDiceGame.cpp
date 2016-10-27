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
	Score winningScore = RollDice();
	for (std::vector<Player*>::iterator pplayer = players.begin(); pplayer != players.end(); ++pplayer) {
		Player& player = **pplayer;
		if (player.GetCurrentBet().GetScore() == winningScore) {
			OnPlayerWin(player, winningScore);
		}
		else {
			OnPlayerLose(player);
		}
	}
}

Score RollDiceGame::RollDice()
{
	return Score((rand() % 6) + 1);
}

void RollDiceGame::OnPlayerWin(Player &player, Score /* winscore */)
{
	player.Win(player.GetCurrentBet().GetAmount() * 6);
}

void RollDiceGame::OnPlayerLose(Player &player)
{
	player.Lose();
}
