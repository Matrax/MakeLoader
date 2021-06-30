#include "../../Headers/Files/LoaderFile.hpp"

LoaderFile::LoaderFile() : File("makeloader.txt", true) {}

LoaderFile::~LoaderFile() {}

void LoaderFile::create()
{
    this->createVariable("COMPILER", "g++");
    this->createVariable("VERSION", "-std=c++17");
    this->createVariable("OUTPUT", "YourApplication");
    this->createVariable("FLAGS", "-Wall");
    this->createVariable("LIBS", "");
    this->createCommand("all", "Application");
    this->save();
}

void LoaderFile::createCommand(const std::string name, const std::string value)
{
    this->addContent("\n");
    this->addContent(name);
    this->addContent(": ");
    this->addContent(value);
    this->addContent("\n");
}

void LoaderFile::createVariable(const std::string name, const std::string value)
{
    this->addContent(name);
    this->addContent("=");
    this->addContent(value);
    this->addContent("\n");
}