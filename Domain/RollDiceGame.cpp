#include "RollDiceGame.h"
#include <ctime>

RollDiceGame::RollDiceGame(IDice* dice) 
	: m_dice(dice)
{
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
	int winningScore = m_dice->Roll();
	for (std::vector<Player*>::iterator pplayer = players.begin(); pplayer != players.end(); ++pplayer) {
		Player& player = **pplayer;
		if (player.GetCurrentBet().Score() == winningScore) {
			player.Win(player.GetCurrentBet().Amount() * 6);
		}
		else {
			player.Lose();
		}
	}
}

int Dice::Roll()
{
	return (rand() % 6 + 1);
}

