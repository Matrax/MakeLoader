#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class InfoCommand : public Command
{

    public:

        //Constructors and destructor
        InfoCommand();
        InfoCommand(const InfoCommand &) = delete;
        virtual ~InfoCommand();

        //Operators
		InfoCommand & operator=(const InfoCommand &) = delete;

        void execute() override;
};