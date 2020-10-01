#pragma once

template <typename T>
class DoublyLinkedList
{
	
public:
	
	DoublyLinkedList();
	DoublyLinkedList(int _size);
	~DoublyLinkedList();

	int Add(T* _item);

	int Delete(T* _item);

	int Search(T* _item);

	int DisplayAll() noexcept;

	int GetLength() const noexcept;

	int GetSize() const noexcept;

private:
	template <typename T>
	class Node
	{
	public:
		Node() : Data(new T[1]) { return; }
		~Node()
		{
			delete[] Data;
		}
		T* Data;
		Node<T>* forward;
		Node<T>* backward;
	};
private:

	bool IsFull() const noexcept;

	bool IsEmpty() const noexcept;
	
private:

	Node<T>* mHead;
	int mLength;
	int mSize;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	mHead = new Node<T>[1];
	mHead->forward = nullptr;
	mHead->backward = nullptr;
	mLength = 0;
	mSize = 9;
	return;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(int _size)
	: mSize(_size)
{
	mHead = new Node<T>[1];
	mHead->forward = nullptr;
	mHead->backward = nullptr;
	mLength = 0;
	mSize = 9;
	return;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	return;
}

// * * * * * * private functions * * * * * * //

template <typename T>
bool DoublyLinkedList<T>::IsEmpty() const noexcept
{
	if (mLength == 0) return true;
	else return false;
}

template <typename T>
bool DoublyLinkedList<T>::IsFull() const noexcept
{
	if (mLength >= mSize) return true;
	else return false;
}

// * * * * * * public functions * * * * * * //

template <typename T>
int DoublyLinkedList<T>::GetSize() const noexcept
{
	return mSize;
}

template <typename T>
int DoublyLinkedList<T>::Add(T* _item)
{
	if (IsFull()) return 0;
	else if (IsEmpty())
	{
		mHead->Data = _item;
		mLength++;

		mHead->forward = nullptr;
		mHead->backward = nullptr;

		return 1;
	}
	else
	{
		Node<T>* temp = mHead;
		Node<T>* insert = new Node<T>[1];

		insert->Data = _item;

		int found = 0;

		while (temp->forward != nullptr && !found)
		{
			if (*temp->Data == *_item)
			{
				return found;
			}
			else if(*temp->Data > *_item)
			{
				temp = temp->forward;
			}
			else if (*temp->Data < *_item)
			{
				if (temp->backward == nullptr)
				{
					insert->forward = temp;
					insert->backward = nullptr;
					temp->backward = insert;
					found = 1;
					mLength++;
					mHead = insert;
				}
				else
				{
					insert->forward = temp;
					insert->backward = temp->backward;

					insert->backward->forward = insert;
					mLength++;
					found = 1;
				}
			}
		}
		if (!found && temp->forward == nullptr)
		{
			if (*temp->Data > *_item)
			{
				insert->backward = temp;
				insert->forward = nullptr;

				temp->forward = insert;

			}
			else if (*temp->Data < *_item)
			{
				if (temp->backward != nullptr)
				{
					insert->forward = temp;
					insert->backward = temp->backward;

					temp->backward->forward = insert;

					temp->forward = nullptr;
				}
				else
				{
					insert->forward = temp;
					insert->backward = nullptr;

					temp->backward = insert;
					mHead = insert;
				}
			}
			mLength++;
			found = 1;
		}
		return found;
	}
}

template <typename T>
int DoublyLinkedList<T>::Delete(T* _item)
{
	int found = 0;

	if (IsEmpty());
	else
	{
		Node<T>* temp = mHead;

		if (mLength == 1)
		{
			if (*temp->Data == *_item)
			{
				delete[] mHead;
				mHead = new Node<T>[1];
				mHead->forward = nullptr;
				mHead->backward = nullptr;
				found = 1;
				mLength--;
			}
		}
		else
		{
			while (temp->forward != nullptr && !found)
			{
				if (*temp->Data == *_item)
				{
					if (temp->backward == nullptr)
					{
						mHead = temp->forward;
						mHead->backward = nullptr;
					}
					else
					{
						temp->backward->forward = temp->forward;
						temp->forward->backward = temp->backward;
					}
					found = 1;
					delete[] temp;
					mLength--;
				}
				else
				{
					temp = temp->forward;
				}
			}
			if (temp->forward == nullptr && !found)
			{
				if (*temp->Data == *_item)
				{
					found = 1;
					delete[] temp;
					mLength--;
				}
			}

		}
		return found;
	}
	
	return found;
}

template <typename T>
int DoublyLinkedList<T>::Search(T* _item)
{
	Node<T>* temp = mHead;
	int found = 0;
	while (temp->forward != nullptr && !found)
	{
		if (*temp->Data == *_item)
		{
			_item = temp->Data;
			found = 1;
		}
		temp = temp->forward;
	}
	if (temp->forward == nullptr && !found)
	{
		if (*temp->Data == *_item)
		{
			_item = temp->Data;
			found = 1;
		}
	}
	return found;
}

template <typename T>
int DoublyLinkedList<T>::DisplayAll() noexcept
{
	Node<T>* temp = mHead;

	while (temp->forward != nullptr)
	{
		std::cout << temp->Data;
		temp = temp->forward;
	}
	if (temp->forward == nullptr && mLength != 0)
		std::cout << temp->Data;

	std::cout << "\n\n";
	return 1;
}

template <typename T>
int DoublyLinkedList<T>::GetLength() const noexcept
{
	return mLength;
}