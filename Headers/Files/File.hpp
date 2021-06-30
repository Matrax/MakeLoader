#pragma once

//Std includes
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

class File 
{

    private:

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

        //Methods
        void remove();
        void save();
        void clear();
        void addContent(const std::string content);
        const std::string getPath() const;
        std::string getContent() const;
        std::string read();

};