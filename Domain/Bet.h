#pragma once
class Bet
{
public:
	Bet(int amount, int score);
	~Bet();
	int Amount();
	int Score();

private:
	int amount;
	int score;
};

