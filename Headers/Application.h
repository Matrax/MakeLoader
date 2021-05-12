#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

class Application
{
	
	public:

		std::string request() const;
		std::vector<std::string> getAllSources() const;

		void start() const;
		void createCommand() const;
		void buildCommand() const;
		void makeCommand() const;
};