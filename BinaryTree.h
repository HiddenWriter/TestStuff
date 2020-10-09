#pragma once

template <typename T>
class BinaryTree
{
public:

	BinaryTree();
	BinaryTree(int _size);
	~BinaryTree();

	int Add(T* _item);

	int Delete(T* _item);

	int Search(T* _item);

	int DisplayAll(int _option) const noexcept;

	int GetLength() const noexcept;

private:

	template <typename T>
	class Node
	{
	public:
		Node()
		{
			Data = new T[1];
			left = nullptr;
			right = nullptr;
			return;
		}
		~Node()
		{
			delete[] Data;
		}
		T* Data;
		Node<T>* left;
		Node<T>* right;
	};

private:

	bool IsEmpty() const noexcept;
	bool IsFull() const noexcept;
	void InsertNode(T* _item, Node<T>* _root, int& _found) const noexcept;
	void DeleteNode(T* _item, Node<T>* _root, int& _found) noexcept;
	void GetInorderSuccessor(Node<T>* _subroot) noexcept;
	void SearchNode(T* _item, Node<T>* _root, int& _found) const noexcept;
	void DisplayPreorder(Node<T>* _root) const noexcept;
	void DisplayPostorder(Node<T>* _root) const noexcept;
	void DisplayInorder(Node<T>* _root) const noexcept;

private:

	Node<T>* mRoot;
	int mLength;
	int mSize;

};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	mRoot = new Node<T>[1];
	mRoot->left = nullptr;
	mRoot->right = nullptr;
	mLength = 0;
	mSize = 15;
	return;
}

template <typename T>
BinaryTree<T>::BinaryTree(int _size)
	:mSize(_size)
{
	mRoot = new Node<T>[1];
	mRoot->left = nullptr;
	mRoot->right = nullptr;
	mLength = 0;
	return;
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	mRoot = nullptr;
	delete[] mRoot;
	return;
}

template <typename T>
bool BinaryTree<T>::IsEmpty() const noexcept
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
bool BinaryTree<T>::IsFull() const noexcept
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
int BinaryTree<T>::Add(T* _item)
{
	if (IsFull())
	{
		return 1;
	}
	else
	{
		if (IsEmpty())
		{
			mRoot->Data = _item;
			mLength++;
			return 1;
		}
		else
		{
			int found = 0;
			InsertNode(_item, mRoot, found);
			if (found)
			{
				mLength++;
			}
			else;

			return found;
		}

	}
	
}

template <typename T>
int BinaryTree<T>::Delete(T* _item)
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		int found = 0;
		DeleteNode(_item, mRoot, found);
		if (found)
		{
			mLength--;
		}
		return found;
	}
}

template <typename T>
int BinaryTree<T>::DisplayAll(int _option) const noexcept
{
	if (mLength == 0)
	{
		return 0;
	}
	else
	{
		switch (_option)
		{
		case 1:
			DisplayPreorder(mRoot);
			break;
		case 2:
			DisplayInorder(mRoot);
			break;
		case 3:
			DisplayPostorder(mRoot);
			break;
		default:
			break;
		}

		return 1;
	}
	
}

template <typename T>
int BinaryTree<T>::Search(T* _item)
{
	int found = 0;
	SearchNode(_item, mRoot, found);
	return found;
}
// Private Functions // 

template <typename T>
void BinaryTree<T>::InsertNode(T* _item, Node<T>* _root, int& _found) const noexcept
{
	if (*_root->Data == *_item)
	{
		_found = 0;
		return;
	}
	else 
	
	{
		if (*_root->Data > *_item)
		{
			if (_root->left == nullptr)
			{
				Node<T>* temp = new Node<T>[1];
				temp->Data = _item;
				_root->left = temp;
				_found = 1;
				return;
			}
			else
			{
				InsertNode(_item, _root->left, _found);
			}
		}
		else if (*_root->Data < *_item)
		{
			if (_root->right == nullptr)
			{
				Node<T>* temp = new Node<T>[1];
				temp->Data = _item;
				_root->right = temp;
				_found = 1;
				return;
			}
			else
			{
				InsertNode(_item, _root->right, _found);
			}
		}
	}
}

template <typename T>
void BinaryTree<T>::GetInorderSuccessor(Node<T>* _subroot) noexcept
{
	while (_subroot->left != nullptr)
	{
		_subroot = _subroot->left;
	};
	return;
}

template <typename T>
void BinaryTree<T>::DeleteNode(T* _item, Node<T>* _root, int& _found) noexcept
{
	if (*_root->Data == *_item)
	{
		_found = 1;
		if (_root->left == nullptr)
		{
			_root = _root->right;
		}
		else if (_root->right == nullptr)
		{
			_root = _root->left;
		}
		else
		{
			Node<T>* temp = new Node<T>[1];
			temp = _root;
			GetInorderSuccessor(temp);
			_root = temp;

		}
	}
}

template <typename T>
void BinaryTree<T>::DisplayInorder(Node<T>* _root) const noexcept
{
	if (_root != nullptr)
	{
		DisplayInorder(_root->left);
		std::cout << _root->Data;
		DisplayInorder(_root->right);
	}
}

template <typename T>
void BinaryTree<T>::DisplayPreorder(Node<T>* _root) const noexcept
{
	if (_root != nullptr && mLength != 0)
	{
		std::cout << _root->Data;
		if (_root->left != nullptr)
		{
			DisplayPreorder(_root->left);
		}
		if (_root->right != nullptr)
		{
			DisplayPreorder(_root->right);
		}

	}
}

template <typename T>
void BinaryTree<T>::DisplayPostorder(Node<T>* _root) const noexcept
{
	if (_root != nullptr)
	{
		DisplayPostorder(_root->left);
		DisplayPostorder(_root->right);
		std::cout << _root->Data;
	}
}

template <typename T>
void BinaryTree<T>::SearchNode(T* _item, Node<T>* _root, int& _found) const noexcept
{
	if (_root == nullptr)
	{
		return;
	}

	else if (*_root->Data == *_item)
	{
		_found = 1;
		_item = _root->Data;
		return;
	}
	else
	{
		SearchNode(_item, _root->left, _found);
		SearchNode(_item, _root->right, _found);
		return;
	}
}

template <typename T>
int BinaryTree<T>::GetLength() const noexcept
{
	return mLength;
}