#include "../../Headers/Commands/InfoCommand.hpp"

InfoCommand::InfoCommand() : Command("info", "This command show you in the console all informations about MakeLoader") {}

InfoCommand::~InfoCommand() {}

void InfoCommand::execute()  
{
	std::cout << "\nMakeLoader  Copyright (C) 2021 Alexandre Pierret" << std::endl;
	std::cout << "This program comes with ABSOLUTELY NO WARRANTY;" << std::endl;
	std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
	std::cout << "\n[MakeLoader] Version 1.0" << std::endl;
	std::cout << "[MakeLoader] More informations at https://github.com/Matrax/MakeLoader\n" << std::endl;
}