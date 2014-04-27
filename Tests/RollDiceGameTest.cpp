#include "gtest/gtest.h"
#include "RollDiceGame.h"
#include "Bet.h"
#include "DiceFake.h"

using namespace testing;

class WhenPlayRollDiceGame : public Test {
};

TEST_F(WhenPlayRollDiceGame, CanAddPlayer)
{
	Dice dice = Dice();
	RollDiceGame game(dice);

	game.Add(Player());
	
	ASSERT_EQ(1, game.NumberOfPlayers());
}

TEST_F(WhenPlayRollDiceGame, PlayerCanMakeABet)
{
	Player player = Player();

	player.MakeBet(Bet(100, 1));

	Bet bet = player.GetCurrentBet();
	ASSERT_EQ(100, bet.Amount());
	ASSERT_EQ(1, bet.Score());
}

TEST_F(WhenPlayRollDiceGame, GameScoreEqualsToDiceScore)
{
	DiceFake dice;
	EXPECT_CALL(dice, Roll()).WillOnce(Return(1));
	RollDiceGame game = RollDiceGame(dice);

	game.Play();

	ASSERT_EQ(1, game.WinningScore());
}