#pragma once

//Std includes
#include <iostream>
#include <vector>
#include <string>
#include <memory>

//Makeloader includes
#include "Command.hpp"
#include "../Core/Application.hpp"

/**
 * This class represent the "info" command of the application.
 * This command write on the console some of informations about MakeLoader.
 * @brief This class represent the "info" command of the application.
 * @author Matrax
 * @version 1.0
 */
class InfoCommand : public Command
{

    public:

        //Constructors and destructor
        InfoCommand();
        InfoCommand(const InfoCommand &) = delete;
        ~InfoCommand();

        //Operators
		InfoCommand & operator=(const InfoCommand &) = delete;

        //Overrided methods
        void execute() override;
};