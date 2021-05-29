#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Makefile 
{

    private:

        std::ofstream m_file;
        std::string m_compiler;
        std::string m_version;
        std::string m_output;
        std::string m_content;

    public:

        Makefile();
        ~Makefile();

        void build();
        void open();
        void save();

        void createCommand(const std::string name, const std::string value);
        void createVariable(const std::string name, const std::string value);
        void createMainSource(const std::vector<std::string> & sources);
        void createSource(const std::string name);

        std::vector<std::string> getSources() const;

};
