#pragma once

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

#include "Command.hpp"

class CreateCommand : public Command
{

    public:

        //Constructors and destructor
        CreateCommand();
        CreateCommand(const CreateCommand &) = delete;
        virtual ~CreateCommand();

        //Operators
		CreateCommand & operator=(const CreateCommand &) = delete;

        //Methods
        void execute() override;
        void createDirectory(const std::string name);
};