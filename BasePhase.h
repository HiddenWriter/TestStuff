#pragma once
class BasePhase
{
public:
	
	virtual PHASE Run() = 0;
	
	virtual void SetDataInformation(DATAINFORMATION* _status) noexcept = 0;

protected:

	virtual	int Add() = 0;

	virtual int Delete() = 0;

	virtual int Display() const noexcept = 0;

	virtual int Search() = 0;
	
};
