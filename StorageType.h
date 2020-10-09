#pragma once

class StorageType : public BaseItem
{
public:

	StorageType();
	~StorageType();

	int GetID() const noexcept override;

	std::string GetName() const noexcept override;

	void SetID(int _id) override;

	void SetName(std::string _name) override;

	void SetIDFromKeyboard() override;

	void SetNameFromKeyboard() override;

	void SetRecord() override;
	
public:

	// 

	friend std::ostream& operator<<(std::ostream& _os, StorageType* _item)
	{
		_os <<
			"\n\t - - - - - - - - - - - - " <<
			"\n\t ID    : " << _item->mID <<
			"\n\t Name  : " << _item->mName;
		return _os;
	}
	bool operator<(StorageType* _item)
	{
		if (mID < _item->GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(StorageType* _item)
	{
		if (mID > _item->GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(StorageType* _item)
	{
		if (GetID() == _item->GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator=(StorageType* _item)
	{
		mID = _item->GetID();
		mName = _item->GetName();
		return;
	}

	// 

	friend std::ostream& operator<<(std::ostream& _os, StorageType _item)
	{
		_os <<
			"\n\t - - - - - - - - - - - - " <<
			"\n\t ID    : " << _item.mID <<
			"\n\t Name  : " << _item.mName;
		return _os;
	}
	bool operator<(StorageType _item)
	{
		if (mID < _item.GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(StorageType _item)
	{
		if (mID > _item.GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(StorageType _item)
	{
		if (mID == _item.GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator=(StorageType _item)
	{
		mID = _item.GetID();
		mName = _item.GetName();
		return;
	}

private:
	
	int mID;
	std::string mName;

};

