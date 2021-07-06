#include "../../Headers/Files/File.hpp"

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

File::~File()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }
}

void File::createDirectory(const std::string name)
{
	if(File::exist(name) == false)
	{
		std::filesystem::create_directory(name);
		std::cout << "[MakeLoader] The directory " << name << " is now created." << std::endl;
	} else { 
		std::cout << "[MakeLoader] The directory " << name << " already exist !" << std::endl;
	}
}

bool File::exist(const std::string path)
{
    return std::filesystem::exists(path);
}

void File::remove()
{
    if(this->m_file.is_open() == true)
    {
        this->m_file.flush();
        this->m_file.close();
    }
    std::remove(this->m_path.c_str());
}

void File::save()
{
    this->m_file.open(this->m_path, std::fstream::out | std::fstream::app);
    if(this->m_file.is_open() == true)
    {
        this->m_file << this->m_content << std::endl;
        this->m_file.flush();
        this->m_file.close();
    } else {
        std::cout << "[MakeLoader] Can't save the file " << this->m_path << std::endl;
    }
}

void File::clear()
{
    if(this->m_content != "")
    {
        this->m_content = "";
    }
}

void File::addContent(const std::string content)
{
    if(content != "")
    {
        this->m_content.append(content);
    }
}

std::string File::read()
{
    this->m_file.seekg (0, this->m_file.end);
    unsigned int length = this->m_file.tellg();
    char * buffer = new char[length];
    this->m_file.seekg (0, this->m_file.beg);
    this->m_file.read(buffer, length);
    std::string data(buffer);
    delete[] buffer;
    return data;
}

const std::string File::getPath() const
{
    return this->m_path;
}

std::string File::getContent() const
{
    return this->m_content;
}