#pragma once

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class CreateCommand : public Command
{

    public:

        CreateCommand();
        virtual ~CreateCommand();

        void createDirectory(const std::string name);
        void execute() override;
};