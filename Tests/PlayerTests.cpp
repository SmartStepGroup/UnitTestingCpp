#include <gtest/gtest.h>
#include <Player.h>

namespace tests {

class Player : public ::testing::Test
{
	
};

TEST_F(Player, ByDefaultHasNoChips)
{
	::Player player;
	ASSERT_EQ(Amount(0), player.GetChips());
}

TEST_F(Player, CanBuyChips)
{
	::Player player;

	player.AddChips(Amount(100));

	ASSERT_EQ(Amount(100), player.GetChips());
}

TEST_F(Player, Has5Chips_Bets1Chip_ChipsAreReducedTo4)
{
	::Player player;
	player.AddChips(Amount(5));

	player.MakeBet(Bet(Amount(1), Score(3)));

	ASSERT_EQ(Amount(4), player.GetChips());
}

TEST_F(Player, BetsOnScore3_HasBetOnScore3)
{
	::Player player;
	player.AddChips(Amount(1));

	player.MakeBet(Bet(Amount(1), Score(3)));

	ASSERT_EQ(Score(3), player.GetCurrentBet().GetScore());
}

TEST_F(Player, Bets2Chips_HasBetWith2Chips)
{
	::Player player;
	player.AddChips(Amount(5));

	player.MakeBet(Bet(Amount(2), Score(3)));

	ASSERT_EQ(Amount(2), player.GetCurrentBet().GetAmount());
}

TEST_F(Player, Has1Chip_Wins2Chips_ChipsAreIncreased3)
{
	::Player player;
	player.AddChips(Amount(1));

	player.Win(Amount(2));

	ASSERT_EQ(Amount(3), player.GetChips());
}

TEST_F(Player, Has3Chips_Bets2ChipsAndLoses_ChipsAreDecreasedTo1)
{
	::Player player;
	player.AddChips(Amount(3));

	player.MakeBet(Bet(Amount(2), Score(4)));
	player.Lose();

	ASSERT_EQ(Amount(1), player.GetChips());
}

} // namespace tests
