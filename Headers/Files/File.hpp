#pragma once

//Std includes
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

/**
* This abstract class represent a file.
* It was developped to have an easier management of files 
* with the MakeLoader application. Every File classes need to
* redefine the methods generate.
* @author Matrax
* @version 1.0
**/
class File 
{

    private:

        //Attributes
        const std::string m_path;
        std::fstream m_file;
        std::string m_content;

    public:

        //Constructors and destructor
        File() = delete;
        File(std::string path, bool loadContent);
        virtual ~File();

        //Static functions
        static bool exist(const std::string path);
        static void createDirectory(const std::string name);

        //Virtual methods
        virtual void onCreate() = 0;

        //Methods
        void create();
        void remove();
        void save();
        void clear();
        void addContent(const std::string content);
        const std::string getPath() const;
        std::string getContent() const;
        std::string read();

};