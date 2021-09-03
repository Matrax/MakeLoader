#include "../../Headers/Files/MakeFile.hpp"

MakeFile::MakeFile() : File("makefile", false) {}

MakeFile::~MakeFile() {}

void MakeFile::build()
{
    std::vector<std::filesystem::path> sources = this->getSources();
    if(sources.size() > 0)
    {
        this->addContent("#================Linker===============\n\n");
        this->createExecutable(sources);
        this->addContent("#================Compiler===============\n\n");
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
    this->addContent("\nApplication:");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }
    this->addContent("\n\t$(COMPILER) $(COMPILER_FLAGS)");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }
    this->addContent(" $(LIBS) -o Builds/$(OUTPUT)\n\n");
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

    if(File::exist(directory) == true)
    {
        for (std::filesystem::directory_entry file : std::filesystem::recursive_directory_iterator(directory))
        {
            if(file.is_directory() == false) sources.push_back(file.path());
        }
    } else {
        std::cout << "[MakeLoader] You have no " << directory << " directory in your project !" << std::endl;
    }

    return sources;
}