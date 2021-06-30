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
        ~LoaderFile();

        //Methods
        void create();
        void createCommand(const std::string name, const std::string value);
        void createVariable(const std::string name, const std::string value);

};
