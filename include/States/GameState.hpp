#ifndef GAME_STATE_IG
#define GAME_STATE_IG

class GameState
{
public:
    virtual GameState *eventHandeler();
    virtual GameState *update();
    virtual GameState *render();

private:
};

#endif