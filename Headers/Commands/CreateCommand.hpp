#pragma once

//Std includes
#include <iostream>
#include <vector>
#include <string>

//Makeloader includes
#include "../Core/Application.hpp"
#include "../Files/MakeFile.hpp"
#include "../Files/LoaderFile.hpp"
#include "Command.hpp"

/**
 * This class represent the "create" command of the application.
 * This command create all the folders for the project and the Makeloader.txt
 * used by the application to generate the Makefile.
 * @brief This class represent the "create" command of the application.
 * @author Matrax
 * @version 1.0
 */
class CreateCommand : public Command
{

    public:

        //Constructors and destructor
        CreateCommand();
        CreateCommand(const CreateCommand &) = delete;
        ~CreateCommand();

        //Operators
		CreateCommand & operator=(const CreateCommand &) = delete;

        //Overrided methods
        void execute() override;
};