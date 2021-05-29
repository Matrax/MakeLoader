#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class MakeCommand : public Command
{

    public:

        MakeCommand();
        virtual ~MakeCommand();

        void execute() override;
};