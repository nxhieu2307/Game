#ifndef _GAMELOOP__H
#define _GAMELOOP__H

#include<SDL.h>
#include<SDL_image.h>
#include"TextureManager.h"
#include<bits/stdc++.h>
using namespace std;
class GameLoop
{
private:
    const int HEIGHT = 600;
    const int WIDTH = 800;
    bool GameState;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Texture* player;
    SDL_Texture* background;

    SDL_Rect srcPlayer, destPlayer;
    SDL_Rect srcbackground;
public:
    GameLoop();
    bool getGameState();
    void Update();
    void Init();
    void Event();
    void Render();
    void Clear();


};



#endif
