
#ifndef _PLAYER__H
#define _PLAYER__H
#include "Object.h"

class Player : public Object
{

public:
    void Render(SDL_Renderer* ren);
};


#endif
