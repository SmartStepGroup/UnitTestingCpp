#pragma once
class Bet
{
public:
	Bet(int amount, int score);
	~Bet();
	int Amount() const;
	int Score() const;

private:
	int amount;
	int score;
};

