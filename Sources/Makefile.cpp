#include "../Headers/Makefile.h"

MakeLoader::Makefile::Makefile() : m_compiler("g++"), m_version("--std=c++17"), m_output("Application"), m_content("") {}

MakeLoader::Makefile::~Makefile()
{
    this->close();
}

void MakeLoader::Makefile::build()
{
    std::vector<std::string> sources = this->getSources();

    this->createVariable("COMPILER", this->m_compiler);
    this->createVariable("VERSION", this->m_version);
    this->createVariable("OUTPUT", this->m_output);
    this->createVariable("LIBS", "");
    this->createVariable("FLAGS", "-Wall");
    this->createCommand("all", "Application");
    this->createMainSource(sources);

    for(unsigned int i = 0; i < sources.size(); i++)
    {
        this->createSource(sources[i]);
    }
}

void MakeLoader::Makefile::open()
{
    if(this->m_file.is_open() == false)
    {
        this->m_file.open("Makefile");
    }
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
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }
}

void MakeLoader::Makefile::createMainSource(const std::vector<std::string> & sources)
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

void MakeLoader::Makefile::createCommand(const std::string name, const std::string value)
{
    this->m_content.append("\n");
    this->m_content.append(name);
    this->m_content.append(": ");
    this->m_content.append(value);
    this->m_content.append("\n");
}

void MakeLoader::Makefile::createSource(const std::string name)
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

void MakeLoader::Makefile::createVariable(const std::string name, const std::string value)
{
    this->m_content.append(name);
    this->m_content.append("=");
    this->m_content.append(value);
    this->m_content.append("\n");
}

std::vector<std::string> MakeLoader::Makefile::getSources() const
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