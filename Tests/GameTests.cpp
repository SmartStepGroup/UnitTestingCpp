#include <gmock/gmock.h>
#include <RollDiceGame.h>
#include <Player.h>

class GameStub : public RollDiceGame
{
public:
	MOCK_METHOD0(RollDice, Score());
	MOCK_METHOD2(OnPlayerWin, void(Player&,int));
	MOCK_METHOD1(OnPlayerLose, void(Player&));
};

////////////////////////////////////////////////////////////////////////////////

namespace tests {

class Game : public ::testing::Test {};

TEST_F(Game, ByDefaultHasNoPlayers)
{
	RollDiceGame game;
	ASSERT_EQ(0, game.NumberOfPlayers());
}

TEST_F(Game, HasNoPlayers_Add1Player_Has1Player)
{
	RollDiceGame game;
	Player player;

	game.Add(player);

	ASSERT_EQ(1, game.NumberOfPlayers());
}

TEST_F(Game, Has1Player_Add1More_Has2Players)
{
	RollDiceGame game;
	Player player1;
	game.Add(player1);

	Player player2;
	game.Add(player2);

	ASSERT_EQ(2, game.NumberOfPlayers());
}

}
