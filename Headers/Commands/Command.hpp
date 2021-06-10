#pragma once

#include <string>

class Command
{
    private:

        //Attributes
        const std::string m_name;
        const std::string m_description;

    public:

        //Constructors and destructor
        Command() = delete;
        Command(const std::string name, const std::string description);
        virtual ~Command();

        //Virtual methods
        virtual void execute() = 0;

        //Methods
        const std::string & getName() const;
        const std::string & getDescription() const;
};