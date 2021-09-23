#include "../../Headers/Files/MakeFile.hpp"

/**
* Constructor of the class MakeFile.
* The makefile is not loaded from the disk, a entire makefile is regenerated each time.
* @author Matrax
* @version 1.0
*/
MakeFile::MakeFile() : File("makefile", false) {}

/**
* Destructor of the class MakeFile.
* @author Matrax
* @version 1.0
*/
MakeFile::~MakeFile() {}

/**
* This method generate the content of the file.
* @author Matrax
* @version 1.0
*/
void MakeFile::onCreate()
{
  this->addContent("#The makefile will be generated here.");
}

void MakeFile::createHeader(nlohmann::json configurations)
{
  this->addContent("#================Header===============\n\n");
  this->createVariable("COMPILER", configurations["COMPILER"]);
  this->createVariable("ARCHIVER", configurations["ARCHIVER"]);
  this->createVariable("VERSION", configurations["VERSION"]);
  this->createVariable("COMPILER_OUTPUT", configurations["COMPILER_OUTPUT"]);
  this->createVariable("ARCHIVER_OUTPUT", configurations["ARCHIVER_OUTPUT"]);
  this->createVariable("LINKER_FLAGS", configurations["LINKER_FLAGS"]);
  this->createVariable("COMPILER_FLAGS", configurations["COMPILER_FLAGS"]);
  this->createVariable("LIBS", configurations["LIBS"]);
  this->addContent("\n");
}

void MakeFile::createBody()
{
  std::vector<std::filesystem::path> sources = this->getSources();

  if(sources.size() <= 0)
  throw std::runtime_error("You have no sources to build !");

  this->addContent("#================Commands===============\n");
  this->createCommand("all", "Application", "");
  this->createCommand("app", "Application", "");
  this->createCommand("static-lib", "StaticLibrary", "");
  this->createCommand("clean", "", "rm Builds/$(OUTPUT)");
  this->addContent("\n#================Linker===============\n");
  this->createExecutable(sources);
  this->createStaticLibrary(sources);
  this->addContent("#================Compiler===============\n");

  for(std::vector<std::filesystem::path>::iterator path = sources.begin(); path != sources.end(); path++)
  {
    path->replace_extension("");
    this->createTarget(path->string(), path->filename().string());
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
  if(sources.size() <= 0)
    throw std::runtime_error("You have no sources to create the library command line !");

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
  if(sources.size() <= 0)
    throw std::runtime_error("You have no sources to create the executable command line !");

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
  if(path.empty() == true)
    throw std::runtime_error("No path specified for the target !");

  if(objectFile.empty() == true)
    throw std::runtime_error("No object file specified for the target !");

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

void MakeFile::createCommand(const std::string name, const std::string requirement, const std::string command)
{
  if(name.empty() == true)
    throw std::runtime_error("No name specified for the command !");

  this->addContent("\n");
  this->addContent(name);
  this->addContent(": ");

  if(requirement.empty() == false)
  {
    this->addContent(requirement);
  }

  if(command.empty() == false)
  {
    this->addContent("\n\t");
    this->addContent(command);
  }

  this->addContent("\n");
}

void MakeFile::createVariable(const std::string name, const std::string value)
{
  if(name.empty() == true)
    throw std::runtime_error("No name specified for the variable !");

  this->addContent(name);
  this->addContent("=");

  if(value.empty() == false)
  {
    this->addContent(value);
  }

  this->addContent("\n");
}

/**
* This method return all the sources files from a directory.
* @param const std::string directory The directory where the program search for sources files.
* @return std::vector<std::filesystem::path> All the sources files from a directory.
* @author Matrax
* @version 1.0
*/
std::vector<std::filesystem::path> MakeFile::getSources(const std::string directory) const
{
  std::vector<std::filesystem::path> sources;

  if(File::exist(directory) == false)
    throw std::runtime_error("The directory doesn't exist !");

  for (std::filesystem::directory_entry file : std::filesystem::recursive_directory_iterator(directory))
  {
    if(file.is_directory() == false) sources.push_back(file.path());
  }

  return sources;
}
