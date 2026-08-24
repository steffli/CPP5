#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
    //Default Constructor and Destructor, Canonical AForm
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm();
        
        virtual void execute(const Bureaucrat &executor) const;

};


