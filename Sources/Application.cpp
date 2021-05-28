#include "../Headers/Application.h"

MakeLoader::Application::Application()
{
	this->m_commands["create"] = MakeLoader::Commands::CREATE;
	this->m_commands["build"] = MakeLoader::Commands::BUILD;
	this->m_commands["make"] = MakeLoader::Commands::MAKE;
}

MakeLoader::Application::~Application() 
{
	this->m_makefile.close();
	this->m_commands.clear();
	this->m_arguments.clear();
}

void MakeLoader::Application::start(const int & argc, char * argv[])
{
	if(argc > 1)
	{
		this->m_command = std::string(argv[1]);
		for(int i = 2; i < argc; i++) 
		{
			std::string arg = std::string(argv[i]);
			this->m_arguments.push_back(arg);
		}
		this->execute(this->m_command, this->m_arguments);
	} else {
		std::cout << "\n[MakeLoader] Version " << MAKELOADER_VERSION_MAJOR << "." << MAKELOADER_VERSION_MINOR << std::endl;
		std::cout << "[MakeLoader] Commands available : {create, build, make}" << std::endl;
		std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader" << std::endl;
	}
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

	if(result != 0) 
	{
		std::cout << "[Error] can't execute the make commands, maybe make is not installed !" << std::endl;
	} else {
		std::cout << "[MakeLoader] Project compiled !" << std::endl;
	}
	
}