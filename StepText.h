#pragma once
#include "pch.h"
#include "Button.h"

class StepText : public ErrorsEtcClass
{
	
	//std::deque<Inscription> rightColumn;
public:
	std::deque<Button> rightColumn;
	screen step;
	//SDL_Texture *mTexture;
	StepText();
	StepText(screen);
	~StepText();
	void MakeButtons(SDL_Renderer* ,TTF_Font*, std::string path, bool i_f_left_column);
	void Render(SDL_Renderer* ,bool, int, int);//0 iff left, 1 for right; screen size
	void Free();
};

