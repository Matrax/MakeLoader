#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "Create all folders needed in your project and the makeloader file") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute() 
{
	if(Application::getInstance() == nullptr)
		throw std::runtime_error("There is no application instance !");

	if(File::exist("makeloader") == true)
		throw std::runtime_error("You already have a Makeloader file in your project !");

	std::cout << "\n[MakeLoader] Creating the project folders ..." << std::endl;
	File::createDirectory("Sources");
	File::createDirectory("Headers");
	File::createDirectory("Builds");
	File::createDirectory("Objects");
	std::cout << "[MakeLoader] Project folders created !" << std::endl;
	std::cout << "[MakeLoader] Creating the Makeloader file ..." << std::endl;
	Application::getInstance()->getLoaderfile()->generate();
	std::cout << "[MakeLoader] Makeloader file created !\n" << std::endl;
}