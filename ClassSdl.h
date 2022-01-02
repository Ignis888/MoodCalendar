#pragma once
#include "pch.h"
#include "StepText.h"

class ClassSdl : public StepText
{
	private:
		
		enum screen
		{
			logoScreen = 0,//justo logoa and background
			mainMenuScreen,//main menu
			creditsScreen,//dispalys credits and copyright
			optionsMainScreen,// technical options of program + option to go to change meritorical questions
			optionsQuestsScreen,	// add/remove various type of questions
			sumarryScreen,	// need o have at least 5 notes
			previousNotesScreen,// displays previous notes
			addNewNoteScreen,	//after using "add new note" option in main menu
			noteScreen // display to read note
		};

#pragma region textures_and_objects

		TexClass logoTEX;
		TexClass signatureTEX;
		TexClass backgroundTEX;
		TexClass noteTEX;

		void LoadMedia();

		StepText mainMenu_Step;
		StepText credits_Step;
		StepText optionsQuests_Step;
		StepText optionsMain_Step;
		StepText previousNotes_Step;
		StepText note_Step;

		void MainMenuDisplay();//main menu
		void CreditsDisplay();//dispalys credits and copyright
		void OptionsMainDisplay();// technical options of program + option to go to change meritorical questions
		void OptionsQuestDisplay();	// add/remove various type of questions
		void sumarryDisplay();	// need o have at least 5 notes
		void PreviousNotesDisplay();// displays previous notes
		void AddNewNoteDisplay();	//after using "add new note" option in main menu
		void NoteScreen(); // display to read note
#pragma endregion
		
		SDL_Event eventHandler;		//SDL_Event handler
		SDL_Window *gWindow; //main window
		SDL_Renderer* gRenderer;//main renderer
	
		Uint32 start_tick;

		int FPS = 60;

		int font_size;
		std::string language;

		int screenWidth, minScreenWidth;
		int screenHeight, minScreenHeight;
		int step;//on which step of app is user now

		bool render;//true if something have changed since last render
		
		
		void limitingFrames();
		void checkIfDir();//check if directory for error file exist and make if not
		void Init();
		void CheckForEvents();
		void checkForWindowEvent();
		void checkForMouseEvent();
		void checkForKeyboardEvent();
		void checkForKeyboardEvent_NoteScreen();
		void Render();

	public:

		bool exitprogram; // if terminate program 

		void RunProgram();
		ClassSdl();
		~ClassSdl();
};

