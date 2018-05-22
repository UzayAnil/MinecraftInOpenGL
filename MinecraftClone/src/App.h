#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <stack>
#include <memory>

#include "GameState/PlayingState.h"

class App
{
private:
    std::stack<std::unique_ptr<State::State_Base>> m_state;

public:
    App();

    void runMainLoop();

    void pushState(std::unique_ptr<State::State_Base> state);
    void popState();
};

#endif // APP_H_INCLUDED
