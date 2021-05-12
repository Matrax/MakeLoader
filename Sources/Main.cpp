#include "../Headers/Application.h"

int main(int argc, char * argv[])
{
	MakeLoader::Application application;

	if(argc > 1)
	{
		std::string command = argv[1];
		application.execute(command);
	}

	return 0;
}