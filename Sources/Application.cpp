#include "../Headers/Application.h"

void Application::createDirectories() const
{
	std::filesystem::create_directory("Sources");
	std::filesystem::create_directory("Headers");
	std::filesystem::create_directory("Binaries");
}

void Application::createMainFile() const
{
	std::ofstream main("Sources/Main.cpp");

	if (main.is_open() == true)
	{
		main << "#include <iostream>\n\n";
		main << "int main()\n";
		main << "{\n";
		main << "\tstd::cout << \"Fuck this world !\" << std::endl;\n";
		main << "\treturn 0;\n";
		main << "}\n";
		main.close();
		std::cout << "[MakeLoader] Main.cpp OK !" << std::endl;
	} else {
		std::cout << "[MakeLoader] Error on creating the Main.cpp file !" << std::endl;
	}
}

void Application::createMakeFile(const std::vector<std::string> & sources) const
{
	std::ofstream makefile("Makefile");

	if (makefile.is_open() == true)
	{
		makefile << "COMPILER=g++\n";
		makefile << "FLAGS=-Wall\n";
		makefile << "VERSION=-std=c++17\n\n";
		makefile << "all: application\n\n";
		for (std::vector<std::string>::const_iterator i = sources.begin(); i < sources.end(); i++)
		{
			makefile << "application: Sources/" << *i << "\n";
			makefile << "\t$(COMPILER) Sources/" << *i << " $(VERSION) $(FLAGS) -o application\n\n";
		}
		makefile.close();
		std::cout << "[MakeLoader] Makefile OK !" << std::endl;
	} else {
		std::cout << "[MakeLoader] Error on creating the Main.cpp file !" << std::endl;
	}
}

void Application::start() const
{
	while (true)
	{
		std::string command = this->request();
		if (command == "create") this->createCommand(); // create: créer le projet
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
	createDirectories();
	createMainFile();
	std::cout << "[MakeLoader] Project created !" << std::endl;
}

void Application::buildCommand() const
{
	std::cout << "[MakeLoader] Building the project" << std::endl;
	std::vector<std::string> sources = this->getAllSources();
	this->createMakeFile(sources);
	std::cout << "[MakeLoader] Project builded !" << std::endl;
}

void Application::makeCommand() const
{
	int result = -1;
	if (result != 0) result = std::system("make all");
	if (result != 0) result = std::system("mingw32-make all");
}

std::vector<std::string> Application::getAllSources() const
{
	std::vector<std::string> sources;
	std::filesystem::directory_iterator iterator("Sources");
	for (std::filesystem::directory_entry directory : iterator)
	{
		std::string filename = directory.path().filename().string();
		sources.push_back(filename);
	}
	return sources;
}