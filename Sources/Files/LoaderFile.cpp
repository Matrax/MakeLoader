#include "../../Headers/Files/LoaderFile.hpp"

LoaderFile::LoaderFile() : File("makeloader", true) {}

LoaderFile::~LoaderFile() {}

/**
* This method generate the content of the file.
* @author Matrax
* @version 1.0
*/
void LoaderFile::generate()
{
    this->addContent("#================Global variables===============\n\n");
    this->createVariable("COMPILER", "g++");
    this->createVariable("ARCHIVER", "ar");
    this->createVariable("VERSION", "-std=c++17");
    this->createVariable("COMPILER_OUTPUT", "application");
    this->createVariable("ARCHIVER_OUTPUT", "libapplication.a");
    this->createVariable("LINKER_FLAGS", "-O");
    this->createVariable("COMPILER_FLAGS", "-Wall -Wextra -Wold-style-cast");
    this->createVariable("LIBS", "");
    this->addContent("\n#================Commands===============\n\n");
    this->createCommand("all", "Application", "");
    this->createCommand("app", "Application", "");
    this->createCommand("static-lib", "StaticLibrary", "");
    this->createCommand("clean", "", "rm Builds/$(OUTPUT)");
    this->save();
}

void LoaderFile::createCommand(const std::string name, const std::string requirement, const std::string command)
{
    this->addContent("\n");
    this->addContent(name);
    this->addContent(": ");
    this->addContent(requirement);

    if(command != "")
    {
        this->addContent("\n\t");
        this->addContent(command);
    }
    
    this->addContent("\n");
}

void LoaderFile::createVariable(const std::string name, const std::string value)
{
    this->addContent(name);
    this->addContent("=");
    this->addContent(value);
    this->addContent("\n");
}