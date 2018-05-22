#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

class App;

namespace State
{

    class State_Base
    {
    public:
        State_Base(App& app);

        virtual void input  () = 0;
        virtual void update () = 0;
        virtual void draw   () = 0;

    protected:
        App * m_app;
    };

}

#endif // GAMESTATE_H_INCLUDED
