#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", false, 72, 45){
    std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm (target, false, 72, 45) {
    std::cout << "RobotomyRequestForm " << this->name << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy){
    std::cout << "RobotomyRequestForm" << this->name << " constructor called." << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
    std::cout << "RobotomyRequestForm copy asignment operator called." << std::endl;
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm " << this->name << " destructor called." << std::endl;
}
