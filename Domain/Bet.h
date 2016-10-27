#pragma once
#include "unit.h"

struct AmountTag;
struct ScoreTag;

typedef Unit<AmountTag> Amount;
typedef Unit<ScoreTag> Score;

class Bet
{
public:
	static Bet Zero() { return Bet(Amount(0), Score(0)); }

	Bet(Amount amount, Score score);
	~Bet();

	Amount GetAmount() const { return m_amount; }
	Score GetScore() const { return m_score; }

private:
	Amount m_amount;
	Score m_score;
};

