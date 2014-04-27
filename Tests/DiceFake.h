#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Dice.h"

class DiceFake : public Dice {
public:
	MOCK_METHOD0(Roll, int());
};