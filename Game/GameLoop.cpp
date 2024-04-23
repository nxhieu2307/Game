

#include "GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
}


void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

bool GameLoop::getGameState()
{
    return GameState;
}

void GameLoop::Init()
{


  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    if(renderer)
    {
        //cout << "OK";
        GameState = true;
        player = TextureManager::Texture("img/bird.png", renderer);
        background = TextureManager::Texture("img/background.png" , renderer);
    }
}

void GameLoop::Event()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        GameState = false;
    }

}

void GameLoop::Update()
{
    // source dimension
    srcPlayer.h = 24;
    srcPlayer.w = 34;
    srcPlayer.x = srcPlayer.y = 0;

    // Destination dimension
    destPlayer.w = 24;
    destPlayer.h = 34;
    destPlayer.x = 10;
    destPlayer.y++;

    srcbackground.h = 600;
    srcbackground.w = 800;
    srcbackground.x = srcbackground.y = 0;
}
void GameLoop::Render()
{

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background , &srcbackground , &srcbackground);
    SDL_RenderCopy(renderer, player, &srcPlayer , &destPlayer);

    SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}
