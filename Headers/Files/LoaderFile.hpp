#pragma once

//Std includes
#include <vector>
#include <filesystem>

//MakeLoader includes
#include "ApplicationFile.hpp"

//Json includes
#include "../../Includes/json.hpp"

/**
* This class represent the MakeLoader file used for generate your makefile.
* @author Matrax
* @version 1.0
**/
class LoaderFile : public ApplicationFile
{

    public:

        //Constructors and destructor
        LoaderFile();
        LoaderFile(const LoaderFile &) = delete;
        virtual ~LoaderFile();

        //Operators
        LoaderFile & operator=(const LoaderFile &) = delete;

        //Overrided methods
        void onCreate() override;

        //Methods
        nlohmann::json getJSON();


};
