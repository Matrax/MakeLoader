#include "../Headers/Makefile.h"

MakeLoader::Makefile::Makefile() : m_compiler("g++"), m_version("--std=c++17"), m_output("Builds/Application"), m_content("") 
{
    
}

MakeLoader::Makefile::~Makefile()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.close();
    }
}

void MakeLoader::Makefile::build(std::string & main)
{
    std::vector<std::string> sources = this->getSources();

    this->createVariable("COMPILER", this->m_compiler);
    this->createVariable("OUTPUT", this->m_output);
    this->createVariable("VERSION", this->m_version);
    this->createVariable("LIBS", this->m_libs);
    this->createVariable("FLAGS", this->m_flags);
    this->m_content.append("\n");

    //Program
    this->m_content.append("all: Application\n\n");

    //Main
    this->createMainSource(sources);
    this->m_content.append("\n");

    for(unsigned int i = 0; i < sources.size(); i++)
    {
        std::string source = sources[i];
        this->createSource(source);
        this->m_content.append("\n");
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

void MakeLoader::Makefile::createMainSource(std::vector<std::string> & sources)
{
    this->m_content.append("\n");
    this->m_content.append("Application:");
    for(unsigned int i = 0; i < sources.size(); i++)
    {
        this->m_content.append(" Binaries/");
        this->m_content.append(sources[i]);
        this->m_content.append(".o");
    }
    this->m_content.append("\n");
    this->m_content.append("\t$(COMPILER)");
    for(unsigned int i = 0; i < sources.size(); i++)
    {
        this->m_content.append(" Binaries/");
        this->m_content.append(sources[i]);
        this->m_content.append(".o ");
    }
    this->m_content.append("$(LIBS) -o $(OUTPUT)");
}

void MakeLoader::Makefile::createSource(std::string name)
{
    this->m_content.append("\nBinaries/");
    this->m_content.append(name);
    this->m_content.append(".o : Sources/");
    this->m_content.append(name);
    this->m_content.append(".cpp");
    this->m_content.append("\n\t$(COMPILER) -c Sources/");
    this->m_content.append(name);
    this->m_content.append(".cpp $(VERSION) $(FLAGS) -o Binaries/");
    this->m_content.append(name);
    this->m_content.append(".o");
}

void MakeLoader::Makefile::createVariable(std::string name, std::string value)
{
    this->m_content.append(name);
    this->m_content.append("=");
    this->m_content.append(value);
    this->m_content.append("\n");
}

void MakeLoader::Makefile::createVariable(std::string name, std::vector<std::string> & values)
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

std::vector<std::string> MakeLoader::Makefile::getSources()
{
    std::vector<std::string> sources;
    if(std::filesystem::exists("Sources"))
    {
        std::filesystem::directory_iterator directory_iterator("Sources");
        for (std::filesystem::directory_entry directory : directory_iterator)
        {
            std::filesystem::path filename = directory.path().filename();
            std::string filenameNoExtension = filename.replace_extension("").string();
            sources.push_back(filenameNoExtension);
        }
    }
    return sources;
}