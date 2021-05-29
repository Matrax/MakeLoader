#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Command.hpp"
#include "CreateCommand.hpp"
#include "BuildCommand.hpp"
#include "MakeCommand.hpp"
#include "InfoCommand.hpp"
#include "Makefile.hpp"

class Application
{

	private:

		static std::shared_ptr<Application> instance;

		std::vector<Command *> m_commands;
		std::shared_ptr<Makefile> m_makefile;
		
	public:

		//Constructors and destructor
		Application();
		~Application();

		//Static functions
		static std::shared_ptr<Application> getInstance();

		//Methods
		void start(const int & argc, char * argv[]);

		//Getters
		std::vector<Command *> getCommands() const;
		std::shared_ptr<Makefile> getMakefile() const;
};