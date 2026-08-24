#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm{

    public:
    //Default Constructor and Destructor, Canonical AForm
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();
        
        virtual void execute(const Bureaucrat &executor) const;
};


