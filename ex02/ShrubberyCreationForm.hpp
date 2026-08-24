#pragma once

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm{
    public:
    //Default Constructor and Destructor, Canonical AForm
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();
        
        //public member functions
        const std::string& getName() const;
        int getGrade() const;
};