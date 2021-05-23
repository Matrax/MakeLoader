#include "../Headers/Application.h"

MakeLoader::Application::Application()
{
	this->m_commands["create"] = MakeLoader::Commands::CREATE;
	this->m_commands["build"] = MakeLoader::Commands::BUILD;
	this->m_commands["make"] = MakeLoader::Commands::MAKE;
}

MakeLoader::Application::~Application() 
{
	this->m_commands.clear();
}

void MakeLoader::Application::createDirectory(const std::string name)
{
	if(std::filesystem::exists(name) == false)
	{
		std::filesystem::create_directory(name);
		std::cout << "[MakeLoader] The directory " << name << " is now created !" << std::endl;
	} else { 
		std::cout << "[MakeLoader] The directory " << name << " already exist !" << std::endl;
	}
}

void MakeLoader::Application::execute(const std::string & command, const std::vector<std::string> & arguments)
{
	MakeLoader::Commands value = this->m_commands[command];
	switch (value)
	{
		case MakeLoader::Commands::CREATE:
			this->cmd_create();
			break;
		case MakeLoader::Commands::BUILD:
			this->cmd_build();
			break;
		case MakeLoader::Commands::MAKE:
			this->cmd_make();
			break;
		default:
			std::cout << "[MakeLoader] No commands found !" << std::endl;
			break;
	}
}

void MakeLoader::Application::cmd_create()
{
	std::cout << "[MakeLoader] Creating the project ..." << std::endl;
	this->createDirectory("Sources");
	this->createDirectory("Headers");
	this->createDirectory("Builds");
	this->createDirectory("Binaries");
	std::cout << "[MakeLoader] Project created !" << std::endl;
}

void MakeLoader::Application::cmd_build()
{
	std::cout << "[MakeLoader] Building the project" << std::endl;
	this->m_makefile.open();
	this->m_makefile.build();
	this->m_makefile.save();
	this->m_makefile.close();
	std::cout << "[MakeLoader] Project builded !" << std::endl;
}

void MakeLoader::Application::cmd_make()
{
	std::cout << "[MakeLoader] Compiling the project ..." << std::endl;
	int result = std::system("make all");
	if(result != 0) std::cout << "[Error] make" << std::endl;
	std::cout << "[MakeLoader] Project compiled !" << std::endl;
}