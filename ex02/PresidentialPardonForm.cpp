#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : name("Default"), grade(150){
    std::cout << "Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, int grade) : name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "PresidentialPardonForm " << this->name << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : name(copy.name), grade(copy.grade){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
    std::cout << "PresidentialPardonForm copy asignment operator called." << std::endl;
    if(this != &copy){
        this->grade = copy.grade;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm " << this->name << " destructor called." << std::endl;
}   