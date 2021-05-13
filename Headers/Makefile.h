#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


namespace MakeLoader
{
    class Makefile 
    {

        private:

            std::ofstream m_file;
            std::string m_compiler;
            std::string m_version;
            std::string m_output;
            std::string m_content;
            std::vector<std::string> m_libs;
            std::vector<std::string> m_flags;

        public:

            Makefile();
            ~Makefile();

            void open();
            void save();
            void build(std::string & main);
            void close();

            void createVariable(std::string name, std::string value);
            void createVariable(std::string name, std::vector<std::string> & values);
            void createMainSource(std::vector<std::string> & sources);
            void createSource(std::string name);

            std::vector<std::string> getSources();

    };
};
