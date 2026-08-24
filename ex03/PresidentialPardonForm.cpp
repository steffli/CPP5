#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", false, 25, 5){
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, false, 25, 5){
    std::cout << "PresidentialPardonForm " << this->getName() << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){
    std::cout << "PresidentialPardonForm " << this->getName() << " copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
    std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm " << this->getName() << " destructor called." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
    if (!this->is_Signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->grade_exec)
        throw AForm::GradeTooLowException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
