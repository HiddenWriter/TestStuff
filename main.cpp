#include  "pch.h"

int main(void)
{
	std::unique_ptr<Application> App1 = std::make_unique<Application>();
	
	App1->Run();

	return 0;
}