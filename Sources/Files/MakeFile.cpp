#include "../../Headers/Files/MakeFile.hpp"

MakeFile::MakeFile() : File("makefile", false) {}

MakeFile::~MakeFile() {}

void MakeFile::build()
{
    std::vector<std::filesystem::path> sources = this->getSources();
    if(sources.size() > 0)
    {
        this->createExecutable(sources);
        for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
        {
            path->replace_extension("");
            this->createTarget(path->string(), path->filename().string());
            std::cout << "[MakeLoader] " << path->string() << " added to the makefile." << std::endl;
        }
        this->save();
    } else {
        std::cout << "[MakeLoader] You have no sources to build !" << std::endl;
    }
}

void MakeFile::createExecutable(std::vector<std::filesystem::path> sources)
{
    this->addContent("\n");
    this->addContent("Application:");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }

    this->addContent("\n");
    this->addContent("\t$(COMPILER)");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }

    this->addContent(" $(LIBS) -o Builds/$(OUTPUT)\n");
}

void MakeFile::createTarget(const std::string path, const std::string objectFile)
{
    this->addContent("\nObjects/");
    this->addContent(objectFile);
    this->addContent(".o : ");
    this->addContent(path);
    this->addContent(".cpp");
    this->addContent("\n\t$(COMPILER) -c ");
    this->addContent(path);
    this->addContent(".cpp $(VERSION) $(FLAGS) -o Objects/");
    this->addContent(objectFile);
    this->addContent(".o\n");
}

std::vector<std::filesystem::path> MakeFile::getSources(const std::string directory) const
{
    std::vector<std::filesystem::path> sources;

    if(std::filesystem::exists(directory))
    {
        std::filesystem::directory_iterator directory_iterator(directory);
        for (std::filesystem::directory_entry file : directory_iterator)
        {
            std::filesystem::path path = file.path();
            if(file.is_directory() == true)
            {
                std::vector<std::filesystem::path> childSources = this->getSources(path.string());
                std::vector<std::filesystem::path>::iterator it;
                for(it = childSources.begin(); it != childSources.end(); it++)
                {
                    sources.push_back(*it);
                }
            } else {
                sources.push_back(path);
            }
        }
    } else {
        std::cout << "[MakeLoader] You have no " << directory << " directory in your project !" << std::endl;
    }

    return sources;
}