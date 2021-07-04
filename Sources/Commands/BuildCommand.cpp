#include "../../Headers/Commands/BuildCommand.hpp"

BuildCommand::BuildCommand() : Command("build", "This command build your makefile using the \"Sources\" directory") {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() 
{
	if(File::exist("makeloader.txt") == true)
	{
		std::cout << "\n[MakeLoader] Building the makefile ..." << std::endl;
		std::string header = Application::getInstance()->getLoaderfile()->getContent();
		Application::getInstance()->getMakefile()->addContent(header);
		Application::getInstance()->getMakefile()->remove();
		Application::getInstance()->getMakefile()->build();
		std::cout << "[MakeLoader] Makefile builded !\n" << std::endl;
	} else {
		std::cout << "[MakeLoader] You don't have a makeloader file in your project !\n" << std::endl;
	}
}