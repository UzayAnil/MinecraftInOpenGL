#include "PlayingState.h"
#include <ctime>
#include <iostream>

namespace State
{

    PlayingState::PlayingState(App& app)
    : State_Base(app)
    {
        m_model = new Model({
            0.5, 0.5,
            0.5, -0.5,
            -0.5, 0.5,
            -0.5, -0.5,
            -0.5, 0.5,
            0.5, -0.5
        });
    }

    void PlayingState::input()
    {

    }

    void PlayingState::update()
    {

    }

    void PlayingState::draw()
    {
        glColor3f(0.5, 0, 1.0);
        m_model->bind();
        glDrawArrays(GL_TRIANGLES,0, 6);
        m_model->unbind();
    }
}
