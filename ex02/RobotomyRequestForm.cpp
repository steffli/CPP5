#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : name("Default"), grade(150){
    std::cout << "Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int grade) : name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "RobotomyRequestForm " << this->name << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : name(copy.name), grade(copy.grade){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
    std::cout << "RobotomyRequestForm copy asignment operator called." << std::endl;
    if(this != &copy){
        this->grade = copy.grade;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm " << this->name << " destructor called." << std::endl;
}