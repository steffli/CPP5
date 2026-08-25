#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern&){
    std::cout << "Intern copy constructor called." << std::endl;
}

Intern& Intern::operator=(const Intern&){
    std::cout << "Intern copy assignment operator called." << std::endl;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const{
    if (form == "shrubbery creation"){
        std::cout << "Intern creates " << form << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (form == "robotomy request"){
        std::cout << "Intern creates " << form << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (form == "presidential pardon"){
        std::cout << "Intern creates " << form << std::endl;
        return new PresidentialPardonForm(target);
    }
    std::cout << "Intern failed to create " << form << ": unknown form type" << std::endl;
    return NULL;
}
