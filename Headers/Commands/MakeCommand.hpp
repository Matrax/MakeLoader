#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class MakeCommand : public Command
{

    public:

        //Constructors and destructor
        MakeCommand();
        MakeCommand(const MakeCommand &) = delete;
        virtual ~MakeCommand();

        //Operators
		MakeCommand & operator=(const MakeCommand &) = delete;

        void execute() override;
};