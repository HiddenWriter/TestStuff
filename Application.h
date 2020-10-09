#pragma once

class Application
{
public:

	Application();
	Application(const Application&) = delete;
	~Application();

	int Run();

private:

	PhaseStorage* GetStoragePhase();
	PhaseContainer* GetContainerPhase();
	PhaseMain* GetMainPhase();
	BasePhase* AppCtrl;

	StorageType* GetStorage();
	ContainerType* GetContainer();
	ItemType* GetItem();
	BaseItem* ItemCtrl;

	void ReleaseResource();
	void GetPhase() noexcept;
private:

	int mCommand;
	int mPhase;

};
