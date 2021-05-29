#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Application.hpp"
#include "Makefile.hpp"
#include "Command.hpp"

class BuildCommand : public Command
{

    public:

        BuildCommand();
        virtual ~BuildCommand();

        void execute() override;
};