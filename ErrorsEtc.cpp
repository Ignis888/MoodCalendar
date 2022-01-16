#include "ErrorsEtc.h"



void ErrorsEtc::getTime(std::fstream* errorfile)
{
	struct tm newtime;
	__time64_t long_time;
	_time64(&long_time);
	errno_t err = _localtime64_s(&newtime, &long_time);// Convert to local time.
	if (!err)
	{
		*errorfile << "\t" << newtime.tm_hour << ":";
		if (newtime.tm_min < 10) *errorfile << "0";
		*errorfile << newtime.tm_min << " " << newtime.tm_mday << ".";
		if (newtime.tm_mon < 10) *errorfile << "0";
		*errorfile << newtime.tm_mon + 1 << "." << newtime.tm_year - 100 << "\n";
	}
}
void ErrorsEtc::getTime(tm* newtime)
{
	__time64_t long_time;
	_time64(&long_time);
	errno_t err = _localtime64_s(newtime, &long_time);// Convert to local time.
}

bool ErrorsEtc::Error(std::string errorContent, std::string sdl_errorContent, bool fatal)
{
	std::fstream errorfile;
	errorfile.open("ErrorDetails/error.txt", std::fstream::in | std::fstream::app);

	if (!errorfile.is_open())
	{
		LPCWSTR dirname = L"ErrorDetails";
		CreateDirectory(dirname, NULL);
		errorfile.open("ErrorDetails/error.txt", std::fstream::in | std::fstream::app);
	}

	if (fatal)
	{
		errorfile << "\n\n FATAL ERROR";
	}
	errorfile << "\n" << errorContent << "\n\t" << sdl_errorContent << "\n";
	getTime(&errorfile);
	errorfile << "\n";

	errorfile.close();

	if (fatal)
	{
		std::string msg;
		msg = "error saved in error.txt";
		AttachConsole(GetCurrentProcessId());
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		std::cout << "\n" << msg << "\n" << errorContent << "\n\t" << sdl_errorContent;
		return true;
	}
	return false;

}