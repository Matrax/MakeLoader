#include "../../Headers/Core/Application.hpp"

std::unique_ptr<Application> Application::instance = std::unique_ptr<Application>(nullptr);

Application::Application() : 
	m_commands(std::vector<std::shared_ptr<Command>>()), 
	m_loaderfile(std::make_unique<LoaderFile>()),
	m_makefile(std::make_unique<MakeFile>())
{
	this->m_commands.push_back(std::make_shared<CreateCommand>());
	this->m_commands.push_back(std::make_shared<BuildCommand>());
	this->m_commands.push_back(std::make_shared<MakeCommand>());
	this->m_commands.push_back(std::make_shared<InfoCommand>());
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
		std::cout << "\n[MakeLoader] You need to put an argument !" << std::endl;
		std::cout << "[MakeLoader] type: makeloader info\n" << std::endl;
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

std::vector<std::shared_ptr<Command>> & Application::getCommands()
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