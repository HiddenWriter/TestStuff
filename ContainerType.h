#pragma once
class ContainerType : public BaseItem
{
public:

	ContainerType();
	~ContainerType();

	int GetID() const noexcept override;

	int GetStgID() const noexcept;

	std::string GetName() const noexcept override;

	void SetStgID(int _stgID);

	void SetID(int _id) override;

	void SetName(std::string _name) override;

	void SetIDFromKeyboard() override;

	void SetNameFromKeyboard() override;

	void SetRecord() override;

public:
	// 

	friend std::ostream& operator<<(std::ostream& _os, ContainerType* _item)
	{
		_os <<
			"\n\t - - - - - - - - - - - - " <<
			"\n\t ID    : " << _item->mID <<
			"\n\t Name  : " << _item->mName;
		return _os;
	}
	bool operator<(ContainerType* _item)
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

	bool operator>(ContainerType* _item)
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

	bool operator==(ContainerType* _item)
	{
		if (mID == _item->GetID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator=(ContainerType* _item)
	{
		mID = _item->GetID();
		mStgID = _item->GetStgID();
		mName = _item->GetName();
		return;
	}

	// 

	friend std::ostream& operator<<(std::ostream& _os, ContainerType _item)
	{
		_os <<
			"\n\t - - - - - - - - - - - - " <<
			"\n\t ID : " << _item.mID <<
			"\n\t Name : " << _item.mName;
		return _os;
	}
	bool operator<(ContainerType _item)
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

	bool operator>(ContainerType _item)
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

	bool operator==(ContainerType _item)
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

	void operator=(ContainerType _item)
	{
		mID = _item.GetID();
		mName = _item.GetName();
		mStgID = _item.GetStgID();
		return;
	}

private:

	int mStgID;
	int mID;
	std::string mName;

};

