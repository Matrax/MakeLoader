#include "../../Headers/Files/MakeFile.hpp"

/**
* Constructor of the class MakeFile.
* The makefile is not loaded from the disk, a entire makefile is regenerated each time.
* @author Matrax
* @version 1.0
*/
MakeFile::MakeFile() : File("makefile", false) {}

/**
* Desctructor of the class MakeFile.
* @author Matrax
* @version 1.0
*/
MakeFile::~MakeFile() {}

/**
* This method generate the content of the file.
* @author Matrax
* @version 1.0
*/
void MakeFile::generate()
{
    std::vector<std::filesystem::path> sources = this->getSources();
    if(sources.size() > 0)
    {
        this->addContent("#================Linker===============\n\n");
        this->createExecutable(sources);
        this->createStaticLibrary(sources);
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

/**
* This method add in the makefile the command line for the static library creation.
* @param std::vector<std::filesystem::path> sources The list of sources files in the project.
* @author Matrax
* @version 1.0
*/
void MakeFile::createStaticLibrary(std::vector<std::filesystem::path> sources)
{
    this->addContent("\nStaticLibrary:");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }

    this->addContent("\n\t$(ARCHIVER) rcs Builds/$(ARCHIVER_OUTPUT)");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }

    this->addContent("\n\n");
}

/**
* This method add in the makefile the command line for the executable creation.
* @param std::vector<std::filesystem::path> sources The list of sources files in the project.
* @author Matrax
* @version 1.0
*/
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

    this->addContent("\n\t$(COMPILER) $(LINKER_FLAGS)");
    for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
    {
        path->replace_extension("");
        this->addContent(" Objects/");
        this->addContent(path->filename().string());
        this->addContent(".o");
    }
    
    this->addContent(" $(LIBS) -o Builds/$(COMPILER_OUTPUT)\n\n");
}

/**
* This method add in the makefile the command line for a target.
* @param const std::string path The path of the source file.
* @param const std::string objectFile The name of the object file to generate.
* @author Matrax
* @version 1.0
*/
void MakeFile::createTarget(const std::string path, const std::string objectFile)
{
    this->addContent("\nObjects/");
    this->addContent(objectFile);
    this->addContent(".o : ");
    this->addContent(path);
    this->addContent(".cpp");
    this->addContent("\n\t$(COMPILER) -c ");
    this->addContent(path);
    this->addContent(".cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/");
    this->addContent(objectFile);
    this->addContent(".o\n");
}

/**
* This method return all the sources files from a directory.
* @param const std::string directory The directory where the program search for sources files.
* @author Matrax
* @version 1.0
*/
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