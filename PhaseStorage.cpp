#include "pch.h"
#include "PhaseStorage.h"

PhaseStorage::PhaseStorage()
{
	StorageList = new BinaryTree<ContainerType>[11];
	mCtnSelect = -1;
	return;
}

PhaseStorage::~PhaseStorage()
{
	return;
}

PHASE PhaseStorage::Run()
{
	bool done = false;
	while (!done)
	{
		std::cout <<
			"\n\t -- Current Storage  :  " << STATUS->StorageID << " -- " << "\n";
		Display();
		std::cout <<
			"\n\t ---------------------" << "\n" <<
			"\n\t Type 0 to return to Main page." <<
			"\n\t Type 11 to Add Container " <<
			"\n\t Type 22 to Delete Container " <<
			"\n\t Type 33 to Display All Container " <<
			"\n\t Type 44 to Select Container " <<
			"\n\t Type 55 to Search Item. \n" <<
			"\n\t >>";
		std::cin >> mCtnSelect;
		switch (mCtnSelect)
		{
		case 0:
			return PHASE::MAIN;
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
			return SelectContainer();
		case 55:
			Search();
			break;
		default:
			break;
		}
	}
	return PHASE::MAIN;
}

int PhaseStorage::Add()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::  Add Container   :: " <<
		"\n\t ::::::::::::::::::::::\n";

	ContainerType* temp = new ContainerType[1];
	temp->SetStgID(STATUS->StorageID);
	temp->SetNameFromKeyboard();
	temp->SetID(StorageList[STATUS->StorageID].GetLength() + 1);
	if (!StorageList[STATUS->StorageID].Add(temp))
	{
		std::cout <<
			"\n\t Error";
		return 0;
	}
	else
	{
		std::cout <<
			"\n\t Successfully Done. \n";
		return 1;
	}
}

int PhaseStorage::Delete()
{
	ContainerType* temp = new ContainerType[1];
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t :: Delete Container :: " <<
		"\n\t ::::::::::::::::::::::\n";
	Display();
	temp->SetIDFromKeyboard();
	if (StorageList[STATUS->StorageID].Delete(temp))
	{
		std::cout <<
			"\n\t Successfully Done \n";
		delete[] temp;
		return 1;
	}
	else
	{
		std::cout <<
			"\n\t Error. \n";
		delete[] temp;
		return 0;
	}
}

int PhaseStorage::Display() const noexcept
{	
	StorageList[STATUS->StorageID].DisplayAll(1);
	std::cout << "\n\n";
	return 1;
}

int PhaseStorage::Search()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t :: Search Container :: " <<
		"\n\t ::::::::::::::::::::::\n";
	ContainerType* temp = new ContainerType[1];
	temp->SetIDFromKeyboard();
	if (StorageList[STATUS->StorageID].Search(temp))
	{
		delete[] temp;
		return 1;
	}
	else
	{
		delete[] temp;
		return 0;
	}
	return 1;
}

PHASE PhaseStorage::SelectContainer()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t :: Select Container :: " <<
		"\n\t ::::::::::::::::::::::\n";
	std::cout << "\n\n";
	Display();
	std::cout <<
		"\n\t Enter Container Number : ";
	std::cin >> mCtnSelect;
	STATUS->ContainerID = mCtnSelect;

	return PHASE::CONTAINER;
}

void PhaseStorage::SetDataInformation(DATAINFORMATION* _status) noexcept
{
	this->STATUS = _status;
	return;
}