#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "Show in the console all informations about MakeLoader") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	if(Application::getInstance() == nullptr)
		throw std::runtime_error("There is no Application instance !");
		
	Application::getInstance()->informations();
}