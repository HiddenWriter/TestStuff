#pragma once

class DATAINFORMATION
{
public:
	DATAINFORMATION()
	{
		StorageID = 999;
		ContainerID = 999;
		ItemID = 999;
		mName = "TEST";
		return;
	}
	~DATAINFORMATION()
	{
	}
public:

	int StorageID;
	int ContainerID;
	int ItemID;
	std::string mName;

};

class BaseItem
{
public:
	
	int virtual GetID() const noexcept = 0;

	std::string virtual GetName() const noexcept = 0;

	void virtual SetID(int _id) = 0;

	void virtual SetName(std::string _name) = 0;

	void virtual SetIDFromKeyboard() = 0;

	void virtual SetNameFromKeyboard() = 0;

	void virtual SetRecord() = 0;

};
