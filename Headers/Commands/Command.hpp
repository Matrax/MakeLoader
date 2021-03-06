#pragma once

//Std includes
#include <string>
#include <stdexcept>

/**
 * This abstract class represent a command in the application.
 * Every child of this class must reimplement the execute pure virtual method.
 * Every command must have a name and a description.
 * @brief This class is an abstract class that represent a command for the application.
 * @author Matrax
 * @version 1.0
 */
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
        Command(const Command &) = delete;
        virtual ~Command();

        //Operators
        Command & operator=(const Command &) = delete;

        //Virtual methods
        virtual void execute() = 0;

        //Methods
        const std::string & getName() const;
        const std::string & getDescription() const;
};