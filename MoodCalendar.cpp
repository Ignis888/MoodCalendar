
#include "pch.h"
#include "ClassSdl.h"


int main(int argc, char* args[])
{

	ClassSdl SdlC;
	while (!SdlC.exitprogram)
	{
		SdlC.RunProgram();
	}
	while (1);
	return true;

}

