#pragma once

#include "Inscription.h"

class Button// : public Inscription
{
public:
	SDL_Rect Rect;
	SDL_Surface*mSurface;
	SDL_Texture* mTexture;

	bool activated;
	Button();
	~Button();
	void createButton(TTF_Font*, std::string text, SDL_Color);
	void Render(SDL_Renderer*, int screenWidth, int screenHeight, int *shift);
};