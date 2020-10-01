#pragma once

template <typename T>
class HeapMin : public BaseHeap<T>
{
	int Add(T* _item) override;
};

template <typename T>
int HeapMin<T>::Add(T* _item)
{
	return 1;
}