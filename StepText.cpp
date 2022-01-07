#include "StepText.h"
StepText::StepText()
{
	Free();
}
StepText::StepText(screen step)
{
	this->step = step;
}
StepText::~StepText()
{
	Free();
}
void StepText::Free()
{
	while (!rightColumn.empty())
	{
		rightColumn.pop_back();
	}
	
	/*while (!leftColumn.empty())
	{
	//	leftColumn.pop_back();
	}*/
}
void StepText::MakeButtons(SDL_Renderer* renderer,TTF_Font* font,std::string path,bool i_f_left_column)
{
	Free();
	std::fstream dataFile;
	dataFile.open("English/test", std::fstream::in);

	if (!dataFile.is_open())
	{
		std::string errorContent = "Can't open " + path;
		Error("Can't open ", path, 1);
		//to do basic in english
	}
	else
	{
		Button TMPButton;
		std::string TMPstring;
		while(!dataFile.eof())
		{
			std::getline(dataFile,TMPstring);
			if (!TMPstring.empty())
			{
				TMPButton.CreateButton(font, TMPstring, {150,50,50}, step);
				if (i_f_left_column)
				{
					//leftColumn.push_back(TMPButton);
				}
				else
				{
					rightColumn.push_back(TMPButton);
				}
			}
		}
	}

	dataFile.close();
}

void StepText::Render(SDL_Renderer* renderer, bool i_f_left_column, int screenWidth, int screenHeight)
{
/*	if ((i_f_left_column && leftColumn.empty()) && (!i_f_left_column && rightColumn.empty()))
	{
		return;
	}
*/
	
	if (i_f_left_column)
	{
		//Rect.x = screenWidth * 0.15;
		SDL_Rect textOb;
		textOb.w = floor(screenWidth * 0.25);
		if (TRUE)
		{
			//do auto inserting
	/* }
		for (auto& TMP : )
		{*/

		}
	}
	else
	{
		int h = screenHeight * 0.1;
	//	if
	//	= screenWidth / (rightColumn.size() + 2);
	//Rect.x = screenWidth * 0.25;
		h = h;
		for (auto& tmpButton : rightColumn)
		{
			if (h > screenHeight * 0.9) break;
			tmpButton.Render(renderer, screenWidth, screenHeight, &h);
		}
	}
}