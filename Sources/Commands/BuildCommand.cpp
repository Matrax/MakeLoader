#include "../../Headers/Commands/BuildCommand.hpp"

BuildCommand::BuildCommand() : Command("build", "test") {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() 
{
	std::cout << "\n[MakeLoader] Building the makefile ..." << std::endl;
	std::shared_ptr<Makefile> makefile = Application::getInstance()->getMakefile();
	makefile->open();
	makefile->build();
	makefile->save();
	std::cout << "[MakeLoader] Makefile builded !" << std::endl;
}