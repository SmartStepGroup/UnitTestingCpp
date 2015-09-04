#include <gtest/gtest.h>
#include <Player.h>

class PlayerCan : public ::testing::Test
{
	
};

TEST_F(PlayerCan, BuyChips)
{
	Player player;

	player.AddChips(100);

	ASSERT_EQ(100, player.GetChips());
}