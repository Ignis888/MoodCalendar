#pragma once
#include "pch.h"
#include "Inscription.h"

class Button// : public Inscription
{
	screen next_step;//if button dont change nextstep = step
	char other_reaction;
	SDL_Rect Rect;
	SDL_Surface* mSurface;
	SDL_Texture* mTexture;
	int screenWidth;
	int screenHeight;
public:

	bool highlighted;
	Button();	
	~Button();
	screen DoThing();
	int CreateButton(TTF_Font*, std::wstring, SDL_Color, screen);
	void Render(SDL_Renderer*, int screenWidth, int screenHeight, int *shift);
	bool Highlighted(int x, int y);//mouse coords
};