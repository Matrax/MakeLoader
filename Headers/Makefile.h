#pragma once

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

        std::vector<std::string> m_sources;
        std::vector<std::string> m_libs;
        std::vector<std::string> m_flags;

    public:

        Makefile();
        ~Makefile();

        static std::vector<std::string> getAllSources();

        void build();
        void save();

};