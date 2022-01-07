#pragma once
#include "ErrorsEtcClass.h"
#include "Inscription.h"

class Button// : public Inscription
{
public:

	screen next_step;//if button dont change step -1
	char other_reaction;
	SDL_Rect Rect;
	SDL_Surface*mSurface;
	SDL_Texture* mTexture;
	int screenWidth;
	int screenHeight;

	bool highlighted;
	Button();
	~Button();
	void CreateButton(TTF_Font*, std::string text, SDL_Color, screen);
	void Render(SDL_Renderer*, int screenWidth, int screenHeight, int *shift);
	bool Highlighted(int x, int y);//mouse coords
};