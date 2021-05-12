#include "../Headers/Makefile.h"

MakeLoader::Makefile::Makefile() : m_compiler("g++"), m_version("--std=c++17"), m_output("Application"), m_content("") 
{
    
}

MakeLoader::Makefile::~Makefile()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.close();
    }
}

void MakeLoader::Makefile::build()
{
    this->createVariable("COMPILER", this->m_compiler);
    this->createVariable("VERSION", this->m_version);
    this->createVariable("LIBS", this->m_libs);
    this->createVariable("FLAGS", this->m_flags);

    this->m_content.append("\n");
    this->createVariable("all", this->m_output);
    
    if(std::filesystem::exists("Sources") == true)
    {
        std::filesystem::directory_iterator directory_iterator("Sources");
        for (std::filesystem::directory_entry directory : directory_iterator)
        {
            std::string filename = directory.path().filename().string();
            this->m_content.append("\n");
            this->m_content.append("Binaries/");
            this->m_content.append(filename);
            this->m_content.append(": Sources/");
            this->m_content.append(filename);
            this->m_content.append("\n");
            this->m_content.append("\t$(COMPILER) Sources/");
            this->m_content.append(filename);
            this->m_content.append("$(VERSION) $(FLAGS) -o application\n");
        }
    }
}

void MakeLoader::Makefile::open()
{
    this->m_file.open("Makefile");
}

void MakeLoader::Makefile::save()
{
    if(this->m_file.is_open())
    {
        this->m_file << this->m_content;
        this->m_file.flush();
    } else {
        std::cout << "Error on saving the Makefile" << std::endl;
    }
}

void MakeLoader::Makefile::close()
{
    this->m_file.close();
}

void MakeLoader::Makefile::createVariable(std::string name, std::string value)
{
    this->m_content.append(name);
    this->m_content.append("=");
    this->m_content.append(value);
    this->m_content.append("\n");
}

void MakeLoader::Makefile::createVariable(std::string name, std::vector<std::string> values)
{
    this->m_content.append(name);
    this->m_content.append("=");
    for(unsigned int i = 0; i < values.size(); i++)
    {
        this->m_content.append(values[i]);
        this->m_content.append(" ");
    }
    this->m_content.append("\n");
}