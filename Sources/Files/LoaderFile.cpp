#include "../../Headers/Files/LoaderFile.hpp"

LoaderFile::LoaderFile() : File("makeloader.txt", true) {}

LoaderFile::~LoaderFile() {}

void LoaderFile::create()
{
    this->addContent("#This is the configuration file of MakeLoader.\n");
    this->addContent("#All these variables will be paste in the makefile.\n");
    this->addContent("#================Global variables===============\n\n");
    this->createVariable("COMPILER", "g++");
    this->createVariable("VERSION", "-std=c++17");
    this->createVariable("OUTPUT", "YourApplication");
    this->createVariable("LINKER_FLAGS", "-O");
    this->createVariable("COMPILER_FLAGS", "-Wall -Wextra -Wold-style-cast");
    this->createVariable("LIBS", "");
    this->addContent("\n#================Commands===============\n\n");
    this->createCommand("all", "Application", "");
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