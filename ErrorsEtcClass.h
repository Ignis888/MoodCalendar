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

