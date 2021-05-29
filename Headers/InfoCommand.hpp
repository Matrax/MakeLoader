#pragma once

#define MAKELOADER_VERSION_MAJOR 1
#define MAKELOADER_VERSION_MINOR 0

#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class InfoCommand : public Command
{

    public:

        InfoCommand();
        virtual ~InfoCommand();

        void execute() override;
};