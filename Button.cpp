#include "Button.h"

Button::Button()
{
	activated = false;
	mTexture = NULL;
}
Button::~Button()
{
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
//	SDL_FreeSurface(mSurface);
//	mSurface = NULL;

}

void Button::createButton(TTF_Font* font, std::string text, SDL_Color color)
{
	mSurface = TTF_RenderText_Solid(font,text.data(), color);
	Rect.w = mSurface->w;
	Rect.h = mSurface->h;
}

void Button::Render(SDL_Renderer* renderer, int screenWidth, int screenHeight, int *shift)
{
	Rect.y += *shift;
	Rect.x = screenWidth * 0.15;
	mTexture = SDL_CreateTextureFromSurface(renderer, mSurface);
	SDL_RenderCopy(renderer, mTexture, NULL, &Rect);
	if (activated)
	{
		SDL_SetRenderDrawColor(renderer,200,200,50,255);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 100, 100, 150, 255);
	}
	SDL_RenderDrawRect(renderer, &Rect);//zostawia ramke
	*shift += 1.5*Rect.h;
}