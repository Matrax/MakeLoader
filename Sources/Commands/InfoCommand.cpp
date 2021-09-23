#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "Show in the console all informations about MakeLoader") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()
{
	Application::infos();
}
