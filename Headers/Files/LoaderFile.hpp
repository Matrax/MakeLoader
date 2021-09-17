#pragma once

//Std includes
#include <vector>
#include <filesystem>

//MakeLoader includes
#include "File.hpp"

/**
* This class represent the MakeLoader file used for generate your makefile.
* @author Matrax
* @version 1.0
**/
class LoaderFile : public File
{

    public:

        //Constructors and destructor
        LoaderFile();
        virtual ~LoaderFile();

        //Overrided methods
        void generate() override;

        //Methods
        void createVariable(const std::string name, const std::string value);
        void createCommand(const std::string name, const std::string requirement, const std::string command);

};
