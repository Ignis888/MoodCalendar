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

screen Button::DoThing()
{
	switch (other_reaction)
	{
	case 's'://save
	{
		break;
	}
	case 'd'://delete
	{
		break;
	}
	case 'l'://load
	{
		break;
	}
	case 'e'://edit
	{
		break;
	}
	}
	return next_step;
}

int Button::CreateButton(TTF_Font* font, std::wstring wtext, SDL_Color color, screen step)
{
	if (wtext.size() < 5)
	{
		ErrorsEtc Error;
		Error.Error("Can't make button","Not enough characters",1);
		return 1;
	}
	size_t lastPos = wtext.rfind(';');
	size_t firstPos = wtext.find(';');

	if (lastPos == std::string::npos || firstPos == std::string::npos || firstPos == lastPos)
	{
		ErrorsEtc Error;
		Error.Error("Can't make button", "Bad format", 1);
		return 1;
	}
	other_reaction = wtext[wtext.length()-1]; //can't use .back() cuz capacity > size
	lastPos = wtext.rfind(';');
	wtext.erase(lastPos, wtext.length() - lastPos);
	std::wstring screenNameTMP = wtext.substr(firstPos +1);
	std::string screenName(screenNameTMP.begin(), screenNameTMP.end());
	
	if (screenName == "logoScreen")
	{
		next_step = logoScreen;
	}
	else if (screenName == "mainMenuScreen")
	{
		next_step = mainMenuScreen;
	}
	else if (screenName == "creditsScreen")
	{
		next_step = creditsScreen;
	}
	else if (screenName == "optionsMainScreen")
	{
		next_step = optionsMainScreen;
	}
	else if (screenName == "optionsQuestsScreen")
	{
		next_step = optionsQuestsScreen;
	}
	else if (screenName == "sumarryScreen")
	{
		next_step = sumarryScreen;
	}
	else if (screenName == "previousNotesScreen")
	{
		next_step = previousNotesScreen;
	}
	else if (screenName == "addNewNoteScreen")
	{
		next_step = addNewNoteScreen;
	}
	else if (screenName == "noteScreen")
	{
		next_step = noteScreen;
	}
	else
	{
		ErrorsEtc Error;
		Error.Error("Can't make button", "There's no step like " + screenName, 1);
		return 1;
	}


	//next_step  buffor; TODO
//	text.erase(lastPos, text.size());

	std::wstring text_new;
	text_new = wtext.substr(0,firstPos);
	//text_new = std::to_wstring(buffor);
	//

	//text = NULL;
	//const std::string s(ws.begin(), ws.end());
	//mSurface = TTF_RenderText_Solid(font, text.data(), color);
	mSurface = TTF_RenderUNICODE_Blended_Wrapped(font, (const Uint16*)text_new.c_str(), color, 300);
	Rect.w = mSurface->w;
	Rect.h = mSurface->h;

	return 0;
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