#pragma once

#define MAKELOADER_VERSION_MAJOR 1
#define MAKELOADER_VERSION_MINOR 0

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Command.h"
#include "Makefile.h"

namespace MakeLoader
{
	class Application
	{

		private:

			MakeLoader::Makefile m_makefile;
			
			std::string m_command;
			std::vector<std::string> m_arguments;
			std::unordered_map<std::string, MakeLoader::Commands> m_commands;
		
		public:

			//Constructors and destructor
			Application();
			~Application();

			//Static function
			static void createDirectory(const std::string name);

			//Methods
			void start(const int & argc, char * argv[]);
			void execute(const std::string & command, const std::vector<std::string> & arguments);

			//Commands
			void cmd_create();
			void cmd_build();
			void cmd_make();
	};
};