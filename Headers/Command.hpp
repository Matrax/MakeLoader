#pragma once

#include <string>

class Command
{
    private:

        const std::string m_name;
        const std::string m_description;

    public:

        Command() = delete;
        Command(const std::string name, const std::string description);
        virtual ~Command();

        virtual void execute() = 0;

        const std::string & getName() const;
        const std::string & getDescription() const;
};