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

TEST_F(WhenPlayRollDiceGame, PlayerCanAddChips)
{
	Player player;

	player.AddChips(100);

	ASSERT_EQ(100, player.GetChips());
}

TEST_F(WhenPlayRollDiceGame, PlayerCanAddMoreChips)
{
	Player player;

	player.AddChips(100);
	player.AddChips(100);

	ASSERT_EQ(100 + 100, player.GetChips());
}

TEST_F(WhenPlayRollDiceGame, PlayerCanBetSomeChips)
{
	Player player;

	player.AddChips(100);
	player.MakeBet(Bet(25, 1));

	ASSERT_EQ(100 - 25, player.GetChips());
}

TEST_F(WhenPlayRollDiceGame, PlayerCanLoose)
{
	Player player;

	player.AddChips(100);
	player.MakeBet(Bet(25, 1));

	DiceFake dice;
	EXPECT_CALL(dice, Roll()).WillOnce(Return(6));
	RollDiceGame game = RollDiceGame(dice);

	game.Add(player);
	game.Play();

	ASSERT_EQ(100 - 25, player.GetChips());
	ASSERT_EQ(0, player.GetCurrentBet().Amount());
}

TEST_F(WhenPlayRollDiceGame, PlayerCanWin)
{
	Player player;

	player.AddChips(100);
	player.MakeBet(Bet(25, 6));

	DiceFake dice;
	EXPECT_CALL(dice, Roll()).WillOnce(Return(6));
	RollDiceGame game = RollDiceGame(dice);

	game.Add(player);
	game.Play();

	ASSERT_EQ(100 - 25 + 25*6, player.GetChips());
	ASSERT_EQ(0, player.GetCurrentBet().Amount());
}
