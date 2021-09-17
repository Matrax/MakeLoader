#include "../../Headers/Commands/MakeCommand.hpp"

MakeCommand::MakeCommand() : Command("make", "Call the \"make\" program to compile your project") {}

MakeCommand::~MakeCommand() {}

void MakeCommand::execute() 
{
	std::cout << "\n[MakeLoader] Compiling the project ..." << std::endl;
	int result = std::system("make all");
	
	if(result == 0) 
		throw std::runtime_error("Error on execute \"Make\" !");

	std::cout << "[MakeLoader] Project compiled !\n" << std::endl;

	
}