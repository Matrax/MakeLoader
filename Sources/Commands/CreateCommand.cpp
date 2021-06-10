#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "test") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute() 
{
	std::cout << "\n[MakeLoader] Creating the project folders ..." << std::endl;
	this->createDirectory("Sources");
	this->createDirectory("Headers");
	this->createDirectory("Builds");
	this->createDirectory("Binaries");
	std::cout << "[MakeLoader] Project folders created !" << std::endl;
}

void CreateCommand::createDirectory(const std::string name)
{
	if(std::filesystem::exists(name) == false)
	{
		std::filesystem::create_directory(name);
		std::cout << "[MakeLoader] The directory " << name << " is now created." << std::endl;
	} else { 
		std::cout << "[MakeLoader] The directory " << name << " already exist !" << std::endl;
	}
}