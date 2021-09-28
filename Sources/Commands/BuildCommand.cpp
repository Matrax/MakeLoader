#include "../../Headers/Commands/BuildCommand.hpp"

BuildCommand::BuildCommand() : Command("build", "Build your makefile using the \"Sources\" directory") {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute()
{
	if(ApplicationFile::exist("makeloader.json") == false)
		throw std::runtime_error("You don't have a makeloader.json in your project !");

	std::cout << "[MakeLoader] Building the makefile ..." << std::endl;
	Application::getInstance().getMakefile().remove();
	Application::getInstance().getMakefile().createHeader(Application::getInstance().getLoaderfile().getJSON());
	Application::getInstance().getMakefile().createBody();
	Application::getInstance().getMakefile().save();
	std::cout << "[MakeLoader] Makefile builded !" << std::endl;
}
