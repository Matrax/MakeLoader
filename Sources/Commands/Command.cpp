#include "../../Headers/Commands/Command.hpp"

Command::Command(const std::string name, const std::string description) : m_name(name),
                                                                          m_description(description)
{
  if(m_name.empty())
      throw std::runtime_error("Can't instantiate a command without name");

  if(m_description.empty())
      throw std::runtime_error("Can't instantiate a command without description");
}

Command::~Command() {}

const std::string & Command::getName() const
{
  return this->m_name;
}

const std::string & Command::getDescription() const
{
  return this->m_description;
}
