#pragma once
class PhaseMain : public BasePhase
{
public:

	PhaseMain();
	PhaseMain(const PhaseMain&) = delete;
	~PhaseMain();

	PHASE Run() override;

	void SetDataInformation(DATAINFORMATION* _status) noexcept override;

private:

	int Add() override;

	int Delete() override;

	int Display() const noexcept override;

	int Search() override;

	PHASE SelectStorage();

private:

	std::unique_ptr<DoublyLinkedList<StorageType>> MasterList;
	int mStgSelect;
	PHASE mPhase;
	DATAINFORMATION* STATUS;

};

