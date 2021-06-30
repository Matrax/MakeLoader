#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "This command show you in the console all informations about MakeLoader") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	std::cout << "\n[MakeLoader] Version 1.0" << std::endl;
	std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader" << std::endl;
}