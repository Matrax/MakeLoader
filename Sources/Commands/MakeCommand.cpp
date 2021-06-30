#include "../../Headers/Commands/MakeCommand.hpp"

MakeCommand::MakeCommand() : Command("make", "This command just call the \"make\" program to compile your project") {}

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