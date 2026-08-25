#pragma once


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Intern{
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();

        AForm* makeForm(const std::string& form, const std::string& target) const;
};


