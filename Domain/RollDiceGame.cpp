#include "RollDiceGame.h"
#include <ctime>

RollDiceGame::RollDiceGame(IDice *dice) : m_dice(dice) {
	m_players = std::vector<Player*>();
	srand(time(nullptr));
}


RollDiceGame::~RollDiceGame() {}

void RollDiceGame::Add(Player& player) {
	m_players.push_back(&player);
}

int RollDiceGame::NumberOfPlayers() {
	return m_players.size();
}

void RollDiceGame::Play() {	
	int winningScore = m_dice->Roll();
	for (std::vector<Player*>::iterator pplayer = m_players.begin(); pplayer != m_players.end(); ++pplayer) {
		Player& player = **pplayer;
		if (player.GetCurrentBet().Score() == winningScore) {
			player.Win(player.GetCurrentBet().Amount() * 6);
		}
		else {
			player.Lose();
		}
	}
}
