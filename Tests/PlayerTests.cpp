#include <ostream>
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Player.h>
#include <RollDiceGame.h>

using namespace ::testing;

bool operator==(const Bet &left, const Bet &right)
{
	return left.Amount() == right.Amount() && left.Score() == right.Score();
}

std::ostream &operator<<(std::ostream &stream, const Bet &bet)
{
	return stream << bet.Amount() << " " << bet.Score();
}

class PlayerCan : public ::testing::Test
{
	
};

TEST_F(PlayerCan, AddChips)
{
	Player player;

	player.AddChips(100);

	ASSERT_EQ(100, player.GetChips());
}

TEST_F(PlayerCan, MakeBet)
{
	Player player;
	player.AddChips(100);
	Bet bet(100, 1);

	player.MakeBet(bet);

	ASSERT_EQ(bet, player.GetCurrentBet());
}

TEST_F(PlayerCan, BetMoreAmount_ThrowsException)
{
	Player player;
	player.AddChips(100);

	ASSERT_THROW(player.MakeBet(Bet(200, 1)), std::runtime_error);
}

class DiceStub : public IDice {
public:
	MOCK_METHOD0(Roll, int());
};

TEST_F(PlayerCan, WinAGame_SixTimesMoreChips)
{
	Player player;
	player.AddChips(100);
	player.MakeBet(Bet(100, 5));
	auto dice = std::make_unique<NiceMock<DiceStub>>();
	ON_CALL(*dice, Roll()).WillByDefault(Return(5));
	RollDiceGame game(dice.get());
	game.Add(player);

	game.Play();
	
	ASSERT_EQ(600, player.GetChips());
}

class PlayerMock : public Player
{
public:
	MOCK_METHOD1(Win, void(int));
};

TEST_F(PlayerCan, WinAGame_CallWin)
{
	PlayerMock player;
	player.AddChips(100);
	player.MakeBet(Bet(100, 5));
	auto dice = std::make_unique<NiceMock<DiceStub>>();
	ON_CALL(*dice, Roll()).WillByDefault(Return(5));
	RollDiceGame game(dice.get());
	game.Add(player);

	EXPECT_CALL(player, Win(Eq(600)));
	
	game.Play();
}

