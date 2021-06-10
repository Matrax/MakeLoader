#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "test") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	std::cout << "\n[MakeLoader] Version 1.0" << std::endl;
	std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader" << std::endl;
}