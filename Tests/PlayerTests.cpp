#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include <Player.h>
#include <RollDiceGame.h>

using namespace ::testing;

class PlayerCan : public ::testing::Test
{
	
};

TEST_F(PlayerCan, Default_PlayerHasNoChips)
{
	Player player;

	ASSERT_EQ(0, player.GetChips());
}

TEST_F(PlayerCan, BuyChips)
{
	Player player;

	player.AddChips(100);

	ASSERT_EQ(100, player.GetChips());
}

TEST_F(PlayerCan, BuyNegativeChips_ThrowsException)
{
	Player player;

	ASSERT_THROW(player.AddChips(-1), std::exception);
}

TEST_F(PlayerCan, CanNotMakeBet_HasNoChips_ThrowsException)
{
	Player player;

	ASSERT_THROW(player.MakeBet(Bet(1,1)), std::exception);
}

TEST_F(PlayerCan, CanNotMakeBet_WithNegativeChips_ThrowsException)
{
	Player player;

	player.AddChips(10);

	ASSERT_THROW(player.MakeBet(Bet(-1, 1)), std::exception);
}

TEST_F(PlayerCan, CanMakeBet)
{
	Player player;

	player.AddChips(10);

	ASSERT_NO_THROW(player.MakeBet(Bet(1, 1)), std::exception);
}

class StubDice : public IDice
{
public:
	MOCK_METHOD0(Roll, int());
};

TEST_F(PlayerCan, CanMakeBetAndWin)
{
	Player player;

	player.AddChips(10);
	player.MakeBet(Bet(1, 6));
	const int chips_before_play = player.GetChips();

	const std::unique_ptr<StubDice> dice(new StubDice());
	ON_CALL(*dice, Roll()).WillByDefault(::testing::Return(6));

	RollDiceGame game(dice.get());
	game.Add(player);
	game.Play();

	ASSERT_EQ(1 * 6 + chips_before_play, player.GetChips());
}
