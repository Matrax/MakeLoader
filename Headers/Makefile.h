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
            void build();
            void close();

            void createVariable(std::string name, std::string value);
            void createVariable(std::string name, std::vector<std::string> values);

    };
};
