#include "ClassSdl.h"


void ClassSdl::LoadMedia()
{
	language = "English";
	switch (backgroundTEX.whichType)
	{
	case 0:
	{
		backgroundTEX.loadFromFile("Resources/tlo.png", gRenderer);
		break;
	}
	case 1:
	{
		backgroundTEX.loadFromFile("Resources/tlo1.png", gRenderer);
	}
	}


	switch (noteTEX.whichType)
	{
	case 0:
	{
		//	noteTEX.loadFromFile("Resources/note.png", gRenderer);
		break;
	}
	case 1:
	{
		//	noteTEX.loadFromFile("Resources/note1.png", gRenderer);
	}
	}

	signatureTEX.loadFromFile("Resources/sign.png", gRenderer);
	logoTEX.loadFromFile("Resources/logo32.png", gRenderer);
	signatureTEX.loadFromFile("Resources/sign.png",gRenderer);
	SDL_SetTextureAlphaMod(signatureTEX.mTexture, 30);


	TTF_Font* big_font;
	TTF_Font* small_font;

	big_font = TTF_OpenFont("Resources/arial.ttf",36);
	small_font = TTF_OpenFont("Resources/arial.ttf", 14);


	mainMenu_Step.makeButtons(gRenderer, big_font, language +"/test",0);
	//take texts
	TTF_CloseFont(big_font);
	TTF_CloseFont(small_font);
}

void ClassSdl::limitingFrames()
{
	int tmp = 1000 - (SDL_GetTicks() - start_tick);
	if (tmp > 0)
	{
		SDL_Delay(floor(tmp / FPS));
	}
}

void ClassSdl::checkIfDir()
{
	if (!remove("firstRunAfterUpdate"))
	{
		remove("ErrorDetails/error.txt");
	}
}

void ClassSdl::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		Error("SDL could not initialize!", SDL_GetError(), true);
		return;
	}
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		Error("Warning: Linear texture filtering not enabled!", SDL_GetError(), false);
	}

	if (TTF_Init() == -1)
	{
		Error("Fonts could not initialize", TTF_GetError(), true);
		return;
	}
	SDL_DisplayMode dm;// screen info in display mode
	SDL_GetCurrentDisplayMode(0, &dm);

	screenWidth = ceil(dm.w * 0.7);
	minScreenWidth = ceil(dm.w * 0.3);
	screenHeight = ceil(dm.h * 0.7);
	minScreenHeight = ceil(dm.h * 0.6);

	//Create window\ SDL_WINDOW_RESIZABLE:
	gWindow = SDL_CreateWindow("Mood Calendar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_RESIZABLE);
	if (gWindow == NULL)
	{
		Error("Window could not be created!", SDL_GetError(), true);
		return;
	}
	//Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
	{
		Error("Renderer could not be created!", SDL_GetError(), true);
		return;
	}

	SDL_RenderClear(gRenderer);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		Error("SDL_image could not initialize", IMG_GetError(), 1);
	}
	else
	{
		LoadMedia();
	}
	step = logoScreen;
	
}

void ClassSdl::CheckForEvents()
{

	while (SDL_PollEvent(&eventHandler) != 0)
	{
		checkForWindowEvent();
		checkForMouseEvent();
		if (step == noteScreen)
		{
			checkForKeyboardEvent_NoteScreen();
		}
		else
		{
			checkForKeyboardEvent();
		}
	}
}

void ClassSdl::checkForWindowEvent()
{
	if (eventHandler.type == SDL_WINDOWEVENT)
	{

		switch (eventHandler.window.event)
		{
		case SDL_WINDOWEVENT_MINIMIZED:
		{
			render = false;
			break;
		}
		case SDL_WINDOWEVENT_RESTORED:
		{
			render = true;
			break;
		}
		case SDL_WINDOWEVENT_RESIZED:
		{
			int widthTMP = screenWidth, heightTMP = screenHeight;

			int* width_handler, * height_handler; ;
			width_handler = &screenWidth;
			height_handler = &screenHeight;

			if (SDL_GetRendererOutputSize(gRenderer, width_handler, height_handler) != 0)
			{
				Error("Can't resize", SDL_GetError(), 0);
				screenWidth = widthTMP;
				screenHeight = heightTMP;
				SDL_SetWindowSize(gWindow, screenWidth, screenHeight);
			}
			else
			{
				if (screenHeight < minScreenHeight)
				{
					screenHeight = minScreenHeight;
				}
				if (screenWidth < minScreenWidth)
				{
					screenWidth = minScreenWidth;
				}
				SDL_SetWindowSize(gWindow, screenWidth, screenHeight);
			}
			render = true;
			break;
		}
		case SDL_WINDOWEVENT_CLOSE:
			exitprogram = true;
			break;
		}
	}
}

