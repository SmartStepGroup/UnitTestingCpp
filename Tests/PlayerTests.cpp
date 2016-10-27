#include <gtest/gtest.h>
#include <Player.h>

inline int amount(int t) { return t; }
inline int score(int t) { return t; }

namespace tests {

class Player : public ::testing::Test
{
	
};

TEST_F(Player, ByDefaultHasNoChips)
{
	::Player player;
	ASSERT_EQ(0, player.GetChips());
}

TEST_F(Player, CanBuyChips)
{
	::Player player;

	player.AddChips(100);

	ASSERT_EQ(100, player.GetChips());
}

TEST_F(Player, Has5Chips_Bets1Chip_ChipsAreReducedTo4)
{
	::Player player;
	player.AddChips(5);

	player.MakeBet(Bet(amount(1), score(3)));

	ASSERT_EQ(4, player.GetChips());
}

TEST_F(Player, BetsOnScore3_HasBetOnScore3)
{
	::Player player;
	player.AddChips(1);

	player.MakeBet(Bet(amount(1), score(3)));

	ASSERT_EQ(3, player.GetCurrentBet().Score());
}

TEST_F(Player, Bets2Chips_HasBetWith2Chips)
{
	::Player player;
	player.AddChips(5);

	player.MakeBet(Bet(amount(2), score(3)));

	ASSERT_EQ(2, player.GetCurrentBet().Amount());
}

TEST_F(Player, Has1Chip_Wins2Chips_ChipsAreIncreased3)
{
	::Player player;
	player.AddChips(1);

	player.Win(amount(2));

	ASSERT_EQ(3, player.GetChips());
}

TEST_F(Player, Has3Chips_Bets2ChipsAndLoses_ChipsAreDecreasedTo1)
{
	::Player player;
	player.AddChips(3);

	player.MakeBet(Bet(amount(2), score(4)));
	player.Lose();

	ASSERT_EQ(1, player.GetChips());
}

} // namespace tests
