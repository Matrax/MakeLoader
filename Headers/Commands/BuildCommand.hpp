#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../Core/Application.hpp"
#include "../Core/Makefile.hpp"
#include "Command.hpp"

class BuildCommand : public Command
{

    public:

        //Constructors and destructor
        BuildCommand();
        BuildCommand(const BuildCommand &) = delete;
        virtual ~BuildCommand();

        //Operators
		BuildCommand & operator=(const BuildCommand &) = delete;

        void execute() override;
};