#pragma once

//Std includes
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

//Makeloader includes
#include "../Files/MakeFile.hpp"
#include "../Files/LoaderFile.hpp"
#include "../Commands/Command.hpp"
#include "../Commands/CreateCommand.hpp"
#include "../Commands/BuildCommand.hpp"
#include "../Commands/MakeCommand.hpp"
#include "../Commands/InfoCommand.hpp"

/**
* This class represent the application.
* This class is a singleton, you can't have multiple instance.
* The Application class manage the commands in the program,
* the command entered by the user , the creation of the makeloader.json file, and the makefile generated.
* @author Matrax
* @version 1.0
**/
class Application
{

	private:

		//Static attributes
		static std::unique_ptr<Application> instance;

		//Attributes
		std::vector<std::shared_ptr<Command>> m_commands;
		std::unique_ptr<LoaderFile> m_loaderfile;
		std::unique_ptr<MakeFile> m_makefile;

	public:

		//Constructors and destructor
		Application();
		Application(const Application &) = delete;
		virtual ~Application();

		//Operators
		Application & operator=(const Application &) = delete;

		//Static functions
		static Application & getInstance();
		static void infos();

		//Methods
		void start(const int & argc, char * argv[]);
		MakeFile & getMakefile();
		LoaderFile & getLoaderfile();
		std::vector<std::shared_ptr<Command>> & getCommands();

};
