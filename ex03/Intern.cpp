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
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int type = (names[0] == form) * 1
             + (names[1] == form) * 2
             + (names[2] == form) * 3;

    switch (type){
        case 1:
            std::cout << "Intern creates " << form << std::endl;
            return new ShrubberyCreationForm(target);
        case 2:
            std::cout << "Intern creates " << form << std::endl;
            return new RobotomyRequestForm(target);
        case 3:
            std::cout << "Intern creates " << form << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern failed to create " << form << ": unknown form type" << std::endl;
            return NULL;
    }
}
