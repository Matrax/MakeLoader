#pragma once

//Std includes
#include <iostream>
#include <vector>

//Makeloader includes
#include "../Core/Application.hpp"
#include "../Files/MakeFile.hpp"
#include "../Files/LoaderFile.hpp"
#include "Command.hpp"

/**
 * This class represent the "build" command of the application.
 * This command build the makefile of the project where the commmand is executed
 * using the Makeloader.txt for add variable to the makefile.
 * @brief This class represent the "build" command of the application.
 * @author Matrax
 * @version 1.0
 */
class BuildCommand : public Command
{

    public:

        //Constructors and destructor
        BuildCommand();
        BuildCommand(const BuildCommand &) = delete;
        virtual ~BuildCommand();

        //Operators
		    BuildCommand & operator=(const BuildCommand &) = delete;

        //Overrided methods
        void execute() override;
};
