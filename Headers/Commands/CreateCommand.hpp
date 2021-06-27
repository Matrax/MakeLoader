#pragma once

//Std includes
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

//Makeloader includes
#include "Command.hpp"

/**
 * This class represent the "create" command of the application.
 * This command create all the folders for the project.
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

        //Methods
        void createDirectory(const std::string name);
};