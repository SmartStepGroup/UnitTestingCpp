#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <Player.h>
#include <RollDiceGame.h>
#include <Dice.h>

using namespace testing;
using ::testing::Return;

class DiceStub : public IDice {
public:
	MOCK_METHOD0(Roll, int());
};

class PlayerTest : public Test {
protected:
	Player player;

public: 
	RollDiceGame CreateGameWithWinningScore(int winningScore) {
		DiceStub* dice = new DiceStub();
		ON_CALL(*dice, Roll()).WillByDefault(Return(winningScore));
		return RollDiceGame(dice);
	}
};

TEST_F(PlayerTest, PlayerHasNoChipsByDefault) {
	ASSERT_EQ(0, player.GetChips());
};

TEST_F(PlayerTest, PlayerCanBuyChips) {
	player.AddChips(100);
	ASSERT_EQ(100, player.GetChips());
};

TEST_F(PlayerTest, PlayerCanBetChips) {
	player.AddChips(100);

	player.MakeBet(Bet(10, 1));

	ASSERT_EQ(100 - 10, player.GetChips());
};

TEST_F(PlayerTest, PlayerCanJoinGame) {
	player.AddChips(100);
	RollDiceGame game = RollDiceGame(new Dice());

	game.Add(player);

	ASSERT_EQ(1, game.NumberOfPlayers());
};

TEST_F(PlayerTest, GameCallsRoll) {
	player.AddChips(100);
	DiceStub* dice = new DiceStub();
	EXPECT_CALL(*dice, Roll()).Times(0).WillRepeatedly(Return(1));
	RollDiceGame game = RollDiceGame(dice);

	game.Play();
};

TEST_F(PlayerTest, PlayerCanLoseGame) {
	player.AddChips(100);
	RollDiceGame game = CreateGameWithWinningScore(6);
	game.Add(player);
	player.MakeBet(Bet(10, 1));

	game.Play();

	ASSERT_EQ(100 - 10, player.GetChips());
};

TEST_F(PlayerTest, PlayerCanWinGame) {
	player.AddChips(100);
	RollDiceGame game = CreateGameWithWinningScore(6);
	game.Add(player);
	player.MakeBet(Bet(10, 6));

	game.Play();

	ASSERT_EQ(100 - 10 + 10*6, player.GetChips());
};
