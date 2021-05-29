#include "../Headers/MakeCommand.hpp"

MakeCommand::MakeCommand() : Command("make", "test") {}

MakeCommand::~MakeCommand() {}

void MakeCommand::execute() 
{
	std::cout << "\n[MakeLoader] Compiling the project ..." << std::endl;
	int result = std::system("make all");

	if(result != 0) 
	{
		std::cout << "[MakeLoader] Can't execute the make commands, maybe make is not installed !" << std::endl;
	} else {
		std::cout << "[MakeLoader] Project compiled !" << std::endl;
	}
}