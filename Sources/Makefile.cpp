#include "../Headers/Makefile.h"

Makefile::Makefile() : m_compiler("g++"), m_output("Application"), m_version("--std=c++17")
{
    this->m_file.open("Makefile");
}

Makefile::~Makefile()
{
    this->m_file.close();
}

void Makefile::build()
{
    //GCC Compiler
    this->m_content.append("COMPILER=");
    this->m_content.append(this->m_compiler);
    this->m_content.append("\n");

    //GCC Version
    this->m_content.append("VERSION=");
    this->m_content.append(this->m_version);
    this->m_content.append("\n\n");

    //Libraries
    this->m_content.append("LIBS=");
    for(int i = 0; i < this->m_libs.size(); i++)
    {
        this->m_content.append(this->m_libs[i]);
        this->m_content.append(" ");
    }
    this->m_content.append("\n\n");

    //Application
    this->m_content.append("all: ");
    this->m_content.append(this->m_output);
    this->m_content.append("\n\n");

    //Sources
    std::vector<std::string>::const_iterator iterator;
	for (iterator = this->m_sources.begin(); iterator < this->m_sources.end(); iterator++)
	{
        this->m_content.append("Binaries/");
        this->m_content.append(*iterator);
        this->m_content.append(": Sources/");
        this->m_content.append(*iterator);
        this->m_content.append("\n");
        this->m_content.append("\t$(COMPILER) Sources/");
        this->m_content.append(*iterator);
        this->m_content.append("$(VERSION) $(FLAGS) -o application\n\n");
	}
}

void Makefile::save()
{
    if(this->m_file.is_open())
    {
        this->m_file << this->m_content;
    } else {
        std::cout << "Error on saving the Makefile" << std::endl;
    }
}

std::vector<std::string> Makefile::getAllSources()
{
	std::vector<std::string> sources;
	std::filesystem::directory_iterator iterator("Sources");
	for (std::filesystem::directory_entry directory : iterator)
	{
		std::string filename = directory.path().filename().string();
		sources.push_back(filename);
	}
	return sources;
}