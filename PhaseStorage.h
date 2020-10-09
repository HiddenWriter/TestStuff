#pragma once
class PhaseStorage : public BasePhase
{
public:
	PhaseStorage();
	PhaseStorage(const PhaseStorage&) = delete;
	~PhaseStorage();

	PHASE Run() override;

	void SetDataInformation(DATAINFORMATION* _status) noexcept override;

private:

	int Add() override;

	int Delete() override;

	int Search() override;

	int Display() const noexcept override;

	PHASE SelectContainer();

private:
	
	DATAINFORMATION* STATUS;
	int mCtnSelect;
	BinaryTree<ContainerType>* StorageList;

};

