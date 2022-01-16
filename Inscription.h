#pragma once
#include "pch.h"
#include "TexClass.h"

class Inscription
{

	SDL_Rect Rect;
	SDL_Surface* mSurface;
	SDL_Texture* mTexture;
public:
	void CreateButton(TTF_Font*, std::string text, SDL_Color, screen);
	void Render(SDL_Renderer*, int screenWidth, int screenHeight, int* shift);
};

