#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : name("Default"), grade(150){
    std::cout << "Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, int grade) : name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "ShrubberyCreationForm " << this->name << " constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : name(copy.name), grade(copy.grade){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
    std::cout << "ShrubberyCreationForm copy asignment operator called." << std::endl;
    if(this != &copy){
        this->grade = copy.grade;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm " << this->name << " destructor called." << std::endl;
}