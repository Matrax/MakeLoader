#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Command.h"
#include "Makefile.h"

namespace MakeLoader
{
	class Application
	{

		private:

			MakeLoader::Makefile m_makefile;
			std::map<std::string, MakeLoader::Commands> m_commands;

		
		public:

			Application();
			~Application();

			void execute(std::string command);
			void cmd_create();
			void cmd_build();
			void cmd_make();
	};
};