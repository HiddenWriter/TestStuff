#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType()
{
	mStgID = -1;
	mID = -1;
	mName = "Defualt Container";
	return;
}

ContainerType::~ContainerType()
{
	return;
}

int ContainerType::GetStgID() const noexcept
{
	return mStgID;
}

void ContainerType::SetStgID(int _stgID)
{
	mStgID = _stgID;
	return;
}

int ContainerType::GetID() const noexcept
{
	return mID;
}

std::string ContainerType::GetName() const noexcept
{
	return mName;
}

void ContainerType::SetID(int _id)
{
	mID = _id;
	return;
}

void ContainerType::SetName(std::string _name)
{
	mName = _name;
	return;
}

void ContainerType::SetIDFromKeyboard()
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

void ContainerType::SetNameFromKeyboard()
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

void ContainerType::SetRecord()
{
	SetIDFromKeyboard();
	SetNameFromKeyboard();
	return;
}