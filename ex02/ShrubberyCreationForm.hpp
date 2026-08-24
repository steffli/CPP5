#pragma once

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm{
    public:
    //Default Constructor and Destructor, Canonical AForm
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();

        virtual void execute(const Bureaucrat &executor) const;
};


