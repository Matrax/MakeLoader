#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "Create all folders needed in your project and the makeloader file") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute() 
{
	Application * instance = Application::getInstance();

	if(instance == nullptr)
		throw std::runtime_error("There is no application instance !");

	std::cout << "\n[MakeLoader] Creating project ..." << std::endl;
	File::createDirectory("Sources");
	File::createDirectory("Headers");
	File::createDirectory("Includes");
	File::createDirectory("Builds");
	File::createDirectory("Objects");
	std::cout << "[MakeLoader] Project Folders OK !" << std::endl;
	
	if(File::exist("makeloader.json") == false)
	{
		instance->getLoaderfile()->create();
		std::cout << "[MakeLoader] Makeloader.json OK !" << std::endl;
	}

	if(File::exist("makefile") == false)
	{
		instance->getMakefile()->create();
		std::cout << "[MakeLoader] Makefile OK !" << std::endl;
	}
	
	std::cout << "[MakeLoader] Project OK !\n" << std::endl;
}