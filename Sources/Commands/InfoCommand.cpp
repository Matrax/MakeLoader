#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "Show in the console all informations about MakeLoader") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	Application * instance = Application::getInstance();
	if(instance == nullptr)
		throw std::runtime_error("There is no Application instance !");
		
	instance->informations();
}