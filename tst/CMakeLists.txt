add_executable(test_stateMachine test_stateMachine.cpp)

target_link_libraries(test_stateMachine
    PRIVATE gtest::gtest
    StateMachine)

add_test(gtest_stateMachine test_stateMachine)