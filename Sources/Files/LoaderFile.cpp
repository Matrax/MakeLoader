#include "../../Headers/Files/LoaderFile.hpp"

LoaderFile::LoaderFile() : ApplicationFile("makeloader.json", true) {}

LoaderFile::~LoaderFile() {}

/**
* This method generate the content of the makeloader file the first time it is created.
* @author Matrax
* @version 1.0
*/
void LoaderFile::onCreate()
{
  this->addContent("{\n");

  this->addContent("\t\"COMPILER\":\n");
  this->addContent("\t{\n");
  this->addContent("\t\t\"COMPILER_COMMAND\": \"g++\",\n");
  this->addContent("\t\t\"COMPILER_FLAGS\": \"-Wall -Wextra -Wold-style-cast\",\n");
  this->addContent("\t\t\"LINKER_OUTPUT\": \"application\",\n");
  this->addContent("\t\t\"LINKER_FLAGS\": \"-O2\",\n");
  this->addContent("\t\t\"VERSION\": \"-std=c++17\",\n");
  this->addContent("\t\t\"LIBS\": \"\"\n");
  this->addContent("\t},\n");

  this->addContent("\n");

  this->addContent("\t\"ARCHIVER\":\n");
  this->addContent("\t{\n");
  this->addContent("\t\t\"ARCHIVER_COMMAND\": \"ar\",\n");
  this->addContent("\t\t\"ARCHIVER_ARGUMENTS\": \"rcs\",\n");
  this->addContent("\t\t\"ARCHIVER_OUTPUT\": \"libapplication.a\"\n");
  this->addContent("\t}\n");

  this->addContent("}");
}

/**
* This method return the content of the file in JSON format.
* @return nlohmann::json The content of the file in JSON format.
* @author Matrax
* @version 1.0
*/
nlohmann::json LoaderFile::getJSON()
{
  return nlohmann::json::parse(this->getContent());
}
