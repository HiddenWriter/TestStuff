#pragma once

template <typename T>
class HeapMax : public BaseHeap<T>
{
public:
	
	void DisplayAll() noexcept;

};

template <typename T>
void HeapMax<T>::DisplayAll() noexcept
{
	std::unique_ptr<T> temp = std::make_unique<T>();

	int index = 0;
	while (index < this->mLength)
	{
		*temp.get() = this->mArray[index];
		std::cout << temp.get();
		index++;
	}
	return;
}
