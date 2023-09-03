#include <iostream>

#include "StateMachine.hpp"

struct OpenEvent {};
struct CloseEvent {};

struct OpenState;
struct CloseState;

struct OpenState {
    MyStateMachine::TransitionTo<CloseState> handle(CloseEvent const&) const {
        std::cout << "Closing the door\n";
        return {};
    }

    MyStateMachine::Nothing handle(OpenEvent const&) const {
        std::cout << "Door is already opened\n";
        return {};
    }
};

struct CloseState {
    MyStateMachine::TransitionTo<OpenState> handle(OpenEvent const&) const {
        std::cout << "Opening the door\n";
        return {};
    }

    MyStateMachine::Nothing handle(CloseEvent const&) const {
        std::cout << "Door is already closed\n";
        return {};
    }
};

int main(int argc, char const *argv[])
{
    MyStateMachine::StateMachine<OpenState, CloseState> door;

    door.handle(OpenEvent{});
    door.handle(CloseEvent{});
    door.handle(CloseEvent{});
    door.handle(OpenEvent{});
    door.handle(OpenEvent{});
    return 0;
}
