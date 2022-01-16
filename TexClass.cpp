#include "TexClass.h"

TexClass::TexClass()
{
	mTexture = NULL;
	whichType = 0;
}

TexClass::~TexClass()
{
	Free();
}

void TexClass::Free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}

void TexClass::loadFromFile(std::string path,SDL_Renderer *Render)
{
	Free();

	SDL_Surface* loadedSurface;
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		//TO DO MAKE PREMADE DEFAULT VERSION
		std::string error = "Unable to load image: " + path;
		ErrorsEtc Error;
		Error.Error(error, IMG_GetError(), 0);
		return;
	}
	mTexture = SDL_CreateTextureFromSurface(Render, loadedSurface);
	if (mTexture == NULL)
	{
		std::string error = "Unable to Create Texture from : " + path + " in TexClass.cpp";
		ErrorsEtc Error;
		Error.Error(error, SDL_GetError(), 1);
	}
	SDL_FreeSurface(loadedSurface);	//Get rid of old loaded surface

	return;
}



void TexClass::Render(SDL_Renderer* renderer)
{

	if (mTexture == NULL)
	{
			std::string error = "Can't Render,Texture don't exist, ";
			ErrorsEtc Error;
			Error.Error(error, SDL_GetError(), 1);
			return;
	}
	SDL_RenderCopy(renderer, mTexture, NULL, NULL);

}
void TexClass::Render(SDL_Renderer* renderer, SDL_Rect *object)
{

	if (mTexture == NULL)
	{
		std::string error = "Can't Render,Texture don't exist ";
		ErrorsEtc Error;
		Error.Error(error, SDL_GetError(), 1);
		return;
	}
	//	SDL_RenderDrawRect(renderer, object);//zostawia ramke
	SDL_RenderCopy(renderer,mTexture,NULL,object);

}