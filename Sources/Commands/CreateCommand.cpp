#include "../../Headers/Commands/CreateCommand.hpp"

CreateCommand::CreateCommand() : Command("create", "Create all folders needed in your project and the makeloader file") {}

CreateCommand::~CreateCommand() {}

void CreateCommand::execute()
{
	std::cout << "\n[MakeLoader] Creating project ..." << std::endl;

	if(File::exist("Sources") == false)
	{
		File::createDirectory("Sources");
		std::cout << "\n[MakeLoader] Sources folder created !" << std::endl;
	}

	if(File::exist("Headers") == false)
	{
		File::createDirectory("Headers");
		std::cout << "\n[MakeLoader] Headers folder created !" << std::endl;
	}

	if(File::exist("Includes") == false)
	{
		File::createDirectory("Includes");
		std::cout << "\n[MakeLoader] Includes folder created !" << std::endl;
	}

	if(File::exist("Builds") == false)
	{
		File::createDirectory("Builds");
		std::cout << "\n[MakeLoader] Builds folder created !" << std::endl;
	}

	if(File::exist("Objects") == false)
	{
		File::createDirectory("Objects");
		std::cout << "\n[MakeLoader] Objects folder created !" << std::endl;
	}

	if(File::exist("makeloader.json") == false)
	{
		Application::getInstance().getLoaderfile().create();
		std::cout << "[MakeLoader] Makeloader.json created !" << std::endl;
	}

	if(File::exist("makefile") == false)
	{
		Application::getInstance().getMakefile().create();
		std::cout << "[MakeLoader] Makefile created !" << std::endl;
	}

	std::cout << "[MakeLoader] Project OK !\n" << std::endl;
}
