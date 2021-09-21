#pragma once

//Std includes
#include <vector>
#include <filesystem>

//MakeLoader includes
#include "File.hpp"

//Json includes
#include "../../Includes/json.hpp"

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
        void onCreate() override;

        //Methods
        nlohmann::json getJSON();
        

};
