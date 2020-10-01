#include "pch.h"
#include "ItemType.h"

ItemType::ItemType()
{
	mID = -1;
	mName = "Default";
	mCtnID = -1;
	return;
}

ItemType::ItemType(int _id, std::string _name, int _ctnID)
	: mID(_id), mName(_name), mCtnID(_ctnID)
{
	return;
}

int ItemType::GetID() const noexcept
{
	return mID;
}

int ItemType::GetCtnID() const noexcept
{
	return mCtnID;
}

std::string ItemType::GetName() const noexcept
{
	return mName;
}

void ItemType::SetID(int _id)
{
	try 
	{
		mID = _id;
	}
	catch (std::exception e)
	{
		std::cout << "\n\t ERROR : " << e.what();
	}
}

void ItemType::SetCtnID(int _ctnID)
{
	mCtnID = _ctnID;
}

void ItemType::SetName(std::string _name)
{
	try
	{
		mName = _name;
	}
	catch (std::exception e)
	{
		std::cout << "\n\t ERROR : " << e.what();
	}

	return;
}

void ItemType::SetIDFromKeyboard()
{
	std::cout << "\n\t Set ID : ";
	try
	{
		std::cin >> mID;
	}
	catch (std::exception e)
	{
		std::cout << "\n\t ERROR : " << e.what();
	}

	return;
}

void ItemType::SetNameFromKeyboard()
{
	std::cout << "\n\t Set Name : ";
	try
	{
		std::cin >> mName;
	}
	catch (std::exception e)
	{
		std::cout << "\n\t ERROR : " << e.what();
	}

	return;
}

void ItemType::SetRecord()
{
	SetIDFromKeyboard();
	SetNameFromKeyboard();

	return;
}