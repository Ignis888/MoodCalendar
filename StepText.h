#pragma once
#include "pch.h"
#include "Button.h"

class StepText : public ErrorsEtcClass
{
	std::deque<Button> rightColumn;
	//std::deque<Inscription> rightColumn;
public:

	//SDL_Texture *mTexture;
	StepText();
	~StepText();
	void makeButtons(SDL_Renderer* ,TTF_Font*, std::string path, bool i_f_left_column);
	void render(SDL_Renderer* ,bool, int, int);//0 iff left, 1 for right; screen size
	void free();
};

