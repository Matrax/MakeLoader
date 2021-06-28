#include "../../Headers/Core/Application.hpp"

std::shared_ptr<Application> Application::instance = std::shared_ptr<Application>(nullptr);

Application::Application() : m_commands(std::vector<Command *>(4)), m_makefile(std::shared_ptr<Makefile>(nullptr))
{
	this->m_commands.push_back(new CreateCommand());
	this->m_commands.push_back(new BuildCommand());
	this->m_commands.push_back(new MakeCommand());
	this->m_commands.push_back(new InfoCommand());
	Application::instance.reset(this);
}

Application::~Application() 
{
	for(unsigned int i = 0; i < this->m_commands.size(); i++)
	{
		if(this->m_commands[i] != nullptr)
		{
			delete this->m_commands[i];
			this->m_commands[i] = nullptr;
		}
	}
}

std::shared_ptr<Application> Application::getInstance()
{
	return Application::instance;
}

/**
 *
 * 
 * When the user enter a command, the application check all the command that exist 
 * in the application and execute the method "execute" of the command.
 */
void Application::start(const int & argc, char * argv[])
{
	if(argc <= 1) 
	{
		std::cout << "\n[MakeLoader] No command entered !" << std::endl;
		return;
	}

	this->m_makefile = std::shared_ptr<Makefile>(new Makefile());
	for(unsigned int i = 0; i < this->m_commands.size(); i++)
	{
		if(this->m_commands[i]->getName() == argv[1])
		{
			this->m_commands[i]->execute();
			break;
		}
	}
}

std::vector<Command *> Application::getCommands() const
{
	return this->m_commands;
}

std::shared_ptr<Makefile> Application::getMakefile() const
{
	return this->m_makefile;
}