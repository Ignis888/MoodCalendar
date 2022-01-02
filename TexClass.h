#pragma once
#include "pch.h"
#include "ErrorsEtcClass.h"

class TexClass : public ErrorsEtcClass
{
private:

	void free();

public:

	SDL_Texture* mTexture;

	int whichType;//to give different options to each

	void loadFromFile(std::string, SDL_Renderer*);	//Loads image from specified path
	void render(SDL_Renderer*, SDL_Rect*);//on object SDL_rect
	void render(SDL_Renderer*);//on whole window, almost only background

	TexClass();//Initializes variables
	~TexClass();//Deallocates memory	
};
