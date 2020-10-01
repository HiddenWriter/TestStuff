#include "pch.h"
#include "PhaseContainer.h"

PhaseContainer::PhaseContainer()
{
	ItemList = new SortedList<ItemType>[15];
	mItemSelect = -1;
}

PHASE PhaseContainer::Run()
{
	while (true)
	{
		std::cout <<
			"\n\t -- Current Storage    : " << STATUS->StorageID <<
			"\n\t -- Current Container  : " << STATUS->ContainerID << "\n";
		Display();
		std::cout <<
			"\n\t ---------------------" << "\n" <<
			"\n\t Type 0 to return to last page." <<
			"\n\t Type 11 to Add Item " <<
			"\n\t Type 22 to Delete Item " <<
			"\n\t Type 33 to Display All Item \n";
		"\n\t >>>";
		std::cin >>
			mItemSelect;


		switch (mItemSelect)
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
		case 0:
			return PHASE::BACKSPACE;
		}
	}
	return PHASE::MAIN;
}


int PhaseContainer::Add()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::     Add Item     :: " <<
		"\n\t ::::::::::::::::::::::\n";
	ItemType* temp = new ItemType[1];
	temp->SetNameFromKeyboard();
	temp->SetCtnID(STATUS->ContainerID);
	temp->SetID(ItemList[STATUS->ContainerID].GetSize() + 1);
	if (ItemList[STATUS->ContainerID].Add(temp))
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

int PhaseContainer::Delete()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::    Delete Item   :: " <<
		"\n\t ::::::::::::::::::::::\n";
	std::unique_ptr<ItemType> temp = std::make_unique<ItemType>();
	temp->SetIDFromKeyboard();
	if (ItemList[STATUS->ContainerID].Delete(temp.get()))
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

int PhaseContainer::Display() const noexcept
{
	std::cout <<
		"\n\t ----------------- \n";
	ItemList[STATUS->ContainerID].Display();
	std::cout << "\n\n";
	return 1;
}

PHASE PhaseContainer::SelectItem()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::    Select Item   :: " <<
		"\n\t ::::::::::::::::::::::\n";
	Display();
	std::cout <<
		"\n\t Enter Item ID " <<
		"\n\t >>> ";
	std::cin >> mItemSelect;
	STATUS->ItemID = mItemSelect;
	std::unique_ptr<ItemType> temp = std::make_unique<ItemType>();
	temp->SetID(STATUS->ContainerID);
	if (!ItemList[STATUS->ContainerID].Get(temp.get()))
	{
		return PHASE::UNKNOWN;
	}
	else
	{
		return PHASE::STORAGE;
	}
}

int PhaseContainer::Search()
{
	std::cout <<
		"\n\t :::::::::::::::::::::: " <<
		"\n\t ::   Search Item    :: " <<
		"\n\t ::::::::::::::::::::::\n";
	std::unique_ptr<ItemType> temp = std::make_unique<ItemType>();
	temp->SetIDFromKeyboard();
	if (ItemList[STATUS->ContainerID].Get(temp.get()))
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

void PhaseContainer::SetDataInformation(DATAINFORMATION* _status) noexcept
{
	this->STATUS = _status;
	return;
}