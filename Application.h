#pragma once

class Application
{
public:

	Application();
	Application(const Application&) = delete;
	~Application();

	int Run();

private:

	PHASE GetPhase() noexcept;
	
private:

	int mCommand;
	int mPhase;

private:

	PhaseStorage Storage;
	PhaseContainer Container;
	PhaseMain Main;
	DATAINFORMATION* STATUS;

};
