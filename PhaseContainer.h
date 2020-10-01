#pragma once
class PhaseContainer : public BasePhase
{
public:
	PhaseContainer();
	PhaseContainer(const PhaseContainer&) = delete;
	~PhaseContainer() { return; }

	PHASE Run() override;

	void SetDataInformation(DATAINFORMATION* _status) noexcept override;

private:

	int Add() override;

	int Delete() override;

	int Display() const noexcept override;

	int Search() override;

	PHASE SelectItem();

private:

	DATAINFORMATION* STATUS;
	int mItemSelect;
	SortedList<ItemType>* ItemList;

};

