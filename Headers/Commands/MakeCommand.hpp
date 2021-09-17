#pragma once

//Std includes
#include <iostream>
#include <vector>

//Makeloader includes
#include "Command.hpp"

/**
 * This class represent the "make" command of the application.
 * This command just call make to compile the project using the makefile generated with the application.
 * @brief This class represent the "make" command of the application.
 * @author Matrax
 * @version 1.0
 */
class MakeCommand : public Command
{

    public:

        //Constructors and destructor
        MakeCommand();
        MakeCommand(const MakeCommand &) = delete;
        ~MakeCommand();

        //Operators
		MakeCommand & operator=(const MakeCommand &) = delete;

        //Overrided methods
        void execute() override;
};