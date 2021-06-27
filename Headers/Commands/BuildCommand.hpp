#pragma once

//Std includes
#include <iostream>
#include <vector>
#include <string>

//Makeloader includes
#include "../Core/Application.hpp"
#include "../Core/Makefile.hpp"
#include "Command.hpp"

/**
 * This class represent the "build" command of the application.
 * This command build the makefile of the project where the commmand is executed.
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
        ~BuildCommand();

        //Operators
		BuildCommand & operator=(const BuildCommand &) = delete;

        //Overrided methods
        void execute() override;
};