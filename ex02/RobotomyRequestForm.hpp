#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{

    public:
    //Default Constructor and Destructor, Canonical AForm
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm();
        
        //public member functions
        const std::string& getName() const;
        int getGrade() const;
};