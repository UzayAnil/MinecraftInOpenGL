#ifndef PLAYINGSTATE_H_INCLUDED
#define PLAYINGSTATE_H_INCLUDED

#include "GameState.h"
#include "../Model.h"

namespace State
{

    class PlayingState : public State_Base
    {
    public:
        PlayingState(App& app);

        void input  () override;
        void update () override;
        void draw   () override;

    private:
        Model * m_model;
    };
}

#endif // PLAYINGSTATE_H_INCLUDED
