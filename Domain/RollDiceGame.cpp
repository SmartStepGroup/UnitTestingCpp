#include "RollDiceGame.h"
#include "IDice.h"
#include <ctime>

RollDiceGame::RollDiceGame() {
	players = std::vector<Player*>();
	srand(time(nullptr));
}

RollDiceGame::RollDiceGame(IDice* adice) {
	players = std::vector<Player*>();
	srand(time(nullptr));
	dice = adice;
}



RollDiceGame::~RollDiceGame() {}

void RollDiceGame::Add(Player& player) {
	players.push_back(&player);
}

int RollDiceGame::NumberOfPlayers() {
	return players.size();
}

void RollDiceGame::Play() {
	int winningScore = dice->Roll();
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
