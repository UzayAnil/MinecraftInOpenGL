#include "App.h"
#include "Display.h"

App::App()
{
    pushState(std::make_unique<State::PlayingState>(*this));
}

void App::runMainLoop()
{
    while (Display::isOpen())
    {
        Display::clear();

        this->m_state.top()->input();
        this->m_state.top()->update();
        this->m_state.top()->draw();

        Display::update();


        Display::checkForClose();
    }
}

void App::pushState(std::unique_ptr<State::State_Base> state)
{
    this->m_state.push(std::move(state));
}

void App::popState()
{
    this->m_state.pop();
}
