#include "pch.h"
#include "StorageType.h"

StorageType::StorageType()
{
	mID = 0;
	mName = "Default Storage";
	return;
}

StorageType::~StorageType()
{
	return;
}


int StorageType::GetID() const noexcept 
{
	return mID;
}

std::string StorageType::GetName() const noexcept
{
	return mName;
}

void StorageType::SetID(int _id) 
{
	mID = _id;
	return;
}

void StorageType::SetName(std::string _name)
{
	mName = _name;
	return;
}

void StorageType::SetIDFromKeyboard()
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

void StorageType::SetNameFromKeyboard()
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

void StorageType::SetRecord()
{
	SetIDFromKeyboard();
	SetNameFromKeyboard();
	return;
}