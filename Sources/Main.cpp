#include "../Headers/Application.h"

#include <string>
#include <vector>

int main(int argc, char * argv[])
{
	MakeLoader::Application application;
	std::vector<std::string> arguments;

	if(argc > 1)
	{
		std::string command = argv[1];

		for(int i = 2; i < argc; i++) 
		{
			std::string arg = std::string(argv[i]);
			arguments.push_back(arg);
		}

		application.execute(command, arguments);
	} else {
		std::cout << "[MakeLoader] Version BETA-1.0" << std::endl;
		std::cout << "[MakeLoader] Commands available : {create, build, make}" << std::endl;
		std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader" << std::endl;
	}

	return 0;
}