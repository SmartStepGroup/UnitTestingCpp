#include "gtest/gtest.h"
#include "Foo.h"

class FooTest : public ::testing::Test {
protected:
	Casino::Foo foo;
};

TEST_F(FooTest, FooTest1) {
	Casino::Foo foo;
	ASSERT_TRUE(foo.Run());
}
