#include "gtest/gtest.h"
#include "Foo.h"

namespace {
  class FooTest : public ::testing::Test {
  protected:
    Casino::Foo foo;
  };

  TEST_F(FooTest, Foo) {
    ASSERT_TRUE(foo.Run());
  }
}
