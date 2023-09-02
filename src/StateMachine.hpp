#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <functional>
#include <tuple>
#include <variant>

namespace MyStateMachine {

template <typename... States>
class StateMachine {
    private:
    std::tuple<States...> states;
    std::variant<States*...> currentState {&std::get<0>(states)};

    public:

    template <typename State>
    void transitionTo() {
        currentState = &std::get<State>(states);
    }

    template <typename Event>
    void handle(Event const& event) {
        auto passEventToState = [&event](auto statePtr) {
            statePtr->handle(event).execute(*this);
        }
        std::visit(passEventToState, currentState);
    }
};

template <typename State>
struct TransitionTo {
    template <typename Machine>
    void execute(Machine &machine) {
        machine.transitionTo<State>();
    }
};

struct Nothing
{
    template <typename Machine>
    void execute(Machine &) {}
};




} // namespace MyStateMachine

#endif // STATEMACHINE_HPP