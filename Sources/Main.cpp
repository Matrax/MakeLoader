#include "../Headers/Application.h"

#include <string>
#include <vector>

int main(int argc, char * argv[])
{
	MakeLoader::Application application;

	if(argc > 1)
	{
		std::string command = argv[1];
		std::vector<std::string> arguments;
		for(int i = 2; i < argc; i++) 
		{
			std::string arg = std::string(argv[i]);
			arguments.push_back(arg);
		}
		application.execute(command, arguments);
	}

	return 0;
}