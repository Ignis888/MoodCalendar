#pragma once
#include "pch.h"
#include "ErrorsEtcClass.h"

struct date
{
	struct tm newtime;

	//ToDo
	//weather
};

class ErrorsEtcClass
{
	private:
	void getTime(std::fstream*);
	void getTime(tm*);
	public:
	bool Error(std::string, std::string, bool); // errorcontent, sdlerror, fatal-1 nonfatal-0
};


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