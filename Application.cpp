#include "pch.h"
#include "Application.h"

Application::Application()
{
	std::cout << "\n\t Start Application . \n";
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
void Application::GetPhase() noexcept
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
			AppCtrl = GetMainPhase();
			phase = PHASE::MAIN;
			break;
		case PHASE::STORAGE:
			AppCtrl = GetStoragePhase();
			phase = PHASE::STORAGE;
			break;
		case PHASE::CONTAINER:
			AppCtrl = GetContainerPhase();
			phase = PHASE::CONTAINER;
			break;
		default:
			break;

		}

		AppCtrl->Run();

		if (phase == PHASE::BACKSPACE)
		{
			done = true;
		}
	}
}

ContainerType* Application::GetContainer()
{
	static ContainerType* pContainer = new ContainerType();
	return pContainer;
}

StorageType* Application::GetStorage()
{
	static StorageType* pStorage = new StorageType();
	return pStorage;
}

ItemType* Application::GetItem()
{
	static ItemType* pItem = new ItemType();
	return pItem;
}

PhaseStorage* Application::GetStoragePhase()
{
	PhaseStorage* pPS = new PhaseStorage();
	return pPS;
}

PhaseContainer* Application::GetContainerPhase()
{
	PhaseContainer* pPC = new PhaseContainer();
	return pPC;
}

PhaseMain* Application::GetMainPhase()
{
	PhaseMain* pPM = new PhaseMain();
	return pPM;
}

void Application::ReleaseResource()
{
	BasePhase* pP1 = GetMainPhase();
	BasePhase* pP2 = GetStoragePhase();
	BasePhase* pP3 = GetContainerPhase();

	BaseItem* pB1 = GetStorage();
	BaseItem* pB2 = GetContainer();
	BaseItem* pB3 = GetItem();

	delete pP1, pP2, pP3, pB1, pB2, pB3;

	return;
}