void ClassSdl::checkForMouseEvent()
{
	if (eventHandler.type == SDL_MOUSEBUTTONUP)
	{
		if (step == logoScreen)
		{
			step++;
			render = true;
			return;
		}
		if (eventHandler.button.button == SDL_BUTTON_LEFT)
		{
			//check buttons eventHandler.button.y
		}
		else if (eventHandler.button.button == SDL_BUTTON_RIGHT)
		{
			step = mainMenuScreen;
			render = true;
		}
	}
}

void ClassSdl::checkForKeyboardEvent()
{
	if (eventHandler.type == SDL_KEYDOWN)
	{
		if (step == logoScreen)
		{
			render = true;
			step++;
		}

		switch (eventHandler.key.keysym.scancode)
		{

		case SDL_SCANCODE_ESCAPE:
		{
			SDL_Delay(50);
			if (eventHandler.key.repeat)
			{
				exitprogram = true;
			}
			else
			{
				//pop up optionsScreen
				render = true;
			}
		}
		}
	}

}

void ClassSdl::checkForKeyboardEvent_NoteScreen()
{
	if (eventHandler.type == SDL_KEYDOWN)
	{
	//	switch (eventHandler.key.keysym.scancode)
	//	{
			//case(Caps): caps =!caps; break
			// case shift: shift=!caps;
		//case :
	//	}
		if ('a' <= eventHandler.key.keysym.sym && eventHandler.key.keysym.sym >= 'z')
	//	if (eventHandler.key.keysym.sym)
		{
			int a = 5;
		}
		switch (eventHandler.key.keysym.sym)
		{
		case 'a':
		{

		}
		}
	}
	if (eventHandler.type == SDL_KEYUP)
	{
		//	switch (eventHandler.key.keysym.scancode)
		//	{
				//case(shift): shift =!caps; break
	}
}

void ClassSdl::Render()
{
	SDL_RenderClear(gRenderer);
	backgroundTEX.render(gRenderer);
	switch (step)
	{
	case screen::mainMenuScreen:
	{
		mainMenu_Step.render(gRenderer, 0,screenWidth, screenHeight);
		//	mainMenuScreen();
		break;
	}
	case screen::creditsScreen:
	{
		//	creditsScreen();
		break;
	}
	case screen::optionsMainScreen:
	{
		//	optionsMainScreen();
		break;
	}	case screen::optionsQuestsScreen:
	{
		//	optionsQuestScreen();
		break;
	}
	case screen::sumarryScreen:
	{
		//	sumarryScreen();
		break;
	}
	case screen::previousNotesScreen:
	{
		//	previousNotesScreen();
		break;
	}
	case screen::addNewNoteScreen:
	{
		//	addNewNoteScreen();
		break;
	}
	case screen::noteScreen:
	{
		//	noteScreen();
		SDL_Rect notePage;
		notePage.w = round(screenWidth * 0.4);
		notePage.h = round(screenHeight * 0.8);
		notePage.x = round((screenWidth - notePage.w) * 0.5);
		notePage.y = round(screenHeight * 0.1);
		noteTEX.render(gRenderer, &notePage);
		break;
	}
	default:
	{
		//	LogoDisplay();
		SDL_Rect logo; // rectangle to where will be rendererd logo texture

		if (screenWidth < screenHeight)
		{
			logo.w = round(screenWidth * 0.6);
			logo.h = logo.w;
		}
		else
		{
			logo.h = round(screenHeight * 0.6);
			logo.w = logo.h;
		}
		logo.x = round((screenWidth - logo.w) * 0.5);
		logo.y = round((screenHeight - logo.h) * 0.5);
		logoTEX.render(gRenderer, &logo);

	}
	}

	if (step != noteScreen && step != addNewNoteScreen && step != previousNotesScreen)
	{
		SDL_Rect sign;//rectangle where will be rendered signature
		sign.x = floor(screenWidth * 0.9);
		sign.w = floor(screenWidth * 0.1);
		sign.y = floor(screenHeight * 0.9);
		sign.h = floor(screenHeight * 0.1);
		signatureTEX.render(gRenderer, &sign);
	}
	SDL_RenderPresent(gRenderer);

}


void ClassSdl::RunProgram()
{
	start_tick = SDL_GetTicks();
	CheckForEvents();
	limitingFrames();
	if (render)
	{
		Render();
		render = false;
	}
	//	SDL_UpdateWindowSurface(gWindow);
}

ClassSdl::ClassSdl()
{
	render = true;
	ShowWindow(GetConsoleWindow(), SW_HIDE);//hide console
	checkIfDir();
	step = screen::logoScreen;
	Init();

	exitprogram = false;
}

ClassSdl::~ClassSdl()
{
	backgroundTEX.~TexClass();
	logoTEX.~TexClass();
	signatureTEX.~TexClass();
	noteTEX.~TexClass();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
//	TTF_CloseFont(big_font);
	TTF_Quit();
	SDL_Quit();
}
