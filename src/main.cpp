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

    void OnUpdate() {
        std::cout << "Door opened\n";
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

    void OnUpdate() {
        std::cout << "Door closed\n";
    }
};

int main(int argc, char const *argv[])
{
    MyStateMachine::StateMachine<OpenState, CloseState> door;

    door.OnUpdate();
    door.handle(OpenEvent{});
    door.OnUpdate();
    door.handle(CloseEvent{});
    door.OnUpdate();
    door.handle(CloseEvent{});
    door.OnUpdate();
    door.handle(OpenEvent{});
    door.OnUpdate();
    door.handle(OpenEvent{});
    return 0;
}
