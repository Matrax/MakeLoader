#include "../../Headers/Files/LoaderFile.hpp"

LoaderFile::LoaderFile() : File("makeloader.json", true) {}

LoaderFile::~LoaderFile() {}

/**
* This method generate the content of the file.
* @author Matrax
* @version 1.0
*/
void LoaderFile::onCreate()
{
  this->addContent("{\n");
  this->addContent("\t\"COMPILER\": \"g++\",\n");
  this->addContent("\t\"ARCHIVER\": \"ar\",\n");
  this->addContent("\t\"VERSION\": \"-std=c++17\",\n");
  this->addContent("\t\"COMPILER_OUTPUT\": \"makeloader\",\n");
  this->addContent("\t\"ARCHIVER_OUTPUT\": \"\",\n");
  this->addContent("\t\"LINKER_FLAGS\": \"-O2\",\n");
  this->addContent("\t\"COMPILER_FLAGS\": \"-Wall -Wextra -Wold-style-cast\",\n");
  this->addContent("\t\"LIBS\": \"\"\n");
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
