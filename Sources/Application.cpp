#include "../Headers/Application.h"

void Application::start() const
{
	while (true)
	{
		std::string command = this->request();
		if (command == "create") this->createCommand(); // create: cr�er le projet
		if (command == "build") this->buildCommand(); // build: construit le makefile
		if (command == "make") this->makeCommand(); // build: construit le makefile
		if (command == "quit") break; // quit: Quitte le programme
	}
	std::cout << "[MakeLoader] Terminated" << std::endl;
}

std::string Application::request() const
{
	std::string command;
	std::cout << "[MakeLoader] > ";
	std::cin >> command;
	return command;
}

void Application::createCommand() const
{
	std::cout << "[MakeLoader] Creating the project" << std::endl;
	std::filesystem::create_directory("Sources");
	std::filesystem::create_directory("Headers");
	std::filesystem::create_directory("Binaries");
	std::cout << "[MakeLoader] Project created !" << std::endl;
}

void Application::buildCommand() const
{
	std::cout << "[MakeLoader] Building the project" << std::endl;
	//todo
	std::cout << "[MakeLoader] Project builded !" << std::endl;
}

void Application::makeCommand() const
{
	int result = std::system("make all");
	if(result != 0)
	{
		std::cout << "Error to do the make command !" << std::endl;
	}
}