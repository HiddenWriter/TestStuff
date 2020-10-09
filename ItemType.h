#pragma once
class ItemType : public BaseItem
{
public:
	ItemType();
	ItemType(int _id, std::string _name, int _ctnID);
	~ItemType() = default;

	int GetID() const noexcept override;

	int GetCtnID() const noexcept;

	std::string GetName() const noexcept override;

	void SetID(int _id) override;

	void SetCtnID(int _ctnID);

	void SetName(std::string _name) override;

	void SetIDFromKeyboard() override;

	void SetNameFromKeyboard() override;

	void SetRecord() override;

	friend std::ostream& operator<<(std::ostream& _os, ItemType* _item) 
	{
		_os << 
			"\n\t - - - - - - - - - - - - \n" << 
			"\n\t ID : " << _item->mID <<
			"\n\t Name : " << _item->mName;
		return _os;
	}

	bool operator<(ItemType* _item)
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

	bool operator>(ItemType* _item)
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

	bool operator==(ItemType* _item)
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

	void operator = (ItemType* _item)
	{
		SetID(_item->GetID());
		SetName(_item->GetName());

		return;
	}


	friend std::ostream& operator<<(std::ostream& _os, std::shared_ptr<ItemType> _item)
	{
		_os << "\n\t ID : " << _item->mID <<
			"\n\t Name : " << _item->mName;
		return _os;
	}

	bool operator<(ItemType _item)
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

	bool operator>(ItemType _item)
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

	bool operator==(ItemType _item)
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

	void operator = (std::shared_ptr<ItemType> _item)
	{
		SetID(_item->GetID());
		SetName(_item->GetName());

		return;
	}

private:

	int mCtnID;
	int mID;
	std::string mName;

};


