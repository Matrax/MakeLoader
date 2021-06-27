#include "../../Headers/Core/Makefile.hpp"

Makefile::Makefile() : m_file(std::ofstream()), m_content("") {}

Makefile::~Makefile()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }
}

void Makefile::build()
{
    std::vector<std::string> sources = this->getSources();

    if(sources.size() > 0)
    {
        this->createVariable("COMPILER", "g++");
        this->createVariable("VERSION", "-std=c++17");
        this->createVariable("OUTPUT", "YourApplication");
        this->createVariable("FLAGS", "-Wall");
        this->createVariable("LIBS", "");
        this->createCommand("all", "Application");
        this->createExecutable(sources);

        for(unsigned int i = 0; i < sources.size(); i++)
        {
            this->createTarget(sources[i]);
            std::cout << "[MakeLoader] " << sources[i] << " added to the makefile." << std::endl;
        }

    } else {
        std::cout << "[MakeLoader] You have no sources to build !" << std::endl;
    }
}

void Makefile::open()
{
    if(this->m_file.is_open() == false)
    {
        this->m_file.open("Makefile");
    } else {
        std::cout << "[MakeLoader] Can't open the Makefile !" << std::endl;
    }
}

void Makefile::save()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file << this->m_content << std::endl;
        this->m_file.flush();
    } else {
        std::cout << "[MakeLoader] Can't save the Makefile !" << std::endl;
    }
}

void Makefile::createExecutable(const std::vector<std::string> & sources)
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

    this->m_content.append("$(LIBS) -o Builds/$(OUTPUT)");
}

void Makefile::createCommand(const std::string name, const std::string value)
{
    this->m_content.append("\n");
    this->m_content.append(name);
    this->m_content.append(": ");
    this->m_content.append(value);
    this->m_content.append("\n");
}

void Makefile::createTarget(const std::string name)
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
    this->m_content.append(".o\n");
}

void Makefile::createVariable(const std::string name, const std::string value)
{
    this->m_content.append(name);
    this->m_content.append("=");
    this->m_content.append(value);
    this->m_content.append("\n");
}

std::vector<std::string> Makefile::getSources() const
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
    } else {
        std::cout << "[MakeLoader] You have no \"Sources\" directory in your project !" << std::endl;
    }

    return sources;
}