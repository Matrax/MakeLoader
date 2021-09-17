#include "../../Headers/Files/File.hpp"

/**
* Constructor of the abstract class File.
* @param std::string path The path of the file.
* @param bool loadContent If the file need to be loaded from the disk in the constructor.
* @author Matrax
* @version 1.0
*/
File::File(std::string path, bool loadContent) : 
    m_path(path), 
    m_file(std::fstream()),
    m_content("") 
{
    if(loadContent == true && File::exist(path) == true)
    {
        this->m_file.open(this->m_path, std::fstream::in);
        this->m_content = this->read();
        this->m_file.close();
    }
}

/**
* Destructor of the class File.
* If the file is open, the destructor flush and close the file.
* @author Matrax
* @version 1.0
*/
File::~File()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }
}

/**
* This static function create a directory.
* This function show an error message if the directory already exist.
* @param const std::string name The name of the directory.
* @author Matrax
* @version 1.0
*/
void File::createDirectory(const std::string name)
{
	std::filesystem::create_directory(name);
	std::cout << "[MakeLoader] The directory " << name << " is created." << std::endl;
}

/**
* This static function check if a directory or a file exist.
* @param const std::string path The name of the directory.
* @return bool if the directory alraedy exist. 
* @author Matrax
* @version 1.0
*/
bool File::exist(const std::string path)
{
    return std::filesystem::exists(path);
}

/**
* This method remove the file from the disk
* and regenerate it.
* @author Matrax
* @version 1.0
*/
void File::regenerate()
{
    this->remove();
    this->generate();
}

/**
* This method remove the file from the disk.
* @author Matrax
* @version 1.0
*/
void File::remove()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }

    std::filesystem::remove(this->m_path.c_str());
}

/**
* This method save the file on the disk.
* @author Matrax
* @version 1.0
*/
void File::save()
{
    this->m_file.open(this->m_path, std::fstream::out | std::fstream::app);

    if(this->m_file.is_open() == false)
        throw std::runtime_error("Can't save the file");
    
    this->m_file << this->m_content << std::endl;
    this->m_file.flush();
    this->m_file.close();
}

/**
* This method clear the file if the content is not empty.
* @author Matrax
* @version 1.0
*/
void File::clear()
{
    if(this->m_content.empty() == false)
    {
        this->m_content = "";
    }
}

/**
* This method append a text content in the file if the text is not empty.
* @param const std::string content The text content to append.
* @author Matrax
* @version 1.0
*/
void File::addContent(const std::string content)
{
    if(content.empty() == false)
    {
        this->m_content.append(content);
    }
}

/**
* This method read the file from the disk.
* @return std::string The content of the file from the disk.
* @author Matrax
* @version 1.0
*/
std::string File::read()
{
    unsigned int length = std::filesystem::file_size(this->m_path);
    std::string result(length, '\0');
    this->m_file.seekg(0, this->m_file.beg);
    this->m_file.read(result.data(), length);
    return result;
}

/**
* This method return the path of the file.
* @return const std::string The path of the file.
* @author Matrax
* @version 1.0
*/
const std::string File::getPath() const
{
    return this->m_path;
}

/**
* This method return the content of the file from the RAM.
* @return std::string The content of the file from the RAM.
* @author Matrax
* @version 1.0
*/
std::string File::getContent() const
{
    return this->m_content;
}