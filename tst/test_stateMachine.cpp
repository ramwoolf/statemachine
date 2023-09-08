#include <gtest/gtest.h>
#include "StateMachine.hpp"

TEST(Dummy, DummyTest)
{
    ASSERT_TRUE(true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}