#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "This command create all the folders needed in your project and the Makeloader file") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute() 
{
	std::cout << "\n[MakeLoader] Creating the project folders ..." << std::endl;
	File::createDirectory("Sources");
	File::createDirectory("Headers");
	File::createDirectory("Builds");
	File::createDirectory("Objects");
	std::cout << "[MakeLoader] Project folders created !" << std::endl;

	if(File::exist("Makeloader.txt") == false)
	{
		std::cout << "[MakeLoader] Creating the Makeloader file ..." << std::endl;
		Application::getInstance()->getLoaderfile()->create();
		std::cout << "[MakeLoader] Makeloader file created !" << std::endl;
	} else {
		std::cout << "[MakeLoader] You already have a Makeloader file in your project !" << std::endl;
	}

}