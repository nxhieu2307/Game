

#include"gameloop.h"

GameLoop* g = new GameLoop();

int main(int argc, char *argv[])
{

    g->Init();

    while(g->getGameState())
    {
        g->Render();
        g->Event();
        g->Update();

    }
    g->Clear();


    return 0;
}
