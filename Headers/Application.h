#pragma once

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
			
			std::unordered_map<std::string, MakeLoader::Commands> m_commands;
		
		public:

			//Constructors and destructor
			Application();
			~Application();

			//Static function
			static void createDirectory(const std::string name);

			//Methods
			void execute(const std::string & command, const std::vector<std::string> & arguments);

			//Commands
			void cmd_create();
			void cmd_build();
			void cmd_make();
	};
};