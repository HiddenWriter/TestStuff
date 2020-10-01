#include "pch.h"
#include "PhaseMain.h"

PhaseMain::PhaseMain()
{
	mStgSelect = -1;
	mPhase = PHASE::MAIN;
	MasterList = std::make_unique<DoublyLinkedList<StorageType>>();
	return;
}

PhaseMain::~PhaseMain()
{
	return;
}

PHASE PhaseMain::Run()
{
	while (true)
	{
		std::cout <<
			"\n\t -- Current Storage --" << "\n";
		Display();
		std::cout <<
			"\n\t ---------------------" << "\n" <<
			"\n\t Type 0 to return to last page." <<
			"\n\t Type 11 to Add Storage " <<
			"\n\t Type 22 to Delete Storage " <<
			"\n\t Type 33 to Display All Storage " <<
			"\n\t Type 44 to Select Storage \n";
			"\n\t >>>" ;
		std::cin >>
			mStgSelect;


		switch (mStgSelect)
		{
		default:
		case 11:
			Add();
			break;
		case 22:
			Delete();
			break;
		case 33:
			Display();
			break;
		case 44:
			if (SelectStorage() == PHASE::UNKNOWN)
				break;
			else
			return PHASE::STORAGE;
		case 0:
			return PHASE::BACKSPACE;
		}


	}
	return PHASE::MAIN;
}

// private 

int PhaseMain::Add()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::    Add Storage   :: " <<
		"\n\t ::::::::::::::::::::::\n";
	StorageType* temp = new StorageType[1];
	temp->SetNameFromKeyboard();
	temp->SetID(MasterList->GetLength() + 1);
	if (MasterList->Add(temp))
	{
		std::cout <<
			"\n\t Successfully Added \n";
		return 1;
	}
	else
	{
		std::cout << "\n\t Error \n";
		return 0;
	}
}

int PhaseMain::Delete()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::  Delete Storage  :: " <<
		"\n\t ::::::::::::::::::::::\n";
	std::unique_ptr<StorageType> temp = std::make_unique<StorageType>();
	temp->SetIDFromKeyboard();
	if (MasterList->Delete(temp.get()))
	{
		std::cout << "\n\t Successfully Deleted \n";
		return 1;
	}
	else
	{
		std::cout << "\n\t Error \n";
		return 0;
	}
}

int PhaseMain::Display() const noexcept
{
	MasterList->DisplayAll();
	std::cout << "\n\n";
	return 1;
}

PHASE PhaseMain::SelectStorage()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::  Select Storage  :: " <<
		"\n\t ::::::::::::::::::::::\n";
	Display();
	std::cout <<
		"\n\t Enter Storage ID " <<
		"\n\t >>> ";
	
	std::cin >> mStgSelect;
	STATUS->StorageID = mStgSelect;
	std::unique_ptr<StorageType> temp = std::make_unique<StorageType>();
	temp->SetID(STATUS->StorageID);
	if (!MasterList->Search(temp.get()))
	{
		return PHASE::UNKNOWN;
	}
	else
	{
		return PHASE::STORAGE;
	}
}

int PhaseMain::Search()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::  Search Storage  :: " <<
		"\n\t ::::::::::::::::::::::\n";
	std::unique_ptr<StorageType> temp = std::make_unique<StorageType>();
	temp->SetIDFromKeyboard();
	if (MasterList->Search(temp.get()))
	{
		std::cout <<
			temp;
		return 1;
	}
	else
	{
		std::cout <<
			"\n\t ERROR .\n";
		return 0;
	}
}

void PhaseMain::SetDataInformation(DATAINFORMATION* _status) noexcept
{
	this->STATUS = _status;
	return;
}