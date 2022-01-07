#include "Button.h"

Button::Button()
{
	highlighted = false;
	mTexture = NULL;
}
Button::~Button()
{
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
//	SDL_FreeSurface(mSurface);
//	mSurface = NULL;

}

void Button::CreateButton(TTF_Font* font, std::string text, SDL_Color color, screen step)
{
	next_step = step;
	text = " " + text + " ";
	mSurface = TTF_RenderText_Solid(font,text.data(), color);
	Rect.w = mSurface->w;
	Rect.h = mSurface->h;
}

void Button::Render(SDL_Renderer* renderer, int screenWidth, int screenHeight, int *shift)
{
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
	Rect.y = *shift;
	Rect.x = screenWidth * 0.15;

	if (highlighted)
	{
		SDL_SetRenderDrawColor(renderer, 200, 200, 50, 150);
		SDL_RenderFillRect(renderer, &Rect);
//		SDL_SetRenderDrawColor(renderer, 200, 200, 50, 255);
	}
	SDL_SetRenderDrawColor(renderer, 100, 100, 150, 255);
	SDL_RenderDrawRect(renderer, &Rect);//zostawia ramke
	*shift += 1.5*Rect.h;

	mTexture = SDL_CreateTextureFromSurface(renderer, mSurface);
	SDL_RenderCopy(renderer, mTexture, NULL, &Rect); //text

}

bool  Button::Highlighted(int x, int y)
{
	if (x >= Rect.x && x <= (Rect.x + Rect.w) && y >= Rect.y && y <= (Rect.y + Rect.h))
	{
		highlighted = true;
		return true;
	}
	else
	{
		highlighted = false;
		return false;
	}
}