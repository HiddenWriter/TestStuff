#include "pch.h"
#include "Application.h"

Application::Application()
{
	std::cout << "\n\t Start Application . \n";
	STATUS = new DATAINFORMATION[1];
	mCommand = -1;
	mPhase = -1;
	return;
}

Application::~Application()
{
	std::cout << "\n\t Exit Application . \n";

	return;
}

int Application::Run()
{
	bool isQuit = false;
	while (!isQuit)
	{
		std::cout <<
			"\n\t -- Simple Storage prgramme. -- " << "\n" <<
			"\n\t 0 : Quit." <<
			"\n\t 1 : Load File" <<
			"\n\t 2 : Start Programme" << "\n" <<
			">> ";
		std::cin >> mCommand;

		switch (mCommand)
		{
		case 1:
			// 
			break;
		case 2:
			GetPhase();
			break;
		case 0:
			isQuit = true;
			break;
		}
	}
	return 1;
}
PHASE Application::GetPhase() noexcept
{
	PHASE phase = PHASE::MAIN;
	bool done = false;

	while (!done)
	{
		switch (phase)
		{
		case PHASE::BACKSPACE:
			done = true;
			break;
		case PHASE::MAIN:
			Main.SetDataInformation(this->STATUS);
			phase = Main.Run();
			break;
		case PHASE::STORAGE:
			Storage.SetDataInformation(this->STATUS);
			phase = Storage.Run();
			break;
		case PHASE::CONTAINER:
			Container.SetDataInformation(this->STATUS);
			phase = Container.Run();
			break;
		default:
			break;

		}
		if (phase == PHASE::BACKSPACE)
		{
			return PHASE::BACKSPACE;
		}
	}
}
