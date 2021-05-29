#include "../Headers/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "test") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	std::cout << "\n[MakeLoader] Version " << MAKELOADER_VERSION_MAJOR << "." << MAKELOADER_VERSION_MINOR << std::endl;
	std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader" << std::endl;
}