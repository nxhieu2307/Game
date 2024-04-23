#ifndef _TEXTUREMANAGER__H
#define _TEXTUREMANAGER__H

#include"GameLoop.h"

class TextureManager
{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};


#endif
