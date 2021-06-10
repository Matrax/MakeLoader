#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Makefile.hpp"
#include "../Commands/Command.hpp"
#include "../Commands/CreateCommand.hpp"
#include "../Commands/BuildCommand.hpp"
#include "../Commands/MakeCommand.hpp"
#include "../Commands/InfoCommand.hpp"

/**
* This class represent the application.
* This class is a singleton, you can't have multiple instance.
* The Application class manage the commands in the program,
* the command entered by the user and the makefile generated.
* @author Matrax
* @version 1.0
**/
class Application
{

	private:

		//Static attributes
		static std::shared_ptr<Application> instance;

		//Attributes
		std::vector<Command *> m_commands;
		std::shared_ptr<Makefile> m_makefile;
		
	public:

		//Constructors and destructor
		Application();
		Application(const Application &) = delete;
		virtual ~Application();

		//Operators
		Application & operator=(const Application &) = delete;

		//Static functions
		static std::shared_ptr<Application> getInstance();

		//Methods
		void start(const int & argc, char * argv[]);
		std::vector<Command *> getCommands() const;
		std::shared_ptr<Makefile> getMakefile() const;
};