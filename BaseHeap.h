#pragma once

template <typename T>
class BaseHeap
{
public:

	BaseHeap(int _size);

	BaseHeap();

	~BaseHeap();

	virtual int Add(T*& _item);

	virtual int Delete(T*& _item);

	virtual int Search(T*& _item);

	virtual int IsEmpty() noexcept;

	virtual int IsFull() noexcept;

	virtual void DisplayAll() noexcept = 0;

protected:

	virtual int AsistSort(int _par, int _cur, int& _found) noexcept;
	virtual int AsistSwap(int _x, int _y) noexcept;
	virtual int AsistSearch(int _root, T* _item, int& _found) noexcept;

protected:

	T* mArray;
	int mLength;
	int mSize;

};

template <typename T>
BaseHeap<T>::BaseHeap()
{
	mSize = 11;
	mLength = 0;
	mArray = new T[mSize];
	return;
}

template <typename T>
BaseHeap<T>::BaseHeap(int _size)
	:mSize(_size)
{
	mLength = 0;
	mArray = new T[mSize];
	return;
}

template <typename T>
BaseHeap<T>::~BaseHeap()
{
	delete[] mArray;
	return;
}

template <typename T>
int BaseHeap<T>::IsEmpty() noexcept
{
	if (mLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
int BaseHeap<T>::IsFull() noexcept
{
	if (mLength == mSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
int BaseHeap<T>::Add(T*& _item)
{
	if (IsFull() || Search(_item))
	{
		return -1;
	}
	else if (IsEmpty())
	{
		mArray[mLength] = _item;
		mLength++;

	}
	else
	{
		mArray[mLength] = _item;
		mLength++;

		int found = 0;
		
		switch (AsistSort(0, mLength, found))
		{
		case -1:
			
			// Same item.

			found = -1;
			mLength--;

			break;
		case 1:
			// done

			found = 1;
			break;
		case 0:
			// some error

			found = 0;
			break;
		default:
			break;
		}
		return found;
	}
	
}

template <typename T>
int BaseHeap<T>::Delete(T*& _item)
{
	if (IsEmpty())
	{
		return -1;
	}
	else
	{
		*_item = mArray[0];

		if (mLength == 1)
		{
			mLength--;
			return 1;
		}
		else
		{
			mArray[0] = mArray[mLength - 1];
			mLength--;
			int found = 0;
			AsistSort(0, mLength - 1, found);

			return found;
		}
	}
}
	


template <typename T>
int BaseHeap<T>::Search(T*& _item)
{
	int found = 0;
	AsistSearch(0, _item, found);
	return found;
}

// Reculsive

template <typename T>
int BaseHeap<T>::AsistSort(int _par, int _cur, int& _found) noexcept
{
	if (mArray[_par] < mArray[_cur])
	{
		AsistSwap(_par, _cur);
		AsistSort((_par + 1) / 2, _par, _found);
	}
	else if (mArray[_par] > mArray[_cur])
	{
		_found = 1;
		return 1;
	}
	else
	{
		if (_par <= _cur)
		{
			_found = 1;
			return 1;
		}
	}
}

template <typename T>
int BaseHeap<T>::AsistSwap(int _x, int _y) noexcept
{

	T* temp = new T[sizeof(1)];
	*temp = mArray[_x];
	mArray[_x] = mArray[_y];
	mArray[_y] = *temp;

	temp = nullptr;
	delete[] temp;

	return 1;
}

template <typename T>
int BaseHeap<T>::AsistSearch(int _root, T* _item, int& _found) noexcept
{
	while (_found != 1 && _root < mLength)
	{
		if (mArray[_root] == _item)
		{
			_found = 1;
			*_item = mArray[_root];
		}
		else 
		{
			AsistSearch((_root * 2) + 1, _item, _found);
			AsistSearch((_root * 2) + 2, _item, _found);
			break;
		}
	}

	return _found;
}