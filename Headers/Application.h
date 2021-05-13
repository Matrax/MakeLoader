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

			Application();
			~Application();

			void execute(std::string & command, std::vector<std::string> & arguments);
			void cmd_create();
			void cmd_build(std::string & main);
			void cmd_make();
	};
};