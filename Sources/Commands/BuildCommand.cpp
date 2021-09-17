#include "../../Headers/Commands/BuildCommand.hpp"

BuildCommand::BuildCommand() : Command("build", "Build your makefile using the \"Sources\" directory") {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() 
{
	if(Application::getInstance() == nullptr)
		throw std::runtime_error("There is no Application instance !");

	if(File::exist("makeloader") == false)
		throw std::runtime_error("[MakeLoader] You don't have a makeloader file in your project !\n");

	std::cout << "\n[MakeLoader] Building the makefile ..." << std::endl;
	std::string header = Application::getInstance()->getLoaderfile()->getContent();
	Application::getInstance()->getMakefile()->addContent(header);
	Application::getInstance()->getMakefile()->regenerate();
	std::cout << "[MakeLoader] Makefile builded !\n" << std::endl;

}