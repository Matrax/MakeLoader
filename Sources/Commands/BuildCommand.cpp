#include "../../Headers/Commands/BuildCommand.hpp"

BuildCommand::BuildCommand() : Command("build", "Build your makefile using the \"Sources\" directory") {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() 
{
	Application * instance = Application::getInstance();

	if(instance == nullptr)
		throw std::runtime_error("There is no Application instance !");

	if(File::exist("makeloader.json") == false)
		throw std::runtime_error("[MakeLoader] You don't have a makeloader.json in your project !\n");

	std::cout << "\n[MakeLoader] Building the makefile ..." << std::endl;
	instance->getMakefile()->remove();
	instance->getMakefile()->createHeader(instance->getLoaderfile()->getJSON());
	instance->getMakefile()->createBody();
	instance->getMakefile()->save();
	std::cout << "[MakeLoader] Makefile builded !\n" << std::endl;
}