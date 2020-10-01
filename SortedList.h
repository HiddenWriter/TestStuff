#pragma once
template <typename T>
class SortedList
{

public:

	SortedList();
	SortedList(int _size);
	~SortedList();

	int Add(T* _item) noexcept;

	int Delete(T* _item) noexcept;

	int Get(T* _item) noexcept;

	int GetSize() noexcept;

	int Display() noexcept;

private:

	int GetNextItem(T* _item) noexcept;

	int ResetIterator() noexcept;

	bool IsFull() const noexcept;

	bool IsEmpty() const noexcept;

private:

	int mSize;
	int mLength;
	int mIterator;

	T* mArray;

};

template <typename T>
SortedList<T>::SortedList()
{
	mSize = 9;
	mArray = new T[mSize];
	mLength = 0;
	mIterator = -1;
	return;
}

template <typename T>
SortedList<T>::SortedList(int _size)
	: mSize(_size)
{
	mArray = new T[_size];
	mLength = 0;
	mIterator = -1;
	return;
}

template <typename T>
SortedList<T>::~SortedList()
{
	delete[] mArray;
	return;
}
template <typename T>
bool SortedList<T>::IsEmpty() const noexcept
{
	if (mLength == 0) return true;
	else return false;
}

template <typename T>
bool SortedList<T>::IsFull() const noexcept
{
	if (mLength == mSize) return true;
	else return false;
}

template <typename T>
int SortedList<T>::Add(T* _item) noexcept
{
	if (IsFull())
	{
		return 0;
	}
	else if (IsEmpty())
	{
		mArray[mLength] = _item;
		mLength++;
		return 1;
	}
	else
	{

		int index = 0;
		int found = 0;

		while (found != 1)
		{
			if (mArray[index] > _item)
			{
				if (index == mLength - 1)
				{
					mArray[index + 1] = _item;
					found = 1;
					mLength++;
				}
				else
				{
					index++;
				}

			}
			else if (mArray[index] < _item)
			{

				int tag = mLength;
				
				if (mLength == 1)
				{
					mArray[tag] = mArray[index];
				}
				else
				{
					while (tag > index)
					{
						mArray[tag] = mArray[tag - 1];
						tag--;
					}
				}
				mArray[index] = _item;
				found = 1;
				mLength++;
			}
		}
		return found;
	}
}

template <typename T>
int SortedList<T>::Delete(T* _item) noexcept
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		bool found = false;
		int index = 0;

		while (index < mLength)
		{
			if (mArray[index] == _item)
			{
				while (index < mLength - 1)
				{
					mArray[index] = mArray[index + 1];
					index++;
				}
				mLength--;
				found = true;
			}
			else
			{
				if (index < mLength)
				{
					index++;
				}
			}

		}
		return found;
	}
}

template <typename T>
int SortedList<T>::Get(T* _item) noexcept
{
	if (IsEmpty())
	{
		return 0;
	}

	else
	{
		bool found = false;
		mIterator = 0;

		while (mIterator != -1 && mIterator < mLength)
		{
			if (mArray[mIterator] == _item)
			{
				*_item = mArray[mIterator];
				found = true;
				break;
			}
			else
			{
				mIterator++;
			}
		}

		ResetIterator();

		return found;
	}
}

template <typename T>
int SortedList<T>::ResetIterator() noexcept
{
	mIterator = -1;
	return 1;
}

template <typename T>
int SortedList<T>::GetNextItem(T* _item) noexcept
{
	mIterator++;
	if (mIterator < mLength)
	{
		*_item = mArray[mIterator];
		return mIterator;
	}
	else
	{
		return -1;
	}

}

template <typename T>
int SortedList<T>::GetSize() noexcept
{
	return mLength;
}

template <typename T>
int SortedList<T>::Display() noexcept
{
	ResetIterator();
	std::unique_ptr<T> temp = std::make_unique<T>();
	int index = GetNextItem(temp.get());
	while (index != -1 && index < mLength)
	{
		std::cout << temp.get();
		index = GetNextItem(temp.get());
	}
	return 1;

}