#include "../../Headers/Core/Application.hpp"

std::unique_ptr<Application> Application::instance = std::unique_ptr<Application>(nullptr);

Application::Application() : 
	m_commands(std::vector<std::unique_ptr<Command>>()), 
	m_loaderfile(std::make_unique<LoaderFile>()),
	m_makefile(std::make_unique<MakeFile>())
{
	this->m_commands.push_back(std::make_unique<CreateCommand>());
	this->m_commands.push_back(std::make_unique<BuildCommand>());
	this->m_commands.push_back(std::make_unique<MakeCommand>());
	this->m_commands.push_back(std::make_unique<InfoCommand>());
	Application::instance.reset(this);
}

Application::~Application() 
{
	Application::instance.release();
}

Application * Application::getInstance()
{
	return Application::instance.get();
}

void Application::start(const int & argc, char * argv[])
{
	if(argc <= 1) 
	{
		std::cout << "\n[MakeLoader] No command entered !\n" << std::endl;
		return;
	}

	for(unsigned int i = 0; i < this->m_commands.size(); i++)
	{
		if(this->m_commands[i]->getName() == argv[1])
		{
			this->m_commands[i]->execute();
			break;
		}
	}
}

std::vector<std::unique_ptr<Command>> & Application::getCommands()
{
	return this->m_commands;
}

MakeFile * Application::getMakefile()
{
	return this->m_makefile.get();
}

LoaderFile * Application::getLoaderfile()
{
	return this->m_loaderfile.get();
}