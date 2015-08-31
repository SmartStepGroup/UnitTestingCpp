#include "RollDiceGame.h"

RollDiceGame::RollDiceGame(IDice* dice) {
	players = std::vector<Player*>();
	_dice = dice;
}


RollDiceGame::~RollDiceGame() {}

void RollDiceGame::Add(Player& player) {
	players.push_back(&player);
}

int RollDiceGame::NumberOfPlayers() {
	return players.size();
}

int RollDiceGame::RollDice() {
	return _dice->Roll();
}

void RollDiceGame::Play() {
	int winningScore = RollDice();
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
