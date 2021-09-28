#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "Create all folders needed in your project and the makeloader file") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute()
{
	if(ApplicationFile::exist("Sources") == false)
	{
		ApplicationFile::createDirectory("Sources");
		std::cout << "[MakeLoader] Sources folder created !" << std::endl;
	}

	if(ApplicationFile::exist("Headers") == false)
	{
		ApplicationFile::createDirectory("Headers");
		std::cout << "[MakeLoader] Headers folder created !" << std::endl;
	}

	if(ApplicationFile::exist("Includes") == false)
	{
		ApplicationFile::createDirectory("Includes");
		std::cout << "[MakeLoader] Includes folder created !" << std::endl;
	}

	if(ApplicationFile::exist("Builds") == false)
	{
		ApplicationFile::createDirectory("Builds");
		std::cout << "[MakeLoader] Builds folder created !" << std::endl;
	}

	if(ApplicationFile::exist("Objects") == false)
	{
		ApplicationFile::createDirectory("Objects");
		std::cout << "[MakeLoader] Objects folder created !" << std::endl;
	}

	if(ApplicationFile::exist("makeloader.json") == false)
	{
		Application::getInstance().getLoaderfile().create();
		std::cout << "[MakeLoader] Makeloader.json created !" << std::endl;
	}

	if(ApplicationFile::exist("makefile") == false)
	{
		Application::getInstance().getMakefile().create();
		std::cout << "[MakeLoader] Makefile created !" << std::endl;
	}
}
